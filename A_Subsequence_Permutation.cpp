/*
author:Karan
created:27.07.2021 21:15:17
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
    int q;
    cin>>q;
    while(q--) {
        int n;
        cin>>n;
        string s,t;
        cin>>s;
        t=s;
        sort(all(s));
        int ans=0;
        for(int i=0;i<n;i++) {
            if(s[i]!=t[i]) {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}