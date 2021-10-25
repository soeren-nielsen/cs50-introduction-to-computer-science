#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars; // Declares the variable dollar as a float
    do // Initialises a do-while loop until user reponds within the specified rules below
    {
        dollars = get_float("Change owed: "); // Promts the user for input using float in case there are decimal points at the same time it ensures that only positive numbers are used as input
    } while (dollars < 0);  // Keeps prompting the user for input if the value inputted is less than 0 i.e. a negative number

    int cents = round(dollars * 100); // Declares the variable cents as an integer while rounding the decimals to the nearest penny. The round function is specified in <math.h>.
    int coins = 0; // Declares the variable coins as an integer while setting it to 0

    int denominations[] = {25, 10, 5, 1}; // Uses an array to declares the different denominations used i.e 25 cent, 10 cent, 5 cent, 1 cent
    int size = sizeof(denominations)/sizeof(int); //Taking the size of the array and dividing it with the size of the integer. Set the value to the variable size. Makes it easier to add or remove denominations without having to rewrite the code
    for (int i = 0; i < size; i++) //Initialises a for loop that set the variable i to 0, checks if the variable size is greater than i and then adds 1 to the variable i if that is the case
    {
        coins += cents / denominations[i];
        cents %= denominations[i];
    }
    printf("%i\n", coins); // Prints how many coins it would take to pay back the customer using the smallest amount possible
}