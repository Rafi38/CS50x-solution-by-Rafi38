#include<stdio.h>

int main(void)
{
    int n, i, j, k,l;
    
    do
    {
        printf("Enter a positive number: "); //taking input
        scanf("%d", &n);
    } 
    while (n < 1 || n > 8);
    
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < n - i; j++) //printing spaces
        {
            printf(" ");
        }
        for (k = 0; k < i; k++)  //printing #
        {
            printf("#");
        }
        printf("  ");

        for (l = 0; l < i; l++)
        {
            printf("#");
        }
        printf("\n");
        
    }
    
    
}