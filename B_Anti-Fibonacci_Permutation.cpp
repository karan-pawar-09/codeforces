/*
    author:Karan
    created:22.02.2022 20:12:45
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

bool isGood(int i,int j,int n,vector<int> &ar) {
    bool one=false;
    bool two=false;
    swap(ar[i],ar[j]);
    for(int k=2;k<n;k++) {
        if(ar[k-2]+ar[k-1]==ar[k]) {
            swap(ar[i],ar[j]);
            return false;
        }
    }
    swap(ar[i],ar[j]);
    return true;
}
void solve() {
    int n;
    cin>>n;
    set<vector<int>> s;
    vector<int> ar(n);
    for(int i=0;i<n;i++) {
        ar[i]=n-i;
    }
    while(s.size()<n) {
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(isGood(i,j,n,ar)) {
                    swap(ar[i],ar[j]);
                    s.insert(ar);
                }
            }
        }
    }
    int k=0;
    for(auto x:s) {
        for(auto y:x) {
            cout<<y<<" ";
        }
        cout<<endl;
        k++;
        if(k>=n) {
            break;
        }
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