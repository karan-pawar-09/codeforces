/*
    author:Karan
    created:10.09.2021 16:52:24
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    map<int,int> M;
    map<int,int> count;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        M[arr[i]]++;
    }
    for(int i=0;i<n;i++) {
        if(arr[i] != arr[i]^x) {
            arr[i]^=x;
            M[arr[i]]++;
            count[arr[i]]++;
        }
    }
    int ans=0;
    int cnt=0;
    for(auto x:M) {
        if(x.second>=ans) {
            if(x.second>ans) {
                cnt=count[x.first];
            }
            else {
                cnt=min(cnt,count[x.first]);
            }
            ans=x.second;
        }
    }
    cout<<ans<<" "<<cnt<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}