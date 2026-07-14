#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green, and blue
            double average = 
                round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            // Update pixel values
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
}
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green, and blue
            double sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                                    .189 * image[i][j].rgbtBlue);
            if (sepiaRed > 255)
                sepiaRed = 255;
            double sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                                      .168 * image[i][j].rgbtBlue);
            if (sepiaGreen > 255)
                sepiaGreen = 255;
            double sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                                     .131 * image[i][j].rgbtBlue);
            if (sepiaBlue > 255)
                sepiaBlue = 255;
            // Update pixel values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Swap pixels
            RGBTRIPLE tmp;
            tmp = image[i][width - j - 1];
            image[i][width - j - 1] = image[i][j];
            image[i][j] = tmp;
        }
    }
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sumRed = 0, sumGreen = 0, sumBlue = 0;
            int neib_count = 0;
            for (int neib_i = i - 1; neib_i <= i + 1; neib_i++)
            {
                for (int neib_j = j - 1; neib_j <= j + 1; neib_j++)
                {
                    if (neib_i >= 0 && neib_i < height && neib_j >= 0 && neib_j < width)
                    {
                        sumRed += copy[neib_i][neib_j].rgbtRed;
                        sumGreen += copy[neib_i][neib_j].rgbtGreen;
                        sumBlue += copy[neib_i][neib_j].rgbtBlue;
                        neib_count++;
                    }
                }
            }
            image[i][j].rgbtRed = round(sumRed / neib_count);
            image[i][j].rgbtGreen = round(sumGreen / neib_count);
            image[i][j].rgbtBlue = round(sumBlue / neib_count);
        }
    }
}