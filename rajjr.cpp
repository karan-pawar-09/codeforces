/*
    author:Karan
    created:07.11.2022 09:08:08
*/
#if true
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define mset(a,x) memset(a,x,sizeof(a))
#endif

const int inf = 1e9+7;

int min(int a, int b) {
    if(a< b) {
        return a;
    } else {
        return b;
    }
}
int magical_string(int n, char arr[]) {
    int i = 1;
    int del = 0;
    int temp = 0;
    while((i+del) < n) {
        if((i+del)%2) {
            while(arr[(i+del)] == arr[i+temp-1]) {
                del++;
            }
            temp = del;
        }
        i++;
    }
    int res = del;
    i= 2;
    del = 0;
    temp = 0;
    while((i+del) < n) {
        if((i+del)%2) {
            while(arr[(i+del)] == arr[i+temp-1]) {
                del++;
            }
            temp = del;
        }
        i++;
    }
    if(del+1 < res) {
        res = del+1;
    }

    int dp[n][2];
    int len[n][2];
    int alp[n][2];
    dp[0][0] = 1;
    len[0][0] = 0;
    alp[0][0] = 500;
    dp[0][1] = 0;
    len[0][1] = 1;
    alp[0][1] = (int)arr[0];
    for(int i=1;i<n;i++) {
        dp[i][0] = inf;
        dp[i][1] = inf;
        {
            //delete
            
            if(dp[i-1][0] < dp[i-1][1]) {
                dp[i][0] = dp[i-1][0]+1;
                len[i][0] = len[i-1][0];
                alp[i][0] = alp[i-1][0];
            } else {
                dp[i][0] = dp[i-1][1]+1;
                len[i][0] = len[i-1][1];
                alp[i][0] = alp[i-1][1];
            }
        } 
        {
            //if(len[i-1][0])
            if(alp[i-1][0] != (int)arr[i]) {
                dp[i][1] = dp[i-1][0];
                len[i][1] = len[i-1][0]+1;
                alp[i][1] = (int)arr[i];
            } else {
                if(len[i-1][0]%2) {
                    len[i][1] = len[i-1][0]+1;
                    alp[i][1] = (int)arr[i];
                } else {
                    dp[i][1] = dp[i-1][0];
                    len[i][1] = len[i-1][0]+1;
                    alp[i][1] = (int)arr[i];
                }
            }
            if(alp[i-1][1] != (int)arr[i]) {
                if(dp[i-1][1] < dp[i-1][0]) {
                    dp[i][1] = dp[i-1][1];
                    len[i][1] = len[i-1][1]+1;
                    alp[i][1] = (int)arr[i];
                }
            } else {
                if(len[i-1][1]%2) {
                    if(dp[i][1] == inf) {
                        len[i][1] = len[i-1][1]+1;
                        alp[i][1] = (int)arr[i];
                    }
                } else {
                    if(dp[i][1] > dp[i-1][1]) {
                        dp[i][1] = dp[i-1][1];
                        len[i][1] = len[i-1][1]+1;
                        alp[i][1] = (int)arr[i];
                    }
                }
            }
        }
    }
    // for(int i=0;i<n;i++) {
    //     cout<<dp[i][0]<<" "<<dp[i][1]<<" | "<<(char)alp[i][0]<<" "<<(char)alp[i][1]<<" | "<<len[i][0]<<" "<<len[i][1]<<endl;
    // }
    return min(dp[n-1][0], dp[n-1][1]);
}

int main() {
    int n;
    scanf("%d", &n);
    char s[n];
    scanf("%s", s);
    printf("%d", magical_string(n, s));
}