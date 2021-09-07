/*
author:Karan
created:18.08.2021 20:12:49
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
        ll a,b,c;
        cin>>a>>b>>c;
        ll no=abs(a-b)*2;
        if((c>no)||(a>no)||(b>no)) {
            cout<<-1<<endl;
        }
        else {
            if(c<=no/2) {
                cout<<c+(no/2)<<endl;
            }
            else {
                cout<<c-(no/2)<<endl;
            }
        }
    }
}