/*
    author:Karan
    created:15.01.2023 17:39:55
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
    int w, d, h;
    cin >> w >> d >> h;
    int a, b, g, f;
    cin >> a >> b >> f >> g;
    int temp = h + g + b + abs(a-f);
    temp = min(temp, h + d-g + d-b + abs(a-f));
    temp = min(temp, h + a + f + abs(b-g));
    temp = min(temp, h + w-a + w-f + abs(b-g));
    cout<<temp<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}