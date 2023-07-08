/*
    author:Karan
    created:07.07.2023 20:37:48
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

long double area(ll b, ll h) {
    long double temp = (long double) b * (long double) h;
    temp /= (long double) 2;
    return temp;
}
long double area1(long double b, long double h) {
    long double temp = b * h;
    temp /= (long double) 2;
    return temp;
}
void solve() {
    ll n, b, h;
    cin >> n >> b >> h;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(all(arr));
    long double ans = 0;
    for(ll i = 0; i < n - 1; i++) {
        ans += area(b, h); 
        ll d = arr[i+1] - arr[i];
        if(d < h) {
            long double a = h - d;
            long double c = (long double) (a * b * 2) / ((long double)h * 2);
            ans -= area1(a, c);
        }
    }
    ans += area(b, h);
    cout<<fixed;
    cout<<setprecision(7);
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