/*
author:Karan
created:22.07.2021 20:09:29
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
    ll q;
    cin>>q;
    while(q--) {
        string s,t;
        cin>>s;
        cin>>t;
        ll n=s.size();
        ll m=t.size();
        bool ans=false;
        string temp1;
        string temp2;
        for(ll i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                temp1=s.substr(i,j-i+1);
                int rem=m-j+i-1;
                if(rem<0) {
                    break;
                }
                int newstart=j-rem;
                if((newstart>=0)&&(newstart<=j)) {
                    temp2=s.substr(newstart,rem);
                    reverse(all(temp2));
                    temp1+=temp2;
                    if(temp1==t) {
                        ans=true;
                        break;
                    }
                }                
                if(ans) break;
            }
            if(ans) break;
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}