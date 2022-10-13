/*
    author:Karan
    created:13.10.2022 20:10:41
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
    int n = 8;
    vector<vector<char>> arr(8, vector<char>(8));
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            cin>>arr[i][j];
        }
    }
    int R =0;
    int B = 0;

    for(int i=0;i<n;i++) {
        R=0;
        if(arr[i][0] != '.') {
            for(int j=0;j<n;j++) {
                if(arr[i][j] == 'R') {
                    R++;
                }
            }
        }
        if(R==8) {
            cout<<"R"<<endl;
            return;
        }
    }
    for(int j=0;j<n;j++) {
        B=0;
        if(arr[0][j] != '.') {
            for(int i=0;i<n;i++) {
                if(arr[i][j] == 'B') {
                    B++;
                }
            }
        }
        if(B==8) {
            cout<<"B"<<endl;
            return;
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}