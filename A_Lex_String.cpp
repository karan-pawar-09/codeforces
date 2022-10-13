/*
    author:Karan
    created:10.06.2022 23:20:23
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
    int n,m,k;
    cin >> n >> m >> k;
    string a,b;
    cin >> a;
    cin >> b;
    multiset<char> sa, sb;
    int na, nb;
    na = k;
    nb = k;
    for(int i=0; i<n; i++) {
        sa.insert(a[i]);
    }
    for(int i=0; i<m; i++) {
        sb.insert(b[i]);
    }
    string ans;
    while((sa.size() && sb.size())) {
        char aa = '{';
        char bb = '{';
        aa = *sa.begin();
        bb = *sb.begin();
        if(aa <= bb) {
            if(na>0) {
                ans.push_back(aa);
                sa.erase(sa.find(aa));
                na--;
                nb=k;
            } else {
                ans.push_back(bb);
                sb.erase(sb.find(bb));
                nb--;
                na=k;
            }
        } else {
            if(nb>0) {
                ans.push_back(bb);
                sb.erase(sb.find(bb));
                nb--;
                na=k;
            } else {
                ans.push_back(aa);
                sa.erase(sa.find(aa));
                na--;
                nb=k;
            }
        }
    }
    cout<<ans<<endl;
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