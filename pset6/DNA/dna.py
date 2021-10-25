# Imports argv from sys module to get access to command-line arguments
from sys import argv

# Import get_string from cs50 module
from cs50 import get_string

if len(argv) != 3: # Checks if length of command-line argument is not equal to 3 ie. validate user input
    print('An error occured. You need to have 3 command-line arguments') # If command-line argument is not equal to 3, print error message
    exit(1) # exit(1) stops the program from running

csv_file = open(argv[1], 'r') # Read CSV file based on argument passed in 1st position in command-line argument

strands = [] # Create an empty strands array
persons = {} # Create an empty persons dictionary

for index, row in enumerate(csv_file): # The for loop will get the variable 'index' as the index of the line and the variable 'row' is the data on that line. I Use enumarate() to ...
    if index == 0: # If index equals 0, meaning the first row then ...
        strands = [strand for strand in row.strip().split(',')][1:] # I get all the strands from the database, however these are stored in CSV format, so first I use strip() to remove any whitespace in the rows, then I use split() to divide the different strands into the array. I don't want 'name', so I go from index 1 onwards ([1:])
    else: # If index does not equal 0, meaning the first row then ...
        current_row = row.strip().split(',') # I strip() and split() the row and sets the content equal to the varaiable current_row
        persons[current_row[0]] = [int(x) for x in current_row[1:]] # Then I fill my persons dictionary with the content from the variable current_row, persons[current_row[0]] will give me the name and I set that equal to current_row[1:] meaning that is from current_row index 1 and onwards. Last I convert x to an int because I can't apply integer operations like max() and min() on strings which I will need to do later.

sequence = open(argv[2], 'r').read() # Read TXT file containg sequences based on argument passed in 2nd position in command-line argument

results = [] # Create a results array

for strand in strands: # Iterate over all the strands
    i = 0 # Set i to 0
    max_strand = -1 # Set max_strand to -1
    current_max = 0 # Set current_max to 0
    while i < len(sequence): # I want to iterate as long as i is less than the length of sequence.
        current_window = sequence[i:i+len(strand)] # I set current_window equal to the current index of sequence plus the length of the strand that I'm checking
        if current_window == strand: # If current_window is equal to the strand that I'm checking then ...
            current_max += 1 # Increment current_max variable with 1
            max_strand = max(max_strand, current_max) # Update max_strand so that it is equal to the max strand that I have seen so far. For this I use max() where i take the current max_strand and current_max, find the biggest one and set that as max_strand
            i += len(strand) # Increment i with the length of the strand, I do this so I can ''move'' the window over to the next strand and therefore I don't have to only move one forward each time.
        else: # When my current_window is no longer equal to strand, then ..
            current_max = 0 # I reset the variable current_max to 0
            i += 1 # If the current strand that i'm chekcking is not equal to strand that i'm checking, then increment i with 1
    results.append(max_strand) # I then append the results to a list via append and I save it in the results array.

for name,data in persons.items(): # Then I iterate through the persons dictionary with the .items method which will return the the data as key-value pairs, which I will use to check if there are any matches with.
    if data == results: # If data is equal to results then ...
        print(name) # Print the name of the person which has a STR count matching the sequence specified
        exit(0) # exit(0) exits the program succesfully, if no match is found between data and results then ...
print('No match') # Print 'No match'