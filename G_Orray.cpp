/*
    author:Karan
    created:13.10.2022 20:40:20
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
    res = 0;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int xorr = 0;
    int index = -1;
    int val = 0;
    for(int i=0;i<n;i++) {
        val = 0;
        index = -1;
        for(int j=i;j<n;j++) {
            if((arr[j] - (arr[j]&xorr)) > val) {
                val = (arr[j] - (arr[j]&xorr));
                index = j;
            }
        }
        if(index == -1) {
            break;
        }
        xorr |= val;
        swap(arr[i], arr[index]);
    }
    for(auto x: arr) {
        cout<<x<<" ";
    }
    cout<<endl;
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
