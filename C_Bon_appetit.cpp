/*
    author:Karan
    created:25.01.2023 20:28:59
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

ll binarysearch1(vector<ll> &a, ll k) {
    ll r = a.size()-1;
    ll l = -1;
    while(l+1 < r) {
        ll m = (l+r)/2;
        if(a[m] >= k) {
            r = m;
        } else {
            l = r;
        }
    }
    if(a[r] < k) {
        return -1;
    } else {
        return r;
    }
}

ll binarysearch(vector<ll> &arr, ll k) {
    ll i = 0;
    ll j = arr.size();
    while(i+1 < j) {
        ll m = (i+j)/2;
        if(arr[m] >= k) {
            i = m;
        } else {
            j = m;
        }
    }
    return i;
}
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    map<ll, ll> M;
    for(ll i=0;i<n;i++) {
        cin>>a[i];
        M[a[i]]++;
    }
    for(ll j=0;j<m;j++) {
        cin>>b[j];
    }
    vector<ll> arr;
    for(auto x: M) {
        arr.push_back(x.second);
    }
    priority_queue<ll> st;
    for(auto x: arr) {
        st.push(x);
    }
    sort(all(b), greater<ll> ());
    ll ans = 0;
    while(st.size()) {
        ll p = st.top();
        st.pop();
        ll indx = binarysearch(b, p);
        if(b[indx] >= p) {
            ans += p;
            b[indx] = -1;
        } else {
            if(b[indx] <= 0) {

            } else {
                p -= b[indx];
                ans += b[indx];
                b[indx] = 0;
                st.push(p);
            }
        }
        sort(all(b), greater<ll>());
    }
    
    cout<<ans<<endl;

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