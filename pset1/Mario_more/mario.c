#include <cs50.h>
#include <stdio.h>

void print(char c, int n); // Decalres the function used in line 24

int main(void)
{
    int n; // Declares the variable n as an integer
    do // Initialises a do-while loop until user reponds within the specified rules below
    {
        n = get_int("Height: "); // Promts the user for input using integer
    } while (n < 1 || n > 8); // Keeps prompting the user for input if the value inputted is less than 1 or bigger than 8

    for (int i = 0; i < n; i++) //
    {
        print(' ', n - 1 - i); //
        print('#', i + 1); //
        print(' ', 2); //
        print('#', i + 1); //

        printf("\n");
    }
}
void print(char c, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", c);
    }
}