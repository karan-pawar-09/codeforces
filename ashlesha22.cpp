/*
    author:Karan
    created:08.04.2023 16:22:51
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

bool isGood(int n, vector<int> &d) {
    string s = to_string(n);
    for(auto x: s) {
        for(auto y: d) {
            if(y == (x-'0')) {
                return false;
            }
        }
    }
    return true;
}
int findYear(int n, vector<int> d) {
    int k = d.size();
    for(int i=n; i<=10*n;i++) {
        if(isGood(i, d)) {
            return i;
        }
    }
    return 0;
}
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(k);
    for(int i=0;i<k;i++) {
        cin >> arr[i];
    }
    cout<<findYear(n, arr)<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}

/*
    author:Karan
    created:19.05.2023 04:18:08
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