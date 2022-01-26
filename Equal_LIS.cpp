/*
    author:Karan
    created:19.01.2022 20:54:22
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

ll ceil(ll a,ll b) {
    return (a+b-1)/b;
}

void solve() {
    ll n;
    cin>>n;
    if(n==2) {
        cout<<"NO"<<endl;
    }
    else {
        cout<<"YES"<<endl;        
        ll i=ceil(n,2);
        ll j=i;
        while(j>=1) {
            cout<<j<<" ";
            j--;
        }
        if(n%2==0) cout<<n<<" ";
        ll k=i+1;
        while(k<=n) {
            cout<<k<<" ";
            k++;
            if(k==n and n%2==0) break;
        }           
        cout<<endl;
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