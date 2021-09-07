/*
author:Karan
created:04.09.2021 21:42:25
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    ll t;
    cin>>t;
    ll a,x;
    multiset<ll> s;
    queue<ll> q;
      
    while(t--) {
            cin>>a;             
            if (a == 1) {
                cin >> x;
                q.push(x);
            }
            else if (a == 2) {
                if (!s.empty()) {
                    cout << *s.begin() <<endl;
                    s.erase(s.begin());
                }
                else {
                    cout << q.front() <<endl;
                    q.pop();
                }
            }
            else {
                while (!q.empty()) {
                    ll T = q.front();
                    q.pop();
                    s.insert(T);
                }
            }
        
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}