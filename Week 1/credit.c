#include<stdio.h>
#include<math.h>

int getlen(long long int num);

int main()
{
    long long int credit, creditmain;
    int twodigit, len;
    int dsum = 0, d, d2, nsum = 0, n;

    do     //asking credit card number
    {
        printf("Enter credit card number: ");
        scanf("%lld", &creditmain);
        len = getlen(creditmain);  //getlen is my fuction. Counting length
    } 
    while (len <= 0);

    credit = creditmain;
    
    while (credit > 0)
    {
        n = credit % 10;    //other number from the end
        nsum = nsum + n;
        credit = credit / 10;

        d = credit % 10;  //other number from second to last 
        d2 = d * 2;

        if (d2 >= 10) 
        {
            dsum = dsum + (d2 - 10) + 1;  //if double in greater then ten then separate two digit
        }
        else
        {
            dsum = dsum + d2;
        }

        credit = credit / 10;
    }

    int sum = dsum + nsum;
    twodigit = creditmain / pow(10, len - 2);

    if (sum % 10 != 0)    //checking number
    { 
        printf("INVALID\n");
    }
    else if ((twodigit >= 51 && twodigit <= 55) && (len == 16)) 
    {
        printf("MASTERCARD\n");
    }
    else if ((twodigit >= 40 && twodigit <= 49) && (len == 13 || len == 16))
    {
        printf("VISA\n");
    }
    else if ((twodigit == 34 || twodigit == 37) && len == 15) 
    {
        printf("AMEX\n");
    }
    else   //if other number, invalid
    {
        printf("INVALID\n");
    }
    
}

int getlen(long long int num)
{
    int count = 0;

    while (num > 0)  //counting length
    {
        num = num / 10;
        count++;
    }
    
    return count;
}

