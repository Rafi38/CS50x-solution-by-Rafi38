#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<cs50.h>

int main(int argc, string argv[])
{
    
    if (argc != 2) //checking cmnd line argmnt
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    for (int j = 0, l = strlen(argv[1]); j < l; j++) //checking non-digit number
    {
        if (!isdigit(argv[1][j]))
        {
            return 1;
        }
    }
    
    int key = atoi(argv[1]);  //string to digit

    string text = get_string("plaintext: ");

    printf("ciphertext: ");       //encodin

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        int pi, ci;
        if (isupper(text[i]))     //shifting upper case
        {
            pi = text[i] - 65;
            ci = (pi + key) % 26 + 65;
            printf("%c", ci);

        }
        else if (islower(text[i]))  //shifting lower case
        {
            pi = text[i] - 97;
            ci = (pi + key) % 26 + 97;
            printf("%c", ci);
        }
        else   //unchanged other chers
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}