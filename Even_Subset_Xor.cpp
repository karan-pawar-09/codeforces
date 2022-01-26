/*
    author:Karan
    created:19.01.2022 20:26:50
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

const int mx=1048579;
int arr[mx];
void solve() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int x=0;
    for(int i=3;i<mx;i++) {
        if(__builtin_popcount(i)%2==0) {
            arr[x]=i;
            x++;
        }
    }
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}