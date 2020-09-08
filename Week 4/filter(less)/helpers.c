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
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_img[height][width];      //temporary image
    //iretate through all pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int pixel = 0, r = 0, g = 0, b = 0;
            //9 pixels 
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    //if pixel outside of photo, continue
                    if (i + di >= 0 && i + di < height && j + dj >= 0 && j + dj < width)
                    {
                        r = r + image[i + di][j + dj].rgbtRed;
                        b = b + image[i + di][j + dj].rgbtBlue;
                        g = g + image[i + di][j + dj].rgbtGreen;
                        pixel++;
                    }
                }
                //count avg
                temp_img[i][j].rgbtBlue = round((float) b / pixel);
                temp_img[i][j].rgbtGreen = round((float) g / pixel);
                temp_img[i][j].rgbtRed = round((float) r / pixel);
            }
        }
    }
    //assing to real photo
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp_img[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp_img[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp_img[i][j].rgbtRed;
        }
    }
    return;
}