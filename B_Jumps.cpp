#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int x;
        cin>>x;
        int ans=1;
        while((ans*(ans+1))/2<x) {
            ans++;
        }
        if((ans*(ans+1))/2==x+1) {
            ans++;
        }
        cout<<ans<<endl;
    }
}