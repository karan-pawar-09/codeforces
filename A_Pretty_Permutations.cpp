/*
author:Karan
created:25.06.2021 21:06:41
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
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        if(n%2) {
            cout<<3<<" "<<1<<" "<<2<<" ";
            for(int i=4;i<=n;i++) {
                if(i%2) {
                    cout<<i-1<<" ";
                }
                else {
                    cout<<i+1<<" ";
                }
            }
        }
        else {
            for(int i=1;i<=n;i++) {
                if(i%2) {
                    cout<<i+1<<" ";
                }
                else {
                    cout<<i-1<<" ";
                }
            }
        }
        cout<<endl;
    }
   
}