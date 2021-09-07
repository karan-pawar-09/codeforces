#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int w,h,n;
        cin>>w>>h>>n;
        ll ans=1;
        while(w%2==0) {
            w/=2;
            ans*=2;
        } 
        while(h%2==0) {
            h/=2;
            ans*=2;
        }
        // cout<<ans<<endl;
        if(ans>=n) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
}