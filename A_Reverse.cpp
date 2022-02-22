/*
    author:Karan
    created:14.02.2022 20:38:52
*/
#if true
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define mset(a,x) memset(a,x,sizeof(a))
#endif

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int start=0;
    for(int i=0;i<n;i++) {
        if(arr[i]!=(i+1)) {
            start=i;
            break;
        }
    }
    int end=0;
    int val=arr[start];
    for(int i=start;i<n;i++) {
        if(arr[i]<val) {
            val=arr[i];
            end=i;
        }
    }
    // cout<<start<<" "<<end<<endl;
    for(int i=start;i<=(start+end)/2;i++) {
        swap(arr[i],arr[end-i+start]);
    }
    for(auto x:arr) {
        cout<<x<<" ";
    } cout<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}