/*
author:Karan
created:31.05.2021 12:22:40
*/
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
        int n;
        cin>>n;
        vector<ll> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        int ans=3*n;
        cout<<ans<<endl;
        for(int i=1;i<=n;i+=2) {
            cout<<"2 "<<i<<" "<<i+1<<endl;
        }
        for(int i=1;i<=n;i+=2) {
            cout<<"1 "<<i<<" "<<i+1<<endl;
            cout<<"1 "<<i<<" "<<i+1<<endl;
        }
        for(int i=1;i<=n;i+=2) {
            cout<<"2 "<<i<<" "<<i+1<<endl;
        }
        for(int i=1;i<=n;i+=2) {
            cout<<"1 "<<i<<" "<<i+1<<endl;
            cout<<"1 "<<i<<" "<<i+1<<endl;
        }
    }
}