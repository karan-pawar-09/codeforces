#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        ll ans=0;
        ll cnt=0;
        for(int i=0;i<n;i++) {
            if(s[i]=='*') {
                cnt++;
            }
            else {
                cnt=0;
            }
            ans=max(ans,cnt);
        }
        
        if(ans>=k) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
}