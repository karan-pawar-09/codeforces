/*
    author:Karan
    created:23.02.2022 16:40:19
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
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    multiset<int> s;
    map<int,int> freq;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        s.insert(arr[i]);
        freq[arr[i]]++;
        freq[arr[i]*x]+=0;
    }
    sort(all(arr));
    for(int i=n-1;i>=0;i--) {
        if(freq[arr[i]]>0 and freq[arr[i]*x]>0) {
            freq[arr[i]]--;
            freq[arr[i]*x]--;
        }
    }
    int res=0;
    for(auto x:freq) {
        res+=x.second;
    }
    cout<<res<<endl;
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


