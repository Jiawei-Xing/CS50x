#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int check_letter(string key);
string encipher(string key, string plaintext);

int main(int argc, string argv[])
{
    //not one key
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //not 26 letters or not letters or more than once
    else if (strlen(argv[1]) != 26 || check_letter(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    //correct key
    else
    {
        string plaintext = get_string("plaintext: ");
        string ciphertext = encipher(argv[1], plaintext);
        printf("ciphertext: %s\n", ciphertext);
        return 0;
    }
}

int check_letter(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        //not letter
        if (islower(key[i]) == 0 && isupper(key[i]) == 0)
        {
            return true;
        }
        //more than once
        else
        {
            for (int j = 0; j < i; j++)
            {
                if (tolower(key[j]) == tolower(key[i]))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

string encipher(string key, string plaintext)
{
    string ciphertext = plaintext;
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if islower(plaintext[i])
        {
            ciphertext[i] = tolower(key[plaintext[i] - 97]);
        }
        else if isupper(plaintext[i])
        {
            ciphertext[i] = toupper(key[plaintext[i] - 65]);
        }
    }
    return ciphertext;
}