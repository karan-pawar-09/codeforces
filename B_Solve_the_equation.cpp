#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'


ll sumk(ll k) {
    string s=to_string(k);
    ll ss=0;
    for(int i=0;i<s.size();i++) {
        ss+=(s[i]-'0');
    }
    return ss;
}
ll power(ll a,ll b) {
    ll ans=1;
    for(int i=0;i<b;i++){
        ans*=a;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x,y,z;
    cin>>x>>y>>z;
    vector<ll> ans;
    ll total=0;
    for(ll i=0;i<82;i++) {
        ll k=y*(power(i,x))+z;
        if(k>0&&k<(ll)1e9) {
            if(sumk(k)==i) {
                total++;
                ans.push_back(k);
            }
        }
        
    }
    cout<<total<<endl;
    for(int i=0;i<total;i++) {
        cout<<ans[i]<<" ";
    }
}

