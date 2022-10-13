/*
    author:Karan
    created:10.08.2022 20:46:51
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
    ll n, m;
    cin>>n>>m;
    string s;
    cin>>s;

    ll total =0;
        for(auto x: s) {
        if(x=='1') {
            total++;
        }
    }

    if(total == 0) {
        cout<<n*m<<endl;
        return;
    }

    if(m%2==0) {
        ll count = 0;
        for(ll i=0;i<n;i++) {
            if(s[i]=='0') count++;
            else break;
        }
        ll count2 = 0;
        for(ll i=n-1;i>=0;i--) {
            if(s[i]=='0') count2++;
            else break;
        }
        cout<<count+count2+1<<endl;
    } else {
        
        if(total%2) {
            cout<<0<<endl;
            return;
        }
        ll index = n;
        ll count = 0;
        for(ll i=0;i<n;i++) {
            if(count < (total/2)) {
                if(s[i]=='1') {
                    count++;
                    index = i;
                }
            }
        }
        ll res = 1;
        for(ll i=index+1;i<n;i++) {
            if(s[i]=='0') {
                res++;
            } else {
                break;
            }
        }
        cout<<res<<endl;
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

