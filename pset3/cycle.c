#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int winner;
    int loser;
}
pair;

pair pairs[4];
bool cycle(int i, int j);
bool locked[4][4];
bool track[4][4];
int k;
int from[4] = {0, 0, 0, 0};

int main(void)
{
    pairs[0].winner = 0;
    pairs[0].loser = 1;
    pairs[1].winner = 1;
    pairs[1].loser = 2;
    pairs[2].winner = 1;
    pairs[2].loser = 3;
    pairs[3].winner = 2;
    pairs[3].loser = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            locked[i][j] = false;
        }
    }

    for (k = 0; k < 4; k++)
    {
        // track walked paths
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                track[i][j] = false;
            }
        }

        if (!cycle(pairs[k].loser, pairs[k].winner))
        {
            locked[pairs[k].winner][pairs[k].loser] = true;
            printf("%i,%i\n", pairs[k].winner, pairs[k].loser);
        }
    }
}

bool cycle(int i, int j)
{
    for (int n = 0; n < 4; n++)
    {
        if (locked[i][n] == true && track[i][n] == false)
        {
            track[i][n] = true;
            from[n] = i;
            if (n == j)
            {
                return true;
            }
            else
            {
                return cycle(n, j);
            }
        }
    }
    if (i == pairs[k].loser)
    {
        return false;
    }
    else
    {
        return cycle(from[i], j);
    }
}
