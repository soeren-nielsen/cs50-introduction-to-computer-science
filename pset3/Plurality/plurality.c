#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++) // Initiating a loop to count from 0 to the total number af candidates
    {
        if (strcmp(candidates[i].name, name) == 0) // Uses the strcmp function to compare whether first string is the same the second string and if it is the same it returns 0 (true)
        {
            candidates[i].votes++; // If it returns 0 (true), increment votes by 1
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int maxvotes = 0; // Declares the variable maxvotes as an integer and sets the value to 0
    // Find highest number of votes
    for (int i = 0; i < candidate_count; i++) // Iterate over the list of candidates and check the number of votes
    {
        if (candidates[i].votes > maxvotes) // Check if the current candidates number of votes is greater than the maxvote
        {
            maxvotes = candidates[i].votes; // If it is update maxvote to that value. This loop continues until all of the candidates have been checked
        }
    }
    // Print winner(s)
    for (int i = 0; i < candidate_count; i++) // Iterate over the list of candidates and check their number of votes against the value of the maxvote variable
    {
        if (candidates[i].votes == maxvotes) // Check if the number of votes equals the value of the maxvote variable
        {
            printf("%s\n", candidates[i].name); // If it does then print winner(s)
        }
    }

    return;
}