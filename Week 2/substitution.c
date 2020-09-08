#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>

int main(int argc, string argv[])
{  
    if (argc != 2)
    {
        printf("usage: ./na key\n");
        return 1;
    }
    else {
        if (strlen(argv[1]) != 26)          //check length 
        {
            printf("Please enter 26 charecters\n");
            return 1;
        }
        for (int i = 0; i < 26; i++)       //check letter
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Enter valid alfabet\n");
                return 1;
            }
        }
        for (int i = 0; i < 26; i++)     //check duplicate
        {
            for (int j = i + 1; j < 26; j++)
            {
                if (argv[1][i] == argv[1][j])
                {
                    printf("Do not repeat\n");
                    return 1;
                }
            }
        }

        char alpha[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", key_alpha[26];

        for (int i = 0; i < 26; i++)    //assing key as upper case
        {
            if (isupper(argv[1][i]))
            {
                key_alpha[i] = argv[1][i];
            }
            else if (islower(argv[1][i]))
            {
                key_alpha[i] = toupper(argv[1][i]);  //lower to upper case
            }
            else
            {
                continue;
            }
        }

        char text[] = {};
        printf("plaintext: ");
        scanf(" %[^\n]", text);
        
        printf("ciphertext: ");

        for (int i = 0, l = strlen(text); i < l; i++)
            {
                if (isupper(text[i]) != 0)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        if(alpha[j] == tolower(text[i]))
                        {
                            printf("%C", toupper(key_alpha[j]));
                            break;
                        }
                    }
                }
                else if (islower(text[i]) != 0)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        if(alpha[j] == text[i])
                        {
                            printf("%c", tolower(key_alpha[j]));
                            break;
                        }
                    }
                }
                else
                {
                    printf("%c", text[i]);
                }
        }
    }
        printf("\n");
}