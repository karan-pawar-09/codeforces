/*
    author:Karan
    created:04.06.2023 12:19:08
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

void solve() {
    int N; cin >> N;
    int A[N+2]; 
    A[0] = 0;
    A[N+1] = N+1;
    for(int i = 1; i < (N+1); i++) {
        cin >> A[i];
    }

    // [0] 7 [3 4 6 8 9 10] 2 5 [11] 1 [12]

    int dp[N+2][N+1];
    for(int i = 0; i < N+2; i++) {
        for(int j = 0; j < N+1; j++) {
            dp[i][j] = N+1;
        }
    }
    for(int i = 0; i < N+1; i++) {
        dp[0][i] = 0;
    }

    for(int i = 1; i < N+2; i++) {
        for(int j = 0; j < N+1; j++) {
            if(A[i] > A[i-1]) {
                dp[i][j] = min(dp[i][j], dp[i-1][j]);
            }
            if(j) {
                for(int k = i; k >= 0; k--) {
                    if(A[k] < A[i]) {
                        dp[i][j] = min(dp[i][j], dp[k][j-1] + i - k - 1);
                    }
                }
            }
        }
    }

    for(int i = 0; i < N + 2; i++) {
        for(int j = 0; j < N + 1; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
    // for(int i = 1; i < N + 1; i++) {
    //     cout << dp[N + 1][i] << " ";
    // }
    // cout << endl;
  
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}

