/*
    author:Karan
    created:12.06.2023 20:30:00
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
    vector<int> arr(n);
    for(int i = 0; i < n; i ++) {
        cin >> arr[i];
    }
    int prev = -1;
    bool used = false;
    int maxi = arr[0];
    string s;
    for(int i = 0; i < n; i++) {
        if(used) {
            if(arr[i] >= prev && arr[i] <= maxi) {
                s+='1';
                prev = arr[i];
            } else {
                s+='0';
            }
        } else {
            if(arr[i] < prev) {
                if(arr[i] <= maxi) {
                    used = true;
                    prev = arr[i];
                    s+='1';
                } else {
                    s+='0';
                }
            } else {
                s += '1';
                prev = arr[i];
            }
            
        }
    }
    cout<<s<<endl;
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