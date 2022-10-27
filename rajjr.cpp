/*
    author:Karan
    created:27.10.2022 13:03:58
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

const int mod = 1e9+7;

void solve() {
    int n;
    vector<string> arr(2);
    cin>>arr[0];
    cin>>arr[1];
    n = arr[0].size();
    int ans = 1;
    int i = 0;
    bool prev = false;
    if(arr[0][0] == arr[1][0]) {
        ans = 3;
        i++;
        prev = true;
    } else {
        ans = 6;
        i +=2;
    }
    for(;i<n;) {
        if(arr[0][i]==arr[1][i] && arr[0][i-1]==arr[0][i]) {
            ans = 0;
        }
        if(i<(n-1)) {
            if(arr[0][i]==arr[1][i] && arr[0][i+1]==arr[0][i]) {
                ans = 0;
            }
        }
        if(arr[0][i] == arr[1][i]) {
            if(prev) {
                ans *= 2;
            }
            prev = true;
            i++;
        } else {
            ans *= 2;
            prev = false;
            i+=2;
        }
        ans %= mod;
    }
    cout<<ans<<endl;

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

/*

    |  |  |


    |  |  |

*/