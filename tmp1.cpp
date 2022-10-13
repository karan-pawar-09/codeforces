/*
    author:Karan
    created:26.07.2022 09:35:55
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

int ans(vector<double> temp) {
    int len = 0;
    int res = 0;
    for(int i=0; i<temp.size(); i++) {
        if(temp[i]>=25) {
            len++;
            if(len>=5) {
                res = max(res, len);
            }
        } else {
            len = 0;
        }
    }
    for(int i = 0; i<temp.size(); i++) {
        if(temp[i]>=30) {
            len++;
            if(len>=3) {
                res = max(res, len);
            } else {
                len = 0;
            }
        }
    }
    return res;
}

void solve() {
    int n;
    cin>>n;
    vector<double> temp(n);
    for(int i=0; i<n; i++) {
        cin>>temp[i];
    }
    cout<<ans(temp)<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}