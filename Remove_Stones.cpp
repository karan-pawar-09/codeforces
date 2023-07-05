/*
    author:Karan
    created:28.06.2023 21:09:11
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
    int n, k;
    cin >> n >> k;
    if(__gcd(n, k) == 1) {
        cout<<"Alice"<<endl;
        fflush(stdout);
        cout<<n<<endl;
        fflush(stdout);
        int input;
        cin >> input;
        if(input == 0) {
            return;
        }
    } else {
        int index = -1;
        for(int i = 1; i <= n; i++) {
            if(__gcd(i, k) != 1) {
                index = i;
                break;
            }
        }
        if(index == n) {
            cout<<"Bob"<<endl;
            fflush(stdout);
            int input;
            cin >> input;
            if(input == 0) {
                return;
            }
            cout<<input<<endl;
            fflush(stdout);
            cin >> input;
            if(input == 0) {
                return;
            }
        } else {
            cout<<"Alice"<<endl;
            fflush(stdout);
            cout<<n - index<<endl;
            fflush(stdout);
            int input;
            cin >> input;
            if(input == 0) {
                return;
            }
            cout<<input<<endl;
            fflush(stdout);
            cin >> input;
            if(input == 0) {
                return;
            }
        }
    }
}

int32_t main() {

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}