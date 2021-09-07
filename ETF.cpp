#include<bits/stdc++.h>
using namespace std;
int ETF (int a) {
    int num=a;
    for(int i=2;i*i<=a;i++) {
        if(a%i==0) {
            while(a%i==0) {
                a/=i;
            }
            num-=num/i;
        }
    }
    if(a>1){
        num-=num/a;
    }
    return num;
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        printf("%d\n",ETF(n));
    }
}
