#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    if(n<4) {
        if(n==1) {
            cout<<"1"<<endl;
        }
        else {
            cout<<"NO SOLUTION"<<endl;
        }
    }
    else {
        for(int i=2;i<=n;i+=2) {
            cout<<i<<" ";
        }
        for(int i=1;i<=n;i+=2) {
            cout<<i<<" ";
        }
    }
}