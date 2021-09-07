#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int k;
    sort(arr.begin(),arr.end());
    cin>>k;
    while(k--) {
        int a,b;
        cin>>a>>b;   
        int l=-1;
        int r=n;
        while(r>l+1) {
            int m=l+(r-l)/2;
            if(arr[m]<a) {
                l=m;
            }
            else {
                r=m;
            }
        }
        int i=r;
        l=-1;
        r=n;
        while(r>l+1) {
            int m=l+(r-l)/2;
            if(arr[m]<=b) {
                l=m;
            }
            else {
                r=m;
            }
        }
        int j=l;
        cout<<j-i+1<<" ";    
    }
}