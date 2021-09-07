#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    while(k--) {
        int x;
        cin>>x;
        int l=-1;
        int r=n;
        while(r>l+1) {
            int m=l+(r-l)/2;
            if(arr[m]<x) {
                l=m;
            }
            else {
                r=m;
            }
        }
      cout<<r+1<<endl;
    }
}