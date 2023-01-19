/*
    author:Karan
    created:18.01.2023 21:33:01
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

ll find(vector<ll> arr) {
    ll n = arr.size();
    stack<ll> str, stl;
    set<ll> ans;
    ll maxi = 0;
    if(arr[n-1] > arr[n-2]) {
        stl.push(arr[n-2]);
        maxi = arr[n-1];
        ans.insert(arr[n-1]- arr[n-2]);
    } else {
        str.push(arr[n-1]);
        maxi = arr[n-2];
        ans.insert(arr[n-2] - arr[n-1]);
    }
    for(int i=n-3;i>=0;i--) {
        if(arr[i] >= maxi) {
            ans.insert(arr[i] - maxi);
            while(stl.size()) {
                ans.insert(arr[i] - stl.top());
                stl.pop();
            }
            maxi = arr[i];
        } else {
            while(stl.size() && arr[i] >= stl.top()) {
                ans.insert(arr[i] - stl.top());
                stl.pop();
            }
            if(stl.size()) {
                ans.insert(stl.top() - arr[i]);
            } else {
                ans.insert(maxi - arr[i]);
            }
            stl.push(arr[i]);
        }
    }
   return ans.size();
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout<<find(arr)<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}