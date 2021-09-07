#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ti;
    cin>>ti; 
    while(ti--) {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll t=0;
        ll m=0;
        bool ans=true;
        for(ll i=0;i<n;i++) {
            s[i]=='T'?t++:m++;
            if(t<m) {
                ans=false;
            }
        }        
        reverse(all(s));
        t=0;
        m=0;
        for(ll i=0;i<n;i++) {
            s[i]=='T'?t++:m++;
            if(t<m) {
                ans=false;
            }
        } 
        if(t==2*m) {
            
        }
        else {
            ans=false;
        }
      if(ans) {
          cout<<"YES"<<endl;
      }
      else {
          cout<<"NO"<<endl;
      }
    }
}