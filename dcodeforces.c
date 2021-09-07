#include<stdio.h>
#include<string.h>

int main() {
    int q;
    char s[100007];
    char t[100007];
    scanf("%d",&q);
    while(q--) {
        scanf("%s",s);
        scanf("%s",t);
        int n=strlen(s);
        int m=strlen(t);
        int ans=0;
        int j=m-1;
        int i=n-1;
        while(s[i]!=t[j]||((n-i)%2==0)) {
            i--;
        }
        while(i>=0&&j>=0) {
            if(s[i]==t[j]) {
                i--;
                j--;
            }
            else {
                i-=2;
            }
        }
        if(j==-1) ans=1;

        if(ans) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
}