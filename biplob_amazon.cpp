/*
    author:Karan
    created:04.08.2022 11:34:13
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

string getEncryptedNumber(vector<int> &arr) {
    vector<int> ans = arr;
    for(int i = 0;i<arr.size()-2;i++) {
        for(int j=0;j<arr.size()-i-1;j++) {
            ans[j] = (ans[j]+ans[j+1])%10;
        }
    }
    return to_string(ans[0])+to_string(ans[1]);
}

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i =0;i<n;i++) {
        cin>>arr[i];
    }
    
    cout<<getEncryptedNumber(arr)<<endl;
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