/*
author:Karan
created:24.07.2021 11:06:52
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
        ll n,m,k;
        cin>>n>>m>>k;
        if(n%2) {
            int left=k;
            if(left>=m/2&&(k-(m/2))%2==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else if(m%2) {
            int left=n*m/2-k;
            if(left>=n/2&&(left-n/2)%2==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else {
            if(k%2) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
}

