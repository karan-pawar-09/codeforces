#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        int z=1;
        for(int i=n-k+1;i<k;i++) {
            cout<<z<<" ";
            z++;
        }
        for(int i=0;i<=(n-k);i++) {
            cout<<k-i<<" ";
        }
        cout<<endl;
    }
}       