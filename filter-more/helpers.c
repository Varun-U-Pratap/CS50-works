#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int avg = round(
                (image[row][col].rgbtBlue + image[row][col].rgbtRed + image[row][col].rgbtGreen) /
                3.00);
            image[row][col].rgbtRed = image[row][col].rgbtBlue = image[row][col].rgbtGreen = avg;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[width];
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width / 2; col++)
        {
            temp[col] = image[row][col];
            image[row][col] = image[row][(width - 1) - col];
            image[row][(width - 1) - col] = temp[col];
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image1[height][width];
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int count = 0, sumred = 0, sumgreen = 0, sumblue = 0;
            for (int row1 = row - 1; row1 < row + 2; row1++)
            {
                for (int col1 = col - 1; col1 < col + 2; col1++)
                {
                    if ((row1 >= 0 && row1 < height) && (col1 >= 0 && col1 < width))
                    {
                        sumred += image[row1][col1].rgbtRed;
                        sumgreen += image[row1][col1].rgbtGreen;
                        sumblue += image[row1][col1].rgbtBlue;
                        count++;
                    }
                }
            }
            image1[row][col].rgbtRed = round((sumred + 0.0) / (count + 0.0));
            image1[row][col].rgbtGreen = round((sumgreen + 0.0) / (count + 0.0));
            image1[row][col].rgbtBlue = round((sumblue + 0.0) / (count + 0.0));
        }
    }
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            image[row][col] = image1[row][col];
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image1[height][width];
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}},
        Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int sumxr = 0, sumxg = 0, sumxb = 0, sumyr = 0, sumyg = 0, sumyb = 0;

            for (int r = -1; r < 2; r++)
            {
                for (int c = -1; c < 2; c++)
                {
                    if (row + r < 0 || row + r > height - 1)
                    {
                        continue;
                    }
                    if (col + c < 0 || col + c > width - 1)
                    {
                        continue;
                    }

                    sumxb += image[row + r][col + c].rgbtBlue * Gx[r + 1][c + 1];
                    sumyb += image[row + r][col + c].rgbtBlue * Gy[r + 1][c + 1];
                    sumxg += image[row + r][col + c].rgbtGreen * Gx[r + 1][c + 1];
                    sumyg += image[row + r][col + c].rgbtGreen * Gy[r + 1][c + 1];
                    sumxr += image[row + r][col + c].rgbtRed * Gx[r + 1][c + 1];
                    sumyr += image[row + r][col + c].rgbtRed * Gy[r + 1][c + 1];
                }
            }
            int blue = round(sqrt((sumxb * sumxb) + (sumyb * sumyb)));
            int green = round(sqrt((sumxg * sumxg) + (sumyg * sumyg)));
            int red = round(sqrt((sumxr * sumxr) + (sumyr * sumyr)));

            image1[row][col].rgbtBlue = (blue > 255) ? 255 : blue;
            image1[row][col].rgbtGreen = (green > 255) ? 255 : green;
            image1[row][col].rgbtRed = (red > 255) ? 255 : red;
        }
    }
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            image[row][col] = image1[row][col];
        }
    }
}
