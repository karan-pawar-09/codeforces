/*
    author:Karan
    created:20.02.2022 17:50:45
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
    int res=0;
    stack<pair<int,int>> s;
    s.push({-1,0});
    for(int i=0;i<n;i++) {
        if(s.top().first!=arr[i]) {
            s.push({arr[i],1});
            res++;
        } else {
            s.top().second++;
            res++;
            if(s.top().second==s.top().first) {
                res-=s.top().first;
                s.pop();
            }
        }
        cout<<res<<endl;
    }
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