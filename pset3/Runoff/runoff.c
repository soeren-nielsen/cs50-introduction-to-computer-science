#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++) // Iterate through list of candidates as long as i is less than candidates_count
    {
        if (strcmp(candidates[i].name, name) == 0) // Go through the candidates array checking only if the name matches the name which is passed in. This is done by using strcmp which compares two strings character by character
        {
            preferences[voter][rank] = i; // If the if statement turns out to be true, it means that the candidate is a ''real'' candidate and then I update the preferences in regards to [voter] and [rank] for that candidate
            return true; // And then return true
        }
    }
    return false; // If the if statement does not turn out to be true then I return false
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++) // Iterate over the voters (the ballot). This is the outer for loop which i use to go over the first dimension of the array
    {
        for (int j = 0; j < candidate_count; j++) // Iterate over rank (the person) in candidates_count as long as it's not higher than candidate_count. This is the inner for loop which i use to go over the second dimension of the array
        {
            // Inside two-dimensional array
            int candidate_index = preferences[i][j]; // First i iterate over the preferences array checking where the information is, then match that with candidates (struct) in order to find out what is where. Kind of like using JOIN in SQL. This is because preferences don't know what a candidate is. I need to do this in order to check if the candidate is already eliminated
            if (candidates[candidate_index].eliminated == false) // If the candidate is already eliminated, I don't count their votes
            {
                candidates[candidate_index].votes++; // If the candidate is not eliminated I increment that candidates number of votes by 1
                break; // Use break to end the inner for loop because it finished the first ballot and now I need to go back to the outer for loop to iterate over the next ballot
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    float majority = (float)voter_count/2; // Declare the variable 'majority' as voter_count divided by 2. This is because if one candidate has the majority of votes they win. Because I am doing division i cast the variable voter_count to a float because I could end up with a number which is not an integer, which it has been decalred as earlier
    for (int i = 0; i < candidate_count; i++) // Iterate over candidates
    {
        if ((float)candidates[i].votes > majority) // If a candidate has more votes than the majority of votes, we print their name and return true. Because majority is a float as specifed before we need to cast candidates.votes as a float as well because its declared as an integer
        {
            printf("%s\n", candidates[i].name); // Print the candidates name
            return true; // And return true
        }
    }
    return false; // Else return false if there are no candidates who have the majority of votes
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int minimum_vote = MAX_VOTERS; // Set the variable minVote to the global variable defined as MAX_VOTER (which is 100)
    for (int i = 0; i < candidate_count; i++) // Iterate over candidates again
    {
        if (candidates[i].eliminated == false && candidates[i].votes < minimum_vote) // If candidates are not eliminated and the number of votes the candidate recieved are less than the minimum number of votes then we count them. If the candidate are eliminated there is no reason to count their votes.
        {
            minimum_vote = candidates[i].votes; // If this is the case we assign the minimum_votes to the specific candidates votes
        }
    }
    return minimum_vote; // Return minimum_vote
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++) // Iterate over candidates again
    {
        if (candidates[i].eliminated == false && candidates[i].votes != min) // If the candidates are eliminated we don't want to count them and if the candidates votes does not equal the min (the minimum amount of votes) return false. The reason we want to know if the candidates does not have the minimum amount of votes is because then it's not a tie
        {
            return false; // Then return false
        }
    }
    return true; // Else return true
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++) // Iterate over candidates again
    {
        if (candidates[i].votes == min) // If candidates votes equals the min (the minimum amount of votes)
        {
            candidates[i].eliminated = true; // Then set that candidate to eliminated true.
        }
    }
    return;
}
