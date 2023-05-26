/*
    author:Karan
    created:08.04.2023 16:11:21
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

bool isPrime(int n) {
    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int findPrime(int array_length, vector<int> arr) {
    for(int i=0 ;i < array_length;i++) {
        if(isPrime(arr[i])) {
            for(int j = 0; j < array_length; j++) {
                for(int k = 0; k < array_length; k++) {
                    if(j != k) {
                        if(arr[j] + arr[k] == arr[i]) {
                            return i;
                        }
                    }
                }
            }
        }
    }
    return -1;
}
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i< n;i++) {
        cin >> arr[i];
    }
    cout<<findPrime(n, arr);
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
