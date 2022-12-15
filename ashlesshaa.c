#include<stdio.h>
#include<string.h>
#include<math.h>

const int inf = 1e9+7;

int min(int a, int b) {
    if(a< b) {
        return a;
    } else {
        return b;
    }
}
int magical_string(int n, char arr[]) {
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
    return min(dp[n-1][0], dp[n-1][1]);
}

int main() {
    int n;
    scanf("%d", &n);
    char s[n];
    scanf("%s", s);
    printf("%d", magical_string(n, s));
}



