#include "helpers.h"
#include <stdio.h>
#include <math.h>
#include "string.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int x;
    int y;

    y = 0;
    x = 0;
    while (y < height)
    {
        while (x < width)
        {
            image[y][x].rgbtRed = round((image[y][x].rgbtRed + image[y][x].rgbtGreen + image[y][x].rgbtBlue) / 3.0);
            image[y][x].rgbtGreen = image[y][x].rgbtRed;
            image[y][x].rgbtBlue = image[y][x].rgbtRed;
            x++;
        }
        if (x == width)
        {
            x = 0;
            y++;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int x;
    int y;

    y = 0;
    x = 0;
    while (y < height)
    {
        while (x < width)
        {
            int sRed = image[y][x].rgbtRed;
            int sGreen = image[y][x].rgbtGreen;
            int sBlue = image[y][x].rgbtBlue;

            int rgbtRed = round(.393 * sRed + .769 * sGreen + .189 * sBlue);
            int rgbtGreen = round(.349 * sRed + .686 * sGreen + .168 * sBlue);
            int rgbtBlue = round(.272 * sRed + .534 * sGreen + .131 * sBlue);

            image[y][x].rgbtRed = fmin(255, rgbtRed);
            image[y][x].rgbtGreen = fmin(255, rgbtGreen);
            image[y][x].rgbtBlue = fmin(255, rgbtBlue);

            x++;
        }
        if (x == width)
        {
            x = 0;
            y++;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int x;
    int y;
    int swap;

    x = 0;
    y = 0;
    swap = 0;
    while (y < height)
    {
        while (x < width / 2)
        {
            swap = image[y][x].rgbtRed;
            image[y][x].rgbtRed = image[y][width - 1 - x].rgbtRed;
            image[y][width - 1 - x].rgbtRed = swap;
            swap = image[y][x].rgbtGreen;
            image[y][x].rgbtGreen = image[y][width - 1 - x].rgbtGreen;
            image[y][width - 1 - x].rgbtGreen = swap;
            swap = image[y][x].rgbtBlue;
            image[y][x].rgbtBlue = image[y][width - 1 - x].rgbtBlue;
            image[y][width - 1 - x].rgbtBlue = swap;
            x++;
        }
        x = 0;
        y++;
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Temporary storage
    RGBTRIPLE temp[height][width];

    // Copying the image to keep an unaltered version to loop over
    memcpy(temp, image, sizeof(RGBTRIPLE) * height * width);

    // Iterate over every row of the image
    for (int i = 0; i < height; i++)
    {
        // Iterate over every column of the image
        for (int j = 0; j < width; j++)
        {
            // Initiate average counter at 0.0
            // Gotta avoid the truncated integer problem
            float average = 0.0;
            // Initiate RGB values at 0
            int red = 0;
            int green = 0;
            int blue = 0;

            // Iterate over rows around current row
            for (int k = -1; k <= 1; k++)
            {
                // Iterate over columns around current column
                for (int l = -1; l <= 1; l++)
                {

                    if (i + k != height &&
                        i + k != -1 &&
                        j + l != width &&
                        j + l != -1)
                    {
                        // Update RGB values to the sum both pixels' RGB values
                        red += temp[i + k][j + l].rgbtRed;
                        green += temp[i + k][j + l].rgbtGreen;
                        blue += temp[i + k][j + l].rgbtBlue;
                        // Increment average by one for one pixel in the sum
                        average++;
                    }
                }
            }
            // Set each RGB values to their blurred values
            image[i][j].rgbtRed = round(red / average);
            image[i][j].rgbtGreen = round(green / average);
            image[i][j].rgbtBlue = round(blue / average);
        }
    }
}

