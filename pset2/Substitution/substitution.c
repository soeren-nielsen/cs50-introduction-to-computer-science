#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (!is_valid_key(argv[1]))
    {
        printf("Key must contain 26 characters.\n")
        return 1;
    }

    string s = get_string("Plaintext: ");

}

bool is_valid_key(string s)
{
    int len = strlen(s);
    if (len != 26)
        return false;

    for (int i = 0; i < len; i++)
        if (!isalpha(s[i]))
            return false;
}