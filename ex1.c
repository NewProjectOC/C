#include <stdio.h>

int main()
{
    int num, temp;
    int sum = 0;
    printf("Please input a number:");
    scanf("%d", &num);
    temp = num;
    while(num)
    {
        sum = sum*10 + num%10;
        num /= 10;
    }
    if(temp == sum)
        printf("it is a palindrome number\n");
    else
        printf("it is not a palindrome number\n");

    return 0;
}
