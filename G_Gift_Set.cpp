/*
author:Karan
created:10.06.2021 21:46:33
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        ll x,y,a,b;
        cin>>x>>y>>a>>b;
        if(x>y) swap(x,y);
        if(a>b) swap(a,b);
        ll xydiff=y-x;
        ll abdiff=b-a;
        if(a==b) {
            cout<<x/a<<endl;
        }
        else {
            ll temp=xydiff/abdiff;
            temp=min({temp,x/a,y/b});
            x-=temp*a;
            y-=temp*b;
            ll togather=x/(a+b);
            ll ans=temp;
            ans+=2*togather;
            x-=togather*(a+b);
            y-=togather*(a+b);
            ans+=min(x/a,y/b);
            cout<<ans<<endl;
        }
    }
}