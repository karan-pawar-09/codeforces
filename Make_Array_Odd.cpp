/*
    author:Karan
    created:02.02.2023 14:11:49
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
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    int odd = 0;
    int even = 0;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        if(arr[i]%2) {
            odd++;
        } else {
            even++;
        }
    }
    
    if(x%2) {
        cout<<ceil(even, 2)<<endl;
    } else {
        if(even == n) {
            cout<<-1<<endl;
        } else {
            cout<<even<<endl;
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