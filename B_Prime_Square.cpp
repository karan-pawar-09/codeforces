#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin>>n;
    if(n%2==1) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i==j||i+j==n-1) {
                    cout<<"1"<<" ";
                }
                else if((i==n/2&&(j==0||j==n-1))||(j==n/2&&(i==0||i==n-1))) {
                    cout<<"1"<<" ";
                }
                else {
                    cout<<"0"<<" ";
                }
            }
            cout<<endl;
        }
    }
    else{
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i==j||i+j==n-1) {
                    cout<<"1"<<" ";
                }
                else {
                    cout<<"0"<<" ";
                }
            }
            cout<<endl;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}