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
        vector<ll> B(n);
        for(int i=0;i<n;i++) {
            cin>>B[i];
        }
        ll sum=0;
        vector<ll> A(n);
        for(int i=0;i<n;i++) {
            A[i]=B[i]*(i+1)-sum;
            sum+=A[i];
        }
        for(int i=0;i<n;i++) {
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }
}