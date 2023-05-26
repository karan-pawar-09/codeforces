/*
    author:Karan
    created:28.01.2023 18:01:55
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
    string a, b;
    cin>>a>>b;
    vector<bool> dpstart(a.size(), false);
    vector<bool> dpend(a.size(), false);
    if(a[0] == b[0] || a[0] =='?' || b[0] == '?') {
        dpstart[0] = true;
    }
    for(int i=1;i<b.size();i++) {
        if(b[i] == a[i] || a[i] == '?' || b[i]=='?') {
            dpstart[i] = dpstart[i-1];
        } else {
            dpstart[i] = false;
        }
    }
    int j = a.size()-1;
    if(a.back() == b.back() || a.back() == '?' || b.back() == '?') {
        dpend[j] = true;
    }
    j--;
    for(int i=b.size()-2;i>=0;i--) {
        if(a[j]==b[i] || b[i]=='?' || a[j] =='?') {
            dpend[j] = dpend[j+1];
        } else {
            dpend[j] = false;
        }
        j--;
    }
    int p = a.size()-b.size();
  
    int abc = p;
    int q = 0;
    p++;
    if(dpend[p]) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }
    for(int i=q;i<b.size()-1;i++) {
        if(dpstart[i] && dpend[p]) {
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
        p++;
    }
    if(dpstart[b.size()-1]) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}

const ll mod=(ll)1e9+7;

ll power(long long x, unsigned ll y, ll mod) {
    ll res = 1; 
    x = x % mod;   
    if (x == 0) return 0;  
    while (y > 0) {        
        if (y & 1)
            res = (res*x) % mod; 
        y = y>>1;
        x = (x*x) % mod;
    }
    return res;
}