/*
    author:Karan
    created:26.03.2023 20:24:27
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
    ll m;
    cin >> m;
    multiset<ll> s;
    vector<ll> arr[m];
    for(ll _ = 0; _ < m; _++) {
        ll n;
        cin >> n;
        ll a;
        for(ll i=0;i<n;i++) {
            cin >> a;
            arr[_].push_back(a);
            s.insert(a);
        }
    }
    vector<ll> answer;
    for(ll _ = 0; _ < m; _++) {
        bool ans = false;
        ll no = -1;
        for(ll i=0;i<arr[_].size();i++) {
            s.erase(s.find(arr[_][i]));
            if(s.find(arr[_][i]) == s.end()) {
                no = arr[_][i];
                ans = true;
            }
        }
        if(ans)
            answer.push_back(no);
        else {
            cout<<-1<<endl;
            return;
        }
    }
    for(auto x: answer) {
        cout<<x<<" ";
    }
    cout<<endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}