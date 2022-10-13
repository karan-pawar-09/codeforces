/*
    author:Karan
    created:13.10.2022 20:56:29
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
    vector<ll> s(200, 0);
    vector<ll> t(200, 0);
    ll n;
    cin>>n;
    s['a']++;
    t['a']++;
    bool oncefalse = false;
    for(ll xx=0;xx<n;xx++)  {
        ll a, b;
        cin>>a>>b;
        string c;
        cin>>c;
        if(a==1) {
            for(auto x: c) {
                s[x] += b;
            }
        } else {
            for(auto x: c) {
                t[x] += b;
            }
        }
        vector<ll> ss = s;
        vector<ll> tt = t;
        if(oncefalse) {
            cout<<"YES"<<endl;
            continue;
        }
        ll  i = 0;
        ll  j=149;
        bool given = false;
        while(i<=149 && j>=0) {
            if(tt[j] != 0 && ss[i] !=0) {
                if(i < j) {
                    given = true;
                    oncefalse = true;
                    cout<<"YES"<<endl;
                    break;
                }
                if(i > j) {
                    cout<<"NO"<<endl;
                    given = true;
                    break;
                }
            }
            ll mini = min(ss[i], tt[j]);
            ss[i] -= mini;
            tt[j] -= mini;
            if(ss[i] == 0) {
                i++;
            } 
            if(tt[j] == 0) {
                j--;
            }
        }
        if(!given) {
            ll suma =0;
            ll sumb = 0;
            int i = 1;
            for(auto x: ss) {
                suma += x;
            }
            i=1;
            for(auto x: tt) {
                sumb += x;
            }
            if(suma == 0) {
                if(sumb == 0) { 
                    cout<<"NO"<<endl;
                } else {
                    cout<<"YES"<<endl;
                }
            } 
            else if(sumb == 0) {
                if(suma == 0) {
                    cout<<"NO"<<endl;
                } else {
                    cout<<"NO"<<endl;
                }
            }
        }
    }
    bool ans = true;
    
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