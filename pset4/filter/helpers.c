#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int n = (int)round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = n;
            image[i][j].rgbtGreen = n;
            image[i][j].rgbtRed = n;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][width - j - 1].rgbtBlue = temp;
            temp = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][width - j - 1].rgbtGreen = temp;
            temp = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][width - j - 1].rgbtRed = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];

    //four corners
    new_image[0][0].rgbtBlue = (int)round((image[0][0].rgbtBlue + image[0][1].rgbtBlue + image[1][0].rgbtBlue + image[1][1].rgbtBlue) / 4.0);
    new_image[0][0].rgbtGreen = (int)round((image[0][0].rgbtGreen + image[0][1].rgbtGreen + image[1][0].rgbtGreen + image[1][1].rgbtGreen) / 4.0);
    new_image[0][0].rgbtRed = (int)round((image[0][0].rgbtRed + image[0][1].rgbtRed + image[1][0].rgbtRed + image[1][1].rgbtRed) / 4.0);

    new_image[0][width - 1].rgbtBlue = (int)round((image[0][width - 2].rgbtBlue + image[0][width - 1].rgbtBlue + image[1][width - 2].rgbtBlue + image[1][width - 1].rgbtBlue) / 4.0);
    new_image[0][width - 1].rgbtGreen = (int)round((image[0][width - 2].rgbtGreen + image[0][width - 1].rgbtGreen + image[1][width - 2].rgbtGreen + image[1][width - 1].rgbtGreen) / 4.0);
    new_image[0][width - 1].rgbtRed = (int)round((image[0][width - 2].rgbtRed + image[0][width - 1].rgbtRed + image[1][width - 2].rgbtRed + image[1][width - 1].rgbtRed) / 4.0);

    new_image[height - 1][0].rgbtBlue = (int)round((image[height - 2][0].rgbtBlue + image[height - 2][1].rgbtBlue + image[height - 1][0].rgbtBlue + image[height - 1][1].rgbtBlue) / 4.0);
    new_image[height - 1][0].rgbtGreen = (int)round((image[height - 2][0].rgbtGreen + image[height - 2][1].rgbtGreen + image[height - 1][0].rgbtGreen + image[height - 1][1].rgbtGreen) / 4.0);
    new_image[height - 1][0].rgbtRed = (int)round((image[height - 2][0].rgbtRed + image[height - 2][1].rgbtRed + image[height - 1][0].rgbtRed + image[height - 1][1].rgbtRed) / 4.0);

    new_image[height - 1][width - 1].rgbtBlue = (int)round((image[height - 2][width - 2].rgbtBlue + image[height - 2][width - 1].rgbtBlue + image[height - 1][width - 2].rgbtBlue + image[height - 1][width - 1].rgbtBlue) / 4.0);
    new_image[height - 1][width - 1].rgbtGreen = (int)round((image[height - 2][width - 2].rgbtGreen + image[height - 2][width - 1].rgbtGreen + image[height - 1][width - 2].rgbtGreen + image[height - 1][width - 1].rgbtGreen) / 4.0);
    new_image[height - 1][width - 1].rgbtRed = (int)round((image[height - 2][width - 2].rgbtRed + image[height - 2][width - 1].rgbtRed + image[height - 1][width - 2].rgbtRed + image[height - 1][width - 1].rgbtRed) / 4.0);

    //four edges
    for (int n = 1; n < width - 1; n++)
    {
        int sum_blue = 0;
        int sum_green = 0;
        int sum_red = 0;
        for (int i = 0; i <= 1; i++)
        {
            for (int j = n - 1; j <= n + 1; j++)
            {
                sum_blue += image[i][j].rgbtBlue;
                sum_green += image[i][j].rgbtGreen;
                sum_red += image[i][j].rgbtRed;
            }
        }
        new_image[0][n].rgbtBlue = (int)round(sum_blue / 6.0);
        new_image[0][n].rgbtGreen = (int)round(sum_green / 6.0);
        new_image[0][n].rgbtRed = (int)round(sum_red / 6.0);
    }

    for (int n = 1; n < width - 1; n++)
    {
        int sum_blue = 0;
        int sum_green = 0;
        int sum_red = 0;
        for (int i = height - 2; i <= height - 1; i++)
        {
            for (int j = n - 1; j <= n + 1; j++)
            {
                sum_blue += image[i][j].rgbtBlue;
                sum_green += image[i][j].rgbtGreen;
                sum_red += image[i][j].rgbtRed;
            }
        }
        new_image[height - 1][n].rgbtBlue = (int)round(sum_blue / 6.0);
        new_image[height - 1][n].rgbtGreen = (int)round(sum_green / 6.0);
        new_image[height - 1][n].rgbtRed = (int)round(sum_red / 6.0);
    }

    for (int n = 1; n < height - 1; n++)
    {
        int sum_blue = 0;
        int sum_green = 0;
        int sum_red = 0;
        for (int i = n - 1; i <= n + 1; i++)
        {
            for (int j = 0; j <= 1; j++)
            {
                sum_blue += image[i][j].rgbtBlue;
                sum_green += image[i][j].rgbtGreen;
                sum_red += image[i][j].rgbtRed;
            }
        }
        new_image[n][0].rgbtBlue = (int)round(sum_blue / 6.0);
        new_image[n][0].rgbtGreen = (int)round(sum_green / 6.0);
        new_image[n][0].rgbtRed = (int)round(sum_red / 6.0);
    }

    for (int n = 1; n < height - 1; n++)
    {
        int sum_blue = 0;
        int sum_green = 0;
        int sum_red = 0;
        for (int i = n - 1; i <= n + 1; i++)
        {
            for (int j = width - 2; j <= width - 1; j++)
            {
                sum_blue += image[i][j].rgbtBlue;
                sum_green += image[i][j].rgbtGreen;
                sum_red += image[i][j].rgbtRed;
            }
        }
        new_image[n][width - 1].rgbtBlue = (int)round(sum_blue / 6.0);
        new_image[n][width - 1].rgbtGreen = (int)round(sum_green / 6.0);
        new_image[n][width - 1].rgbtRed = (int)round(sum_red / 6.0);
    }

    //the rest in the middle
    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            int sum_blue = 0;
            int sum_green = 0;
            int sum_red = 0;
            for (int a = i - 1; a <= i + 1; a++)
            {
                for (int b = j - 1; b <= j + 1; b++)
                {
                    sum_blue += image[a][b].rgbtBlue;
                    sum_green += image[a][b].rgbtGreen;
                    sum_red += image[a][b].rgbtRed;
                }
            }
            new_image[i][j].rgbtBlue = (int)round(sum_blue / 9.0);
            new_image[i][j].rgbtGreen = (int)round(sum_green / 9.0);
            new_image[i][j].rgbtRed = (int)round(sum_red / 9.0);
        }
    }

    //move new_image to image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = new_image[i][j].rgbtBlue;
            image[i][j].rgbtGreen = new_image[i][j].rgbtGreen;
            image[i][j].rgbtRed = new_image[i][j].rgbtRed;
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //store pre-RGB in new image (could >256)
    typedef struct
    {
        WORD  rgbtBlue;
        WORD  rgbtGreen;
        WORD  rgbtRed;
    } __attribute__((__packed__))
    NEW_RGBTRIPLE;

    NEW_RGBTRIPLE new_image[height][width];

    //four corners
    new_image[0][0].rgbtBlue = (int)round(sqrt(pow(image[0][1].rgbtBlue * 2 + image[1][1].rgbtBlue, 2.0) + pow(image[1][0].rgbtBlue * 2 + image[1][1].rgbtBlue, 2.0)));
    new_image[0][0].rgbtGreen = (int)round(sqrt(pow(image[0][1].rgbtGreen * 2 + image[1][1].rgbtGreen, 2.0) + pow(image[1][0].rgbtGreen * 2 + image[1][1].rgbtGreen, 2.0)));
    new_image[0][0].rgbtRed = (int)round(sqrt(pow(image[0][1].rgbtRed * 2 + image[1][1].rgbtRed, 2.0) + pow(image[1][0].rgbtRed * 2 + image[1][1].rgbtRed, 2.0)));

    new_image[0][width - 1].rgbtBlue = (int)round(sqrt(pow(image[0][width - 2].rgbtBlue * (-2) + image[1][width - 2].rgbtBlue * (-1), 2.0) + pow(image[1][width - 2].rgbtBlue + image[1][width - 1].rgbtBlue * 2, 2.0)));
    new_image[0][width - 1].rgbtGreen = (int)round(sqrt(pow(image[0][width - 2].rgbtGreen * (-2) + image[1][width - 2].rgbtGreen * (-1), 2.0) + pow(image[1][width - 2].rgbtGreen + image[1][width - 1].rgbtGreen * 2, 2.0)));
    new_image[0][width - 1].rgbtRed = (int)round(sqrt(pow(image[0][width - 2].rgbtRed * (-2) + image[1][width - 2].rgbtRed * (-1), 2.0) + pow(image[1][width - 2].rgbtRed + image[1][width - 1].rgbtRed * 2, 2.0)));

    new_image[height - 1][0].rgbtBlue = (int)round(sqrt(pow(image[height - 2][1].rgbtBlue + image[height - 1][1].rgbtBlue * 2, 2.0) + pow(image[height - 2][0].rgbtBlue * (-2) + image[height - 2][1].rgbtBlue * (-1), 2.0)));
    new_image[height - 1][0].rgbtGreen = (int)round(sqrt(pow(image[height - 2][1].rgbtGreen + image[height - 1][1].rgbtGreen * 2, 2.0) + pow(image[height - 2][0].rgbtGreen * (-2) + image[height - 2][1].rgbtGreen * (-1), 2.0)));
    new_image[height - 1][0].rgbtRed = (int)round(sqrt(pow(image[height - 2][1].rgbtRed + image[height - 1][1].rgbtRed * 2, 2.0) + pow(image[height - 2][0].rgbtRed * (-2) + image[height - 2][1].rgbtRed * (-1), 2.0)));

    new_image[height - 1][width - 1].rgbtBlue = (int)round(sqrt(pow(image[height - 2][width - 2].rgbtBlue * (-1) + image[height - 1][width - 2].rgbtBlue * (-2), 2.0) + pow(image[height - 2][width - 2].rgbtBlue * (-1) + image[height - 2][width - 1].rgbtBlue * (-2), 2.0)));
    new_image[height - 1][width - 1].rgbtGreen = (int)round(sqrt(pow(image[height - 2][width - 2].rgbtGreen * (-1) + image[height - 1][width - 2].rgbtGreen * (-2), 2.0) + pow(image[height - 2][width - 2].rgbtGreen * (-1) + image[height - 2][width - 1].rgbtGreen * (-2), 2.0)));
    new_image[height - 1][width - 1].rgbtRed = (int)round(sqrt(pow(image[height - 2][width - 2].rgbtRed * (-1) + image[height - 1][width - 2].rgbtRed * (-2), 2.0) + pow(image[height - 2][width - 2].rgbtRed * (-1) + image[height - 2][width - 1].rgbtRed * (-2), 2.0)));

    //four edges
    for (int n = 1; n < width - 1; n++)
    {
        new_image[0][n].rgbtBlue = (int)round(sqrt(pow(image[0][n - 1].rgbtBlue * (-2) + image[0][n + 1].rgbtBlue * 2 + image[1][n - 1].rgbtBlue * (-1) + image[1][n + 1].rgbtBlue, 2.0) + pow(image[1][n - 1].rgbtBlue + image[1][n].rgbtBlue * 2 + image[1][n + 1].rgbtBlue, 2.0)));
        new_image[0][n].rgbtGreen = (int)round(sqrt(pow(image[0][n - 1].rgbtGreen * (-2) + image[0][n + 1].rgbtGreen * 2 + image[1][n - 1].rgbtGreen * (-1) + image[1][n + 1].rgbtGreen, 2.0) + pow(image[1][n - 1].rgbtGreen + image[1][n].rgbtGreen * 2 + image[1][n + 1].rgbtGreen, 2.0)));
        new_image[0][n].rgbtRed = (int)round(sqrt(pow(image[0][n - 1].rgbtRed * (-2) + image[0][n + 1].rgbtRed * 2 + image[1][n - 1].rgbtRed * (-1) + image[1][n + 1].rgbtRed, 2.0) + pow(image[1][n - 1].rgbtRed + image[1][n].rgbtRed * 2 + image[1][n + 1].rgbtRed, 2.0)));
    }

    for (int n = 1; n < width - 1; n++)
    {
        new_image[height - 1][n].rgbtBlue = (int)round(sqrt(pow(image[height - 1][n - 1].rgbtBlue * (-2) + image[height - 1][n + 1].rgbtBlue * 2 + image[height - 2][n - 1].rgbtBlue * (-1) + image[height - 2][n + 1].rgbtBlue, 2.0) + pow(image[height - 2][n - 1].rgbtBlue * (-1) + image[height - 2][n].rgbtBlue * (-2) + image[height - 2][n + 1].rgbtBlue * (-1), 2.0)));
        new_image[height - 1][n].rgbtGreen = (int)round(sqrt(pow(image[height - 1][n - 1].rgbtGreen * (-2) + image[height - 1][n + 1].rgbtGreen * 2 + image[height - 2][n - 1].rgbtGreen * (-1) + image[height - 2][n + 1].rgbtGreen, 2.0) + pow(image[height - 2][n - 1].rgbtGreen * (-1) + image[height - 2][n].rgbtGreen * (-2) + image[height - 2][n + 1].rgbtGreen * (-1), 2.0)));
        new_image[height - 1][n].rgbtRed = (int)round(sqrt(pow(image[height - 1][n - 1].rgbtRed * (-2) + image[height - 1][n + 1].rgbtRed * 2 + image[height - 2][n - 1].rgbtRed * (-1) + image[height - 2][n + 1].rgbtRed, 2.0) + pow(image[height - 2][n - 1].rgbtRed * (-1) + image[height - 2][n].rgbtRed * (-2) + image[height - 2][n + 1].rgbtRed * (-1), 2.0)));
    }

    for (int n = 1; n < height - 1; n++)
    {
        new_image[n][width - 1].rgbtBlue = (int)round(sqrt(pow(image[n - 1][width - 2].rgbtBlue * (-1) + image[n][width - 2].rgbtBlue * (-2) + image[n + 1][width - 2].rgbtBlue * (-1), 2.0) + pow(image[n - 1][width - 2].rgbtBlue * (-1) + image[n - 1][width - 1].rgbtBlue * (-2) + image[n + 1][width - 2].rgbtBlue + image[n + 1][width - 1].rgbtBlue * 2, 2.0)));
        new_image[n][width - 1].rgbtGreen = (int)round(sqrt(pow(image[n - 1][width - 2].rgbtGreen * (-1) + image[n][width - 2].rgbtGreen * (-2) + image[n + 1][width - 2].rgbtGreen * (-1), 2.0) + pow(image[n - 1][width - 2].rgbtGreen * (-1) + image[n - 1][width - 1].rgbtGreen * (-2) + image[n + 1][width - 2].rgbtGreen + image[n + 1][width - 1].rgbtGreen * 2, 2.0)));
        new_image[n][width - 1].rgbtRed = (int)round(sqrt(pow(image[n - 1][width - 2].rgbtRed * (-1) + image[n][width - 2].rgbtRed * (-2) + image[n + 1][width - 2].rgbtRed * (-1), 2.0) + pow(image[n - 1][width - 2].rgbtRed * (-1) + image[n - 1][width - 1].rgbtRed * (-2) + image[n + 1][width - 2].rgbtRed + image[n + 1][width - 1].rgbtRed * 2, 2.0)));
    }

    for (int n = 1; n < height - 1; n++)
    {
        new_image[n][0].rgbtBlue = (int)round(sqrt(pow(image[n - 1][1].rgbtBlue + image[n][1].rgbtBlue * 2 + image[n + 1][1].rgbtBlue, 2.0) + pow(image[n - 1][0].rgbtBlue * (-2) + image[n - 1][1].rgbtBlue * (-1) + image[n + 1][0].rgbtBlue * 2 + image[n + 1][1].rgbtBlue, 2.0)));
        new_image[n][0].rgbtGreen = (int)round(sqrt(pow(image[n - 1][1].rgbtGreen + image[n][1].rgbtGreen * 2 + image[n + 1][1].rgbtGreen, 2.0) + pow(image[n - 1][0].rgbtGreen * (-2) + image[n - 1][1].rgbtGreen * (-1) + image[n + 1][0].rgbtGreen * 2 + image[n + 1][1].rgbtGreen, 2.0)));
        new_image[n][0].rgbtRed = (int)round(sqrt(pow(image[n - 1][1].rgbtRed + image[n][1].rgbtRed * 2 + image[n + 1][1].rgbtRed, 2.0) + pow(image[n - 1][0].rgbtRed * (-2) + image[n - 1][1].rgbtRed * (-1) + image[n + 1][0].rgbtRed * 2 + image[n + 1][1].rgbtRed, 2.0)));
    }

    //the rest in the middle
    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            new_image[i][j].rgbtBlue = (int)round(sqrt(pow(image[i - 1][j - 1].rgbtBlue * (-1) + image[i - 1][j + 1].rgbtBlue + image[i][j - 1].rgbtBlue * (-2) + image[i][j + 1].rgbtBlue * 2 + image[i + 1][j - 1].rgbtBlue * (-1) + image[i + 1][j + 1].rgbtBlue, 2.0) + pow(image[i - 1][j - 1].rgbtBlue * (-1) + image[i - 1][j].rgbtBlue * (-2) + image[i - 1][j + 1].rgbtBlue * (-1) + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue * 2 + image[i + 1][j + 1].rgbtBlue, 2.0)));
            new_image[i][j].rgbtGreen = (int)round(sqrt(pow(image[i - 1][j - 1].rgbtGreen * (-1) + image[i - 1][j + 1].rgbtGreen + image[i][j - 1].rgbtGreen * (-2) + image[i][j + 1].rgbtGreen * 2 + image[i + 1][j - 1].rgbtGreen * (-1) + image[i + 1][j + 1].rgbtGreen, 2.0) + pow(image[i - 1][j - 1].rgbtGreen * (-1) + image[i - 1][j].rgbtGreen * (-2) + image[i - 1][j + 1].rgbtGreen * (-1) + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen * 2 + image[i + 1][j + 1].rgbtGreen, 2.0)));
            new_image[i][j].rgbtRed = (int)round(sqrt(pow(image[i - 1][j - 1].rgbtRed * (-1) + image[i - 1][j + 1].rgbtRed + image[i][j - 1].rgbtRed * (-2) + image[i][j + 1].rgbtRed * 2 + image[i + 1][j - 1].rgbtRed * (-1) + image[i + 1][j + 1].rgbtRed, 2.0) + pow(image[i - 1][j - 1].rgbtRed * (-1) + image[i - 1][j].rgbtRed * (-2) + image[i - 1][j + 1].rgbtRed * (-1) + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed * 2 + image[i + 1][j + 1].rgbtRed, 2.0)));
        }
    }

    //cap 255
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (new_image[i][j].rgbtBlue > 255)
            {
                new_image[i][j].rgbtBlue = 255;
            }
            if (new_image[i][j].rgbtGreen > 255)
            {
                new_image[i][j].rgbtGreen = 255;
            }
            if (new_image[i][j].rgbtRed > 255)
            {
                new_image[i][j].rgbtRed = 255;
            }
        }
    }

    //move image to new_image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = new_image[i][j].rgbtBlue;
            image[i][j].rgbtGreen = new_image[i][j].rgbtGreen;
            image[i][j].rgbtRed = new_image[i][j].rgbtRed;
        }
    }

    return;
}
