/*
    author:Karan
    created:13.08.2022 21:46:48
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
    multiset<int> ms;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        ms.insert(arr[i]);
    }
    int ans = n;
    {
        for(int i=n-1;i>=0;i--) {
        
            ms.erase(ms.find(arr[i]));
            bool k = true;
            if(i< (n-1)) {
                k = arr[i]<=arr[i+1];
            }
            bool p = true;
            if(i>0) {
                if(arr[i]==arr[i-1]){
                    
                }
                else {
                    p = ms.find(arr[i]) == ms.end();
                }
            }
            if(k&&p) {
                ans = i;
            } else break;
        }
    }
    set<int> s;
    for(int i=0;i<ans;i++) {
        if(arr[i]!=0)
            s.insert(arr[i]);
    }
    cout<<s.size()<<endl;
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
