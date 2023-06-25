/*
    author:Karan
    created:24.06.2023 19:36:05
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    multiset<int> qa, qb;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        qa.insert(a[i]);
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
        qb.insert(b[i]);
    }
    bool k = true;
    while(qa.size() && qb.size()) {
        if(k) {
            int one = *qa.rbegin();
            int temp = one;
            int two = *qb.begin();
            qa.erase(qa.find(one));
            qb.erase(qb.begin());
            one -= two;
            two -= temp;
            if(one > 0) {
                qa.insert(one);
            }
            if(two > 0) {
                qb.insert(two);
            }
        } else {
            int one = *qa.begin();
            int temp = one;
            int two = *qb.rbegin();
            qa.erase(qa.begin());
            qb.erase(qb.find(two));
            one -= two;
            two -= temp;
            if(one > 0) {
                qa.insert(one);
            }
            if(two > 0) {
                qb.insert(two);
            }
        }
        k = !k;   
    }
    if(qa.size()) {
        cout<<"Tsondu"<<endl;
    } else if(qb.size()) {
        cout<<"Tenzing"<<endl;
    } else {
        cout<<"Draw"<<endl;
    }
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