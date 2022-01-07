/*
    author:Karan
    created:03.01.2022 20:05:24
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

int ceil(int a, int b) {
    return (a+b-1)/b;
}
void solve() {
    int n,k;
    cin>>n>>k;
    int p=ceil(n,2);
    if(p>=k) {
        int cnt=k;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i==j and i%2==0 and cnt>0) {
                    cout<<'R';
                    cnt--;
                } else {
                    cout<<".";
                }                
            }
            cout<<endl;
        }
    } else {
        cout<<-1<<endl;
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