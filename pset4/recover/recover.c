#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <iso646.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Use: recover.c card.raw\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        fclose(card);
        printf("Non-valid file\n");
        return 1;
    }

    BYTE *buffer = malloc(512);
    int i = 0;
    char *filename = malloc(7 * sizeof(char));
    sprintf(filename, "%03i.jpg", i);
    FILE *image = fopen(filename, "a");

    while (fread(buffer, sizeof(BYTE), 512, card))
    {
        if ((int)buffer[0] == 0xff && (int)buffer[1] == 0xd8 && (int)buffer[2] == 0xff && ((int)buffer[3] & 0xf0) == 0xe0)
        {
            if (i == 0)
            {
                i++;
                fwrite(buffer, sizeof(BYTE), 512, image);
            }
            else
            {
                fclose(image);
                sprintf(filename, "%03i.jpg", i);
                i++;
                image = fopen(filename, "a");
                fwrite(buffer, sizeof(BYTE), 512, image);
            }

        }
        else
        {
            if (i != 0)
            {
                fwrite(buffer, sizeof(BYTE), 512, image);
            }
        }
    }
    fclose(image);
    fclose(card);
    free(buffer);
    free(filename);
}