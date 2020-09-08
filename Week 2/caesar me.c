#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
    int key;
    do
    {  
        printf("Enter key: ");
        scanf("%i", &key);
    } while (key < 1 || key > 26);
    

    char ntext[] = {}, ctext[] ={};
    printf("Normal text: ");
    scanf(" %[^\n]", ntext);
    
    for (int i = 0, len = strlen(ntext); i < len; i++)
    {    
        int pi, ci, shift; 
        if (isupper(ntext[i]))
        {
            pi = ntext[i] - 65;
            ci = (pi + key) % 26;
            ctext[i] = ci + 65;

        }
        else if (islower(ntext[i]))
        {
            pi = ntext[i] - 97;
            ci = (pi + key) % 26;
            ctext[i] = ci + 97;
        }
        else
        {
           ctext[i] = ntext[i];
        }    
    }
    
    printf("encoded text: %s\n", ctext);
}