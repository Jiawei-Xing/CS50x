#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //get height from user
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    //print out pyramid
    for (int row = 0; row < height; row++)
    {
        //print spaces
        for (int space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }

        //print hashes
        for (int hash = 0; hash < row + 1; hash++)
        {
            printf("#");
        }

        //print gaps
        printf("  ");
        
        //print hashes2
        for (int hash2 = 0; hash2 < row + 1; hash2++)
        {
            printf("#");
        }
        
        printf("\n");
    }
}