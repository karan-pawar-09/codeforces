#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll lastzero=-1;
    ll firstone=-1;
    ll totalzeros=0;
    ll totalones=0;
    vector<ll>left(n);
    vector<ll>right(n);
    for(int i=0;i<n;i++) {
        if(s[i]=='1') {
            totalones++;
        }
        left[i]=totalones;
    }
    for(int i=n-1;i>=0;i--) {
        if(s[i]=='0') {
            totalzeros++;
        }
        right[i]=totalzeros;
    }
    ll ans=(ll)1e18+5;
    for(int i=1;i<n;i++) {
        ans=min(ans,left[i-1]+right[i]);
    }
    cout<<min({ans,totalones,totalzeros})<<endl;        
}   