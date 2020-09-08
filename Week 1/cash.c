#include<stdio.h>
#include<math.h>


int main(void)
{
    int i = 0, cent[] = {25,10,5,1}, num = 0;
    float change;

    do
    {
        printf("Change Owed: ");
        scanf("%f",&change);
    }
    while (change <= 0);

    change = round(change*100);

    while (i <= 3)
    { 
        if (change >= cent[i])
        {
            change = change - cent[i];
            num++;
        }

        else
        {
            i++;
        }
    }
    
    printf("%d",num);   
}