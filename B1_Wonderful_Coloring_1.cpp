/*
author:Karan
created:23.07.2021 20:11:18
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        ll n=(ll) s.size();
        vector<ll> used(26,0);
        for(ll i=0;i<n;i++) {
            used[s[i]-'a']++;
        }
        ll no=0;
        ll pair=0;
        for(ll i=0;i<26;i++) {
            if(used[i]==1) {
                no++;
            }
            else if(used[i]>1) {
                pair++;
            }
        }
        cout<<pair+(no/2)<<endl;
    }
}