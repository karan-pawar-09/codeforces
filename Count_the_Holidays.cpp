/*
    author:Karan
    created:02.03.2022 20:00:54
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
    int n;
    cin>>n;
    vector<int> a(n);
    int ans=0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        a[i]--;
        if(a[i]%7==5 or a[i]%7 ==6) {

        } else {
            ans++;
        }
    }
    cout<<8+ans<<endl;
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

// 1 2 3 4 5 6 7
// M T W T F S S
// 8 9 10 11 12 13
// 14 15 16 17 18 19
// 20 21 22 23 24 25 26
// 27 28 29 30