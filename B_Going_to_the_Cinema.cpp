/*
    author:Karan
    created:15.01.2023 17:49:06
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

bool binarysearch(vector<int> &arr, int x) {
    int n = arr.size();
    int l = -1;
    int r = n-1;
    while(l+1 < r) {
        int m = l+(r-l)/2;
        if(arr[m] >= x) {
            r = m;
        } else {
            l = m;
        }
    }
    int res1 = n;
    if(arr[r] > x) {
        res1 = r;
    }
    l = 0;
    r = n;
    while(l+1 < r) {
        int m = l+(r-l)/2;
        if(arr[m] < x) {
            l = m;
        } else {
            r = m;
        }
    }
    int res2 = -1;
    if(arr[l] < x) {
        res2 = l;
    }
    if(res2 >= res1-1 && (x == res1)) {
        //cout<<x<<" "<<res1<<" "<<res2<<endl;
        return true;
    } else {
        return false;
    }
}

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    sort(all(arr));
    int ans = 0;
   // cout<<"START"<<endl;
    for(int i=0; i<= n;i++) {
        ans += binarysearch(arr, i);
    }
    //cout<<"END"<<endl;
    cout<<ans<<endl;
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