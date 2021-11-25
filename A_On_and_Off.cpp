/*
    author:Karan
    created:20.11.2021 17:30:28
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
    int s,t,x;
    cin>>s>>t>>x;
    vector<bool> arr(24,false);
    int i=s;
    while(i!=t) {
        arr[i]=true;
        i++;
        i%=24;
    }
    arr[s]=arr[t]=true;
    if(arr[(x+1)%24]) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
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