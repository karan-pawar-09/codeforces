#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

string solve(string a,string b,ll n) {
    string ans=a;
    ll k=0;
    for(ll i=0;i<2*n;i++) {
        if(ans[i]==b[k]) {
            k++;
        }
    }
    for(ll i=k;i<2*n;i++) {
        ans+=b[i];
    }
    return ans;
} 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        string a,b,c;
        cin>>a>>b>>c;
        string ans;
        ans=solve(a,b,n);
        if(ans.size()<=3*n) {
            cout<<ans<<endl;
            continue;
        }
        ans=solve(a,c,n);
        if(ans.size()<=3*n) {
            cout<<ans<<endl;
            continue;
        }
        ans=solve(b,a,n);
        if(ans.size()<=3*n) {
            cout<<ans<<endl;
            continue;
        }
        ans=solve(b,c,n);
        if(ans.size()<=3*n) {
            cout<<ans<<endl;
            continue;
        }
        ans=solve(c,a,n);
        if(ans.size()<=3*n) {
            cout<<ans<<endl;
            continue;
        }
        ans=solve(c,b,n);
        cout<<ans<<endl;
    }
}