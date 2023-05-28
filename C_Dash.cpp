/*
    author:Karan
    created:27.05.2023 17:42:24
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
    ll n, m, h, k;
    cin >> n >> m >> h >> k;
    ll x = 0;
    ll y = 0;
    string s;
    cin >> s;
    set<pair<ll, ll>> st;
    for(ll i=0;i<m;i++) {
        ll a, b;
        cin>>a>>b;
        st.insert({a, b});
    }

    for(ll i=0;i<n;i++) {
        h--;
        if(s[i]=='R') {
            x++;
        } else if(s[i]=='L') {
            x--;
        } else if(s[i]=='U') {
            y++;
        } else if(s[i]=='D') {
            y--;
        }
    
        
        if(h < 0) {
            cout<<"No"<<endl;
            return;
        }
        
        
        if(st.find({x, y}) != st.end()) {
            if(h < k) {
                h = k;
                st.erase({x, y});
            }
        }
        //cout<<i<<" "<<x<<" "<<y<<" "<<h<<endl;
        
    }
    cout<<"Yes"<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    
    while(t--) {
        solve();
    }
}


/*

-1 0
-1 -1


*/