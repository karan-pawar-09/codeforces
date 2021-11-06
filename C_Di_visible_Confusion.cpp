/*
    author:Karan
    created:31.10.2021 12:11:51
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
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    for(int i=0;i<n;i++) {
        bool ok=false;
        for(int j=i+2;j>=2;j--) {
            if(arr[i]%j) {
                ok=true;
                break;
            }
        }
        if(!ok) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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