#include <stdio.h>

void to_octal(int num)
{
    char res[32];
    int count = 0;

    while (num)
    {
        int rem = num % 8;
        res[count] = rem + '0';
        count += 1;
        num /= 8;
    }

    for (int i = count - 1; i >= 0; i--)
    {
        printf("%c", res[i]);
    }
}

void to_binary(int num)
{
    char res[32];
    int count = 0;

    while (num)
    {
        int rem = num % 2;
        res[count] = rem + '0';
        count += 1;
        num /= 2;
    }

    for (int i = count - 1; i >= 0; i--)
    {
        printf("%c", res[i]);
    }
}

void to_hexadecimal(int num)
{
    char res[32];
    int count = 0;

    while (num)
    {
        int rem = num % 16;
        if (rem < 10)
        {
            res[count] = rem + '0';
        }
        else
        {
            res[count] = rem - 10 + 'A';
        }
        count += 1;
        num /= 16;
    }

    for (int i = count - 1; i >= 0; i--)
    {
        printf("%c", res[i]);
    }
}

int main()
{
    int num;
    printf("Enter number: ");
    scanf("%d", &num);

    printf("Binary: ");
    to_binary(num);

    printf("    Octal: ");
    to_octal(num);

    printf("    Hexadecimal: ");
    to_hexadecimal(num);

    return 0;
}
