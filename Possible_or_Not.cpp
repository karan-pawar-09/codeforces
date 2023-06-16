/*
    author:Karan
    created:14.06.2023 20:05:44
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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    int andd = arr[0];
    set<int> st;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        bool bad = false;
        for(int j = 0; j < 31; j++) {
            if((k & (1 << j)) && !(arr[i]&(1 << j))) {
                bad = true;
            }
        }
        if(!bad) {
            st.insert(arr[i]);
        }
    }

    int res = 0;
    for(auto x: st) {
        for(int i = 0; i<31;i++) {
            if(!(x & (1 << i))) {
                res |= (1 << i);
            }
        }
    }
    for(int i = 0; i < 31; i++) {
        if(true) {
            if(!(k & (1<<i))) {
                if(res & (1<<i)) {

                } else {
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"YES"<<endl;
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