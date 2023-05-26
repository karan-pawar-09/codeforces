/*
    author:Karan
    created:02.02.2023 14:32:51
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
    cin >> n;
    if(n%2) {
        cout<<-1<<endl;
        return;
    }
    vector<int> arr(n);
    arr[0] = 1;
    for(int i=1;i<n;i++) {
        if(i%2) {
            arr[i] = 0;
        } else {
            arr[i] = 2;
        }
    }
    int sum = 0;
    int sum1 = 0;
   
    for(int i=0;i<n-1;i++) {
        sum += arr[i];
        sum1 += arr[n-1-i];
       
        if(i%2 == 0) {
            assert(sum > sum1);
        } else {
            assert(sum1 > sum);
        }
    }
    for(auto x: arr) {
        cout<<x<<" ";
    }
    cout<<endl;
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