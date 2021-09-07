#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    int ans=0;
    for(int i=0;i<n;i++) {
       cin>>arr[i];
    }
    int max=ceil((double)arr[0]/m);
    for(int i=0;i<n;i++) {
        if(ceil((double)arr[i]/m)>=max) {
            max=ceil((double)arr[i]/m);
            ans=i;
        }
    }
    cout<<ans+1<<endl;
}