/*
    author:Karan
    created:08.01.2022 17:56:01
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

ll binarysearch(ll a,vector<ll> &arr,ll n) {
    ll l=-1;
    ll r=n-1;
    while(l+1<r) {
        ll m=l+(r-l)/2;
        if(arr[m]>=a) {
            r=m;
        }
        else {
            l=m;
        }
    }
    return r;
}
void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    priority_queue<int, vector<int>, greater<int> > q;
    for(int i=0;i<k;i++) {
        q.push(arr[i]);
        
    }
    cout<<q.top()<<endl;
    for(ll i=k;i<n;i++) {
        if(arr[i]<=q.top()) {
            cout<<q.top()<<endl;
        }
        else {
            if(q.size())
                q.pop();
            q.push(arr[i]);
            cout<<q.top()<<endl;
        }
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}