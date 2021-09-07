#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll x,y;
        cin>>x>>y;
        string s;
        cin>>s;
        ll xp=0;
        ll yp=0;
        ll xn=0;
        ll yn=0;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='U') {
                yp++;
            }
            else if(s[i]=='D') {
                yn--;
            }
            else if(s[i]=='R') {
                xp++;
            }
            else {
                xn--;
            }        
        }
        if((xp>=x&&x>=xn)&&(yp>=y&&y>=yn)) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
}