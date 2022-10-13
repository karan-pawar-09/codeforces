/*
    author:Karan
    created:06.09.2022 12:25:46
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

const long long MOD = 1e9+7;

static bool comparator( vector<int>& a, vector<int>& b ) {
        return a[0] < b[0];
}
    
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    if( intervals.empty()) {
        return res;
    }
    if( intervals.size() == 1 ) {
        res.push_back( intervals[0]);
        return res;
    }
    sort( intervals.begin(), intervals.end(), comparator );
    res.push_back( intervals[0] );
    int i = 1;
    while( i < intervals.size() ) {
        vector<int>& last = res.back();
        if( last[1] < intervals[i][0] ) {
            res.push_back( intervals[i] );
        }
        else {
            last[1] = max( last[1], intervals[i][1] );
        }
        i++;
    }
    return res;
}
long long sub(long long a, long long b) {
    return (a-b+MOD)%MOD;
}
long long POW(long long x, long long y, long long p) {
    long long res = 1;
    while (y > 0) {
        if (y % 2 == 1)
            res = (res * x);
        y = y >> 1;
        x = (x * x);
    }
    return res % p;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> input(n, vector<int> (2));
    for(long long i=0;i<n;i++) {
        cin>>input[i][0]>>input[i][1];
    }
    long long k = merge(input).size();
    cout<<sub(POW(2, k, MOD), 2)<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    long long t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}