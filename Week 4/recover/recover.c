#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("usages: ./recover image\n");
    }
    //open files
    FILE *file = fopen(argv[1], "r");
    FILE *img = NULL;

    int img_no = 0;     //declar variables
    char filename[8];
    unsigned char buffer[512];
    bool start = false;   //trigger

    while (fread(buffer, 512, 1, file) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (img_no == 0)     //if t
            {
                start = true;  //trigger to start
                img = fopen("000.jpg", "a");
                img_no++;
            }
            else
            {
                fclose(img);    //
                sprintf(filename, "%03i.jpg", img_no);
                img = fopen(filename, "a");
                img_no++;
            }
        }
        if (start == true)
        {
            fwrite(buffer, 512, 1, img);
        }
    }
    
    fclose(img);
    fclose(file);
    
}