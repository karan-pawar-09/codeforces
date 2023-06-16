/*
    author:Karan
    created:04.06.2023 21:18:56
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
    ll n;
    cin >> n;
    vector<ll> arr(n);
    int maxi = 0;
    int one, two;
    vector<int> index(n+1);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        index[arr[i]] = i+1;
        if(arr[i] == 1) {
            one = i+1;
        }
        if(arr[i] == 2) {
            two = i+1;
        }
        if(arr[i] > arr[maxi]) {
            maxi = i;
        }
    }
    maxi = maxi +1;
    if(one == 1) {
        cout<<index[n]<<" "<<2<<endl;
        return;
    } 
    if(one == n) {
        cout<<index[n]<<" "<<n-1<<endl;
        return;
    }

    if(index[1] < maxi && index[2] < maxi) {
        if(index[1] > index[2]) cout<<index[1]<<" "<<maxi<<endl;
        else cout<<index[2]<<" "<<maxi<<endl;
    } else if(maxi < index[2] && maxi < index[1]) {
        if(index[1] < index[2]) cout<<index[1] << " "<<maxi<<endl;
        else cout<<maxi << " " << index[2]<<endl;
    } else {
        cout<<1<<" "<<1<<endl;
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