/*
    author:Karan
    created:12.11.2021 20:36:12
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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    // bool ans=false;
    // for(ll i=1;i<n;i++) {
    //     if(s[i]==s[i-1] and s[i]=='a') {
    //         ans=true;
    //         break;
    //     }
    // }
    // if(ans) {
    //     cout<<2<<endl;
    // }
    // else {            
    //     for(ll i=2;i<n;i++) {
    //         if(s[i]==s[i-2] and s[i]=='a') {
    //             ans=true;
    //             break;
    //         }
    //     }
    //     if(ans) {
    //         cout<<3<<endl;
    //     }
    //     else {                       
    //         for(int i=3;i<n;i++) {
    //             if(s[i]==s[i-3] and s[i-1]!=s[i-2] and s[i]=='a') {
    //                 ans=true;
    //                 break;
    //             }
    //         }
    //         if(ans) {
    //             cout<<4<<endl;
    //         }
    //         else cout<<-1<<endl;            
    //     }        
    // }
    bool ans=false;
    int mini=1e9;
    for(int i=0;i<n;i++) {
        vector<ll> freq(3,0);
        freq[s[i]-'a']++;
        for(int j=i+1;j<n and j<(i+100);j++) {
            freq[s[j]-'a']++;
            if(freq[0]>freq[1] and freq[0]>freq[2]) {
                mini=min(mini,j-i+1);
                ans=true;
            }
        }
    }
    if(ans) {
        cout<<mini<<endl;
    }
    else {
        cout<<-1<<endl;
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