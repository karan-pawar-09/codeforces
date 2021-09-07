/*
author:Karan
created:04.07.2021 11:51:54
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
        ll n,a,b;
        cin>>n>>a>>b;
        bool ans=false;        
        if(a!=1) {
            ll k=1;
            while(k<=n) {
                if((n-k)%b==0) {
                    ans=true;
                    break;
                }
                k*=a;
            }
        }
        else {
            if((n-1)%b==0) ans=true;
            else ans=false;
        }       
        ans?cout<<"Yes"<<endl:cout<<"No"<<endl;
    }

}

