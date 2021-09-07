#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    int sum=0;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        sum+=arr[i];
    }
    if(sum==m) {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
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