// (a+k)*b = 4*x

// 1 2 3 4 5 6 7 8

// 4 1
// 8 3

/*
    author:Karan
    created:16.08.2022 20:15:36
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
    ll n, k;
    cin>>n>>k;
    if(k%2) {
        cout<<"YES"<<endl;
        for(ll i=1;i<=n;i+=2) {
            cout<<i<<" "<<i+1<<endl;
        }
    } else {
        ll no = n/4;
        bool ans = true;
        for(ll i=2;i<=n;i+=4) {
            if((i+k)%4==0) {
                
            } else {
                ans = false;
                break;
            }
        }
        if(ans) {
            cout<<"YES"<<endl;
            for(ll i=1;i<=n;i+=2) {
                if((i+1)%4==0) {
                    cout<<i<<" "<<i+1<<endl;
                } else {
                    cout<<i+1<<" "<<i<<endl;
                }
            }
        } else {
            cout<<"NO"<<endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}
