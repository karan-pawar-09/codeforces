/*
    author:Karan
    created:08.01.2022 18:26:47
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
    ll x;
    cin>>x;
    set<ll> s;
    for(ll i=1;i<10;i++) {
        s.insert(i);
    }
    // for(ll i=2;i<=18;i++) {
    //     for(ll j=1;j<9;j++) {
    //         string ans;            
    //         for(ll k=0;(k+j)<10;k+=j) {
    //             ll dig=k+j;
    //             char c='0'+dig;
    //             ans+=c;
    //             if(ans.size()) {
    //                 s.insert(stoll(ans));
    //             }
    //         }            
    //     }
    // }
    ll p;
    for(ll i=0;i<10;i++) {
        string ans;
        for(int k=2;k<=18;k++) {             
            for(ll j=0;j<10;j++) {
                ans.clear();
                p=i;
                char c='0'+p;
                ans+=c;
                while(ans.size()<=k) {
                    s.insert(stoll(ans));
                    p+=j;
                    if(p>9) break;   
                    c='0'+p;
                    ans+=c;                 
                }            
            }
        }
    }
    s.insert(0);
    vector<ll> ar;
    for(auto xx:s) ar.push_back(xx);
    for(auto xx:ar) {
        string temp=to_string(xx);
        if(temp.size()>1) {
            reverse(all(temp));
            s.insert(stoll(temp));
            if(temp[temp.size()-2]-temp[temp.size()-1] == temp[temp.size()-1]-'0') {
                temp+="0";
                s.insert(stoll(temp));
            }
        }
    }
  
    cout<<*s.lower_bound(x);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}