/*
    author:Karan
    created:07.11.2021 17:35:20
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

const ll mx=(ll)2e5+10;
vector<ll> arr[mx];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n;
    cin>>n;
    ll sum=0;
    vector<ll> t(n);   
    for(ll i=0;i<=n;i++) {
        arr[i].clear();
    }
    queue<ll> q;
    for(ll i=0;i<n;i++) {
        cin>>t[i];
        ll k;
        cin>>k;
        for(ll j=0;j<k;j++) {
            ll b;
            cin>>b;
            b--;
            arr[i].push_back(b);
            if(i==n-1) {
                q.push(b);
            }
        }
    }
    set<ll> s;
    while(q.size()) {
        ll p=q.front();
        q.pop();
        s.insert(p);
        for(auto i:arr[p]) {
            if(s.find(i)==s.end()) {
                q.push(i);
            }
        }
    }
    ll res=t[n-1];
    for(auto x:s) {
        res+=t[x];
    }
    cout<<res<<endl;
}