/*
    author:Karan
    created:29.12.2022 10:48:41
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
    ll n;
    cin >> n;
    vector<ll> arr(n+1);
    vector<ll> pos(n+1);
    set<ll> s;
    
    for(ll i=1;i<=n;i++) {
        cin>>arr[i];
        pos[arr[i]] = i;
        if(arr[i] != i) {
            s.insert(arr[i]);
        }
    }
    ll count1 = 0;
    set<ll> s1 = s;
    s.clear();
    for(ll i=1;i<=n;i++) {
        if(arr[i] != (n-i +1)) {
            s.insert(i);
        }
    }
    ll common = 0;
    for(ll i = 1;i<=n;i++) {
        if(s.find(i) != s.end()) {
            if(s1.find(i) != s1.end()) {
                common++;
            }
        }
    }
    ll sizeone = s1.size();
    ll sizetwo = s.size();
    //cout<<endl;
    ll count2 = 0;
   count1 = sizeone;
   count2 = sizetwo;
    if(count1 <= count2-common) {
        cout<<"First"<<endl;
    } else if(count2 < count1-common) {
        cout<<"Second"<<endl;
    } else {
        cout<<"Tie"<<endl;
    }
    
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



