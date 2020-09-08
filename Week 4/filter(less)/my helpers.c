#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int b, r, g, avg;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            b = image[i][j].rgbtBlue;
            g = image[i][j].rgbtGreen;
            r = image[i][j].rgbtRed;
            avg = round(((float) r + (float) b + (float) g) / 3);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed, sepiaGreen, sepiaBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaRed = round(.393 * (float) image[i][j].rgbtRed + .769 * (float) image[i][j].rgbtGreen + .189 * (float) image[i][j].rgbtBlue);
            sepiaGreen = round(.349 * (float) image[i][j].rgbtRed + .686 * (float) image[i][j].rgbtGreen + .168 * (float) image[i][j].rgbtBlue);
            sepiaBlue = round(.272 * (float) image[i][j].rgbtRed + .534 * (float) image[i][j].rgbtGreen + .131 * (float) image[i][j].rgbtBlue);

                image[i][j].rgbtBlue = sepiaBlue;
                image[i][j].rgbtGreen = sepiaGreen;
                image[i][j].rgbtRed = sepiaRed;

            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //temporary storage
    RGBTRIPLE temp_image;
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width / 2; i++)
        {
            //store data temporarily
            temp_image = image[j][i];
            image[j][i] = image[j][width - i - 1];
            image[j][width - i - 1] = temp_image;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE temp_img[height][width])
{
    RGBTRIPLE image[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //four corner
            if ((i == 0 && j == 0) )
            {
                image[i][j].rgbtRed = round((temp_img[i][j].rgbtRed + temp_img[i][j + 1].rgbtRed + 
                                    temp_img[i + 1][j].rgbtRed + temp_img[i + 1][j + 1].rgbtRed) / 4);
                image[i][j].rgbtBlue = round((temp_img[i][j].rgbtBlue + temp_img[i][j + 1].rgbtBlue + 
                                    temp_img[i + 1][j].rgbtBlue + temp_img[i + 1][j + 1].rgbtBlue) / 4);
                image[i][j].rgbtRed = round((temp_img[i][j].rgbtGreen + temp_img[i][j + 1].rgbtGreen + 
                                    temp_img[i + 1][j].rgbtGreen + temp_img[i + 1][j + 1].rgbtGreen) / 4);
            }
            else if (i == 0 && j == width - 1)
            {
                image[i][j].rgbtRed = round((temp_img[i][j - 1].rgbtRed + temp_img[i][j].rgbtRed +
                                    temp_img[i + 1][j - 1].rgbtRed + temp_img[i + 1][j].rgbtRed) / 4);
                image[i][j].rgbtBlue = round((temp_img[i][j - 1].rgbtBlue + temp_img[i][j].rgbtBlue + 
                                    temp_img[i + 1][j - 1].rgbtBlue + temp_img[i + 1][j].rgbtBlue) / 4);
                image[i][j].rgbtGreen = round((temp_img[i][j - 1].rgbtGreen + temp_img[i][j].rgbtGreen + 
                                    temp_img[i + 1][j - 1].rgbtGreen+ temp_img[i + 1][j].rgbtGreen) / 4);
            }
            else if (i == height - 1 && j == 0)
            {
                image[i][j].rgbtRed = round((temp_img[i - 1][j].rgbtRed + temp_img[i - 1][j + 1].rgbtRed + 
                                    temp_img[i][j + 1].rgbtRed + temp_img[i][j].rgbtRed) / 4);
                image[i][j].rgbtBlue = round((temp_img[i - 1][j].rgbtBlue + temp_img[i - 1][j + 1].rgbtBlue + 
                                    temp_img[i][j + 1].rgbtBlue + temp_img[i][j].rgbtBlue) / 4);
                image[i][j].rgbtGreen = round((temp_img[i - 1][j].rgbtGreen + temp_img[i - 1][j + 1].rgbtGreen + 
                                    temp_img[i][j + 1].rgbtGreen + temp_img[i][j].rgbtBlue) / 4);
            }
            else if (i == height - 1 && j == width - 1)
            {
                image[i][j].rgbtRed = round((temp_img[i - 1][j - 1].rgbtRed + temp_img[i - 1][j].rgbtRed + 
                                    temp_img[i][j - 1].rgbtRed + temp_img[i][j].rgbtRed) / 4);
                image[i][j].rgbtBlue = round((temp_img[i - 1][j].rgbtBlue + temp_img[i - 1][j].rgbtBlue + 
                                    temp_img[i][j - 1].rgbtBlue + temp_img[i][j].rgbtBlue) / 4);
                image[i][j].rgbtGreen = round((temp_img[i - 1][j].rgbtGreen + temp_img[i - 1][j].rgbtGreen + 
                                    temp_img[i][j - 1].rgbtGreen + temp_img[i][j].rgbtGreen) / 4);
            }
            //four sides
            else if (i == 0 && j != 0 && j != width - 1)
            {
                image[i][j].rgbtRed = round((temp_img[i + 1][j - 1].rgbtRed + temp_img[i + 1][j].rgbtRed + temp_img[i + 1][j + 1].rgbtRed
                                        + temp_img[i][j - 1].rgbtRed + temp_img[i][j].rgbtRed + temp_img[i][j + 1].rgbtRed) / 6);
                image[i][j].rgbtGreen = round((temp_img[i + 1][j - 1].rgbtGreen + temp_img[i + 1][j].rgbtGreen + temp_img[i + 1][j + 1].rgbtGreen
                                        + temp_img[i][j - 1].rgbtGreen + temp_img[i][j].rgbtGreen + temp_img[i][j + 1].rgbtGreen) / 6);
                image[i][j].rgbtBlue = round((temp_img[i + 1][j - 1].rgbtBlue + temp_img[i + 1][j].rgbtBlue + temp_img[i + 1][j + 1].rgbtBlue
                                        + temp_img[i + 1][j - 1].rgbtBlue + temp_img[i][j].rgbtBlue + temp_img[i][j + 1].rgbtBlue) / 6);
            }
            else if (i == height - 1 && j != 0 && j != width - 1)
            {
                image[i][j].rgbtRed = round((temp_img[i - 1][j - 1].rgbtRed + temp_img[i - 1][j].rgbtRed + temp_img[i - 1][j + 1].rgbtRed
                                            + temp_img[i][j - 1].rgbtRed + temp_img[i][j].rgbtRed + temp_img[i][j + 1].rgbtRed) / 6);
                image[i][j].rgbtGreen = round((temp_img[i - 1][j - 1].rgbtGreen + temp_img[i - 1][j].rgbtGreen + temp_img[i - 1][j + 1].rgbtGreen
                                            + temp_img[i][j - 1].rgbtGreen + temp_img[i][j].rgbtGreen + temp_img[i][j + 1].rgbtGreen) / 6);
                image[i][j].rgbtBlue = round((temp_img[i - 1][j - 1].rgbtBlue + temp_img[i - 1][j].rgbtBlue + temp_img[i - 1][j + 1].rgbtBlue
                                            + temp_img[i + 1][j - 1].rgbtBlue + temp_img[i][j].rgbtBlue + temp_img[i][j + 1].rgbtBlue) / 6);
            }
            else if (i != 0 && i != height - 1 && j == 0)
            {
                image[i][j].rgbtRed = round((temp_img[i + 1][j + 1].rgbtRed + temp_img[i][j + 1].rgbtRed + temp_img[i - 1][j + 1].rgbtRed
                                            + temp_img[i + 1][j].rgbtRed + temp_img[i][j].rgbtRed + temp_img[i - 1][j].rgbtRed) / 6);
                image[i][j].rgbtGreen = round((temp_img[i + 1][j + 1].rgbtGreen + temp_img[i][j + 1].rgbtGreen + temp_img[i - 1][j + 1].rgbtGreen
                                            + temp_img[i + 1][j].rgbtGreen + temp_img[i][j].rgbtGreen + temp_img[i + 1][j].rgbtGreen) / 6);
                image[i][j].rgbtBlue = round((temp_img[i + 1][j + 1].rgbtBlue + temp_img[i][j + 1].rgbtBlue + temp_img[i - 1][j + 1].rgbtBlue
                                            + temp_img[i + 1][j].rgbtBlue + temp_img[i][j].rgbtBlue + temp_img[i - 1][j].rgbtBlue) / 6);
            }
            else if (i != 0 && i !=height - 1 && j == width - 1)
            {
                image[i][j].rgbtRed = round((temp_img[i + 1][j - 1].rgbtRed + temp_img[i][j - 1].rgbtRed + temp_img[i - 1][j - 1].rgbtRed
                                            + temp_img[i + 1][j].rgbtRed + temp_img[i][j].rgbtRed + temp_img[i - 1][j].rgbtRed) / 6);
                image[i][j].rgbtGreen = round((temp_img[i + 1][j - 1].rgbtGreen + temp_img[i][j - 1].rgbtGreen + temp_img[i - 1][j - 1].rgbtGreen
                                            + temp_img[i + 1][j].rgbtGreen + temp_img[i][j].rgbtGreen + temp_img[i + 1][j].rgbtGreen) / 6);
                image[i][j].rgbtBlue = round((temp_img[i + 1][j - 1].rgbtBlue + temp_img[i][j - 1].rgbtBlue + temp_img[i - 1][j - 1].rgbtBlue
                                            + temp_img[i + 1][j].rgbtBlue + temp_img[i][j].rgbtBlue + temp_img[i - 1][j].rgbtBlue) / 6);
            }
            //whole photo
            else
            {
                image[i][j].rgbtRed = round((temp_img[i - 1][j - 1].rgbtRed + temp_img[i - 1][j].rgbtRed + temp_img[i - 1][j + 1].rgbtRed
                                            + temp_img[i][j - 1].rgbtRed + temp_img[i][j].rgbtRed + temp_img[i][j + 1].rgbtRed
                                            + temp_img[i + 1][j - 1].rgbtRed + temp_img[i + 1][j].rgbtRed + temp_img[i + 1][j + 1].rgbtRed) / 9);
                image[i][j].rgbtBlue = round((temp_img[i - 1][j - 1].rgbtBlue + temp_img[i - 1][j].rgbtBlue  + temp_img[i - 1][j + 1].rgbtBlue 
                                            + temp_img[i][j - 1].rgbtBlue  + temp_img[i][j].rgbtBlue  + temp_img[i][j + 1].rgbtBlue 
                                            + temp_img[i + 1][j - 1].rgbtBlue  + temp_img[i + 1][j].rgbtBlue  + temp_img[i + 1][j + 1].rgbtBlue ) / 9);
                image[i][j].rgbtGreen = round((temp_img[i - 1][j - 1].rgbtGreen + temp_img[i - 1][j].rgbtGreen  + temp_img[i - 1][j + 1].rgbtGreen 
                                            + temp_img[i][j - 1].rgbtGreen  + temp_img[i][j].rgbtGreen  + temp_img[i][j + 1].rgbtGreen 
                                            + temp_img[i + 1][j - 1].rgbtGreen  + temp_img[i + 1][j].rgbtGreen  + temp_img[i + 1][j + 1].rgbtGreen ) / 9);
            }    
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp_img[i][j].rgbtBlue = image[i][j].rgbtBlue;
            temp_img[i][j].rgbtGreen = image[i][j].rgbtGreen;
            temp_img[i][j].rgbtRed = image[i][j].rgbtRed;
        }
    }
    return;
    
}
