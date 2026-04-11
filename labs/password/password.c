// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library
 
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool has_upper = false;
    bool has_lower = false;
    bool has_digit = false;
    bool has_special = false;

    int len = strlen(password);
    for (int i = 0; i < len; i++)
    {
        if (isupper(password[i]))
        {
            has_upper = true;
        }
    }

    for (int k = 0; k < len; k++)
    {
        if (islower(password[k]))
        {
            has_lower = true;
        }
    }

    for (int j = 0; j < len; j++)
    {
        if (isdigit(password[j]))
        {
            has_digit = true;
        }
    }

    for (int l = 0; l < len; l++)
    {
        if (isalpha(password[l]) == 0 && isdigit(password[l]) == 0)
        {
            has_special = true;
        }
    }

    if (has_upper && has_lower && has_digit && has_special)
    {
        return true;
    }
    else
    {
        return false;
    }
}
