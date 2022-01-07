/*
    author:Karan
    created:29.12.2021 14:31:33
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
    set<int> s;
    int sum=0;
    for(int i=0;i<n;i++) {
        sum+=arr[i];
        s.insert(sum);
    }
    for(int i=1;i<=n;i++) {
        if(sum%i==0) {
            bool isGood=true;
            for(int j=1;j<=i;j++) {
                if(s.find((sum/i)*j)==s.end()) {
                    isGood=false;
                    break;
                }
            }
            if(isGood) {
                cout<<1;
            } else {
                cout<<0;
            }
        } else {
            cout<<0;
        }

    }
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