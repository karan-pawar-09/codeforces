/*
    author:Karan
    created:16.08.2022 21:00:23
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
    int zeros = 0;
    vector<bool> a(n,false);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        if(arr[i]==0) {
            a[i] = true;
        }
    }
    vector<int> xorr(n);
    xorr[0]=arr[0];
    for(int i=1;i<n;i++) {
        xorr[i]=arr[i]^xorr[i-1];
    }
    map<int, int> last;
    last[0]=-1;
    int used = -1;
    int ans = n;
    for(int i=0;i<n;i++) {
        if(last.count(xorr[i]) && last[xorr[i]]>=used) {
            ans--;
            used = i;
        }
        last[xorr[i]]=i;
    }
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