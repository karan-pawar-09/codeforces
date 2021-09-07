#include <stdio.h>
#include <string.h>
void swap(char *str1, char *str2)
{
    char *temp = str1;
    str1 = str2;
    str2 = temp;
}
char *findSum(char str1[], char str2[])
{
    if (strlen(str1) > strlen(str2))
        swap(str2, str1);

    int n1 = strlen(str1), n2 = strlen(str2);
    char str[100000];

    int diff = n2 - n1;

    int carry = 0;
    int j = 0;
    for (int i = n1 - 1; i >= 0; i--)
    {
        int sum = ((str1[i] - '0') +
                   (str2[i + diff] - '0') +
                   carry);
        str[j] = (sum % 10 + '0');
        j++;
        carry = sum / 10;
    }

    for (int i = n2 - n1 - 1; i >= 0; i--)
    {
        int sum = ((str2[i] - '0') + carry);
        str[j] = (sum % 10 + '0');
        j++;
        carry = sum / 10;
    }

    if (carry)
    {
        str[j] = (carry + '0');
        j++;
    }
    char temp[2];

    for (int i = 0; i < strlen(str) / 2; i++)
    {
        temp[0] = str[i];
        str[i] = str[strlen(str) - i - 1];
        str[strlen(str) - i - 1] = temp[0];
    }
    char *strp = &str;

    return strp;
}
int main()
{
    int n, t;
    scanf("%d", &t);
    int count;
    while (t > 0)
    {
        scanf("%d", &n);

        if (n == 0)
        {
            printf("0");
        }
        else if (n > 0)
        {
            char a[100000] = "0";
            char b[100000] = "1";

            char next[100000] = "0";

            int count = 2;
            while (count <= n)
            {

                strcpy(next, findSum(a, b));
                strcpy(a, b);
                strcpy(b, next);
                count++;
            }
            printf("%s", b);
        }
        else
            printf("Invalid input");

        t--;
    }
}