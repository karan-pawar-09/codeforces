/*
    author:Karan
    created:10.06.2022 23:06:49
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
    set<int> s;
    for(int i=0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }
    if(n == 1) {
        cout<< -1 << endl; 
        return ;
    }
    vector<int> ans(n);
    for(int i=0;i<n;i++) {
        int temp;
        for(auto x:s) {
            if(arr[i]!=x) {
                ans[i]=x;
                temp=x;
                break;
            }
        }
        s.erase(temp);
    }
    if(ans[n-1] == 0) {
        ans[n-1] = ans[n-2];
        ans[n-2] = *s.begin();
    }
    for(auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
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