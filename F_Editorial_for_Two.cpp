/*
    author:Karan
    created:28.05.2023 17:56:44
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

bool check(vector<ll> &arr, ll m, ll k) {
    //Initiating variables
    ll n = arr.size();
    priority_queue<ll> pq;
    vector<ll> L(n+1), R(n+1);
    ll sum = 0;
    L[0] = 0;

    // Prefix
    for(ll i = 0; i < n; i++) {
        sum += arr[i];
        pq.push(arr[i]);
        if(sum > m) {
            sum -= pq.top();
            pq.pop();
        }
        L[i+1] = pq.size();
    }

    //clearing variables
    while(pq.size()) pq.pop();
    sum = 0;
    R[n] = 0;

    //suffix
    for(ll i=n-1;i>=0;i--) {
        sum += arr[i];
        pq.push(arr[i]);
        if(sum > m) {
            sum -= pq.top();
            pq.pop();
        }
        R[i] = pq.size();
    }

    // Checking
    for(ll i=0;i<=n;i++) {
        if((L[i]+R[i]) >= k) {
            return true;
        }
    }
    return false;
}

ll binarysearch(vector<ll> &arr, ll k) {
    ll l = 0;
    ll r = 1e15+10;
    while(l+1 < r) {
        ll m = l + (r - l)/2;
        if(check(arr, m, k)) {
            r = m;
        } else {
            l = m;
        }
    }
    return r;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout<<binarysearch(arr, k)<<endl;
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