/*
    author:Karan
    created:30.08.2022 22:02:21
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
    vector<int> ans;
    int xor1 =0;
    int xor2 =0;
    for(int i=1;i<n;i++) {
        ans.push_back(i);
        if(i%2) {
            xor1 ^=i;
        } else {
            xor2 ^=i;
        }
    }
    
    ans.push_back((xor1^xor2));
    int a = 0;
    int b = 0;
    for(int i=0;i<ans.size();i++) {
    cout<<ans[i]<<" ";
    if(i%2) {
        a ^= ans[i];
    } else {
        b ^= ans[i];
    }
    }
    assert(a == b);
    assert(ans.size() == n);
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

Batman