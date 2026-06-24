/********************************************************
 *
 *  Project :  Hexadecimal Numbers
 *  File    :  DexiToHexa.c
 *  Name    :  Cris Cervantes
 *  Date    :  March 8, 2026
 *
 *  Description : Converts decimal values 1-15 into respective hexadecimal value.
 *                Converts hexadecimal values into decimal values.
 *
 *    1) Easy conversion between decimal and hexadecimal
 *    2) Functions, for loops, while loops, pointers, scanf, if statements.
 *
 ********************************************************/
#define _CRT_SECURE_NO_WARNINGS // visual studio, definition needed for scanf
#include <stdio.h>
#include <stdlib.h>

void dectohex(int x);
void hextodec(char* str);

int main()
{
    int choice = 0;
    int chosenDecimal = 0;
    char chosenHex[12];

    printf("This code is written by Cris Cervantes.\n");
    printf("Enter 1 for Decimal to Hexadecimal conversion.\n"
        "Enter 2 for Hexadecimal to Decimal coversion.\n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter a positive decimal number.\n");
        scanf("%d", &chosenDecimal);
        dectohex(chosenDecimal);
    }
    else if (choice == 2)
    {
        printf("Enter a positive hexadecimal number.\n");
        scanf("%s", chosenHex);
        hextodec(chosenHex);
    }
    return 0;
}

void dectohex(int x)
{
    int input = x;
    int remainder = 0;
    char arr[32];
    int start = 30;

    for (int i = 0; i < 31; i++)
    {
        arr[i] = ' ';
    }
    arr[31] = '\0';

    while (x != 0)
    {
         while (x != 0)
    {
        if (x < 10)
        {
            arr[start] = x + '0';
        }
        else
        {
            remainder = x % 16;
            arr[start] = (remainder - 10) + 'A';  
        }
        x = x / 16;
        start--;
    }
        x = x / 16;
        start--;
    }
    printf("The hexadecimal representation of %d is", input);
    printf("%s\n", &arr[start + 1]);
    return;
}

void hextodec(char *str)
{
    int size = strlen(str);
    int dec = 0;
    int temp = 0;

    for (int i = 0; i < size; i++)
    {
        if (str[i] < 70)
        {
            temp = str[i] - 'A' + 10;
        }
        dec = (dec * 16) + temp;
    }
    printf("The decimal representation of %s is %d.\n ", str, dec);
    return;
}