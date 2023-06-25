/*
    author:Karan
    created:25.06.2023 15:25:39
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
    cin >> n;
    vector<int> arr(n);
    set<int> st;
    st.insert(61);
    st.insert(59);
    st.insert(55);
    st.insert(53);
    st.insert(47);
    for(int i =0; i < n;i++) {
        cin >> arr[i];
    }
    int res = 0;
    for(int i =0; i < n; i++) {
        if(st.count(arr[i])) {
            res += arr[i];
        } else {
            res -= arr[i];
        }
        cout<<res<<endl;
    }
    vector<bool> dp(500, false);
    dp[0] = true;
    for(int i =0; i < n; i++) {
        for(int j = 499; j >= 0; j--) {
            if(dp[j]) {
                if((j + arr[i]) < 500) {
                    dp[j + arr[i]] = true;
                }
            }
        }
    }

    //cout<<dp[275]<<endl;
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