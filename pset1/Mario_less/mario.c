#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n; // Declares the variable n as an integer
    do // Initialises a do-while loop until user reponds within the specified rules below
    {
        n = get_int("Height: "); // Promts the user for input
    }
    while (n < 1 || n > 8); // Keeps prompting the user for input if the value inputted is less than 1 or higher than 8

    for (int i = 0; i < n; i++) // Initialises a for loop, which sets the variable i to 0, then checks if n is greater than i and then adds 1 to the variable j
    {
        for (int j = n - 1; j > i; j--) // Initialises a for loop, whick set the variable j to n minus 1, then checks
        printf(" "); // Print blank spaces

        for (int j = 0; j <= i; j++) // Initialises a for loop
        printf("#"); // Print number sign

        printf("\n");
    }
}