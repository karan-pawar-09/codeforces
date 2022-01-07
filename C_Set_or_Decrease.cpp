/*
    author:Karan
    created:27.12.2021 21:42:15
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
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    if(n==1) {
        if(arr[0]<=k) {
            cout<<0<<endl;
        }
        else {
            cout<<arr[0]-k<<endl;
        }
    }
    else {
        int min=*min_element(all(arr));
        int sum=0;
        for(int i=0;i<n;i++) {
            sum+=(arr[i]-min);
        }
        int l=0;
        int r=1e9+7;
        while(l+1 < r) {
            int mid=l+(r-l)/2;
            if(sum+(mid*(n)) <= k) {
                l=mid;
            } else {
                r=mid;
            }
        }
        cout<<r<<endl;
    }
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