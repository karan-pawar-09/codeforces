#include<stdio.h>
int main()
{
    int tag, flag=1, rem1, rem2;
    printf("Please Enter tag: ");
    scanf("%d",&tag);
    int len=0;
    int prev=0;
    while(tag!=0)
    {
        len++;
        int cur=tag%10;
        tag=tag/10;
        if(len!=1) {
            if((cur+prev) % 2==0) {

            }
            else {
                flag=0;
            }
        }
        prev=cur;
    }
    if(len!=8) {
        flag=0;
    }
    if(flag==0)
    {
        printf("Invalid");
    }
    else
    {
        printf("Valid");
    }
    return 0;
}