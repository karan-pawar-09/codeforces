/*
    author:Karan
    created:19.06.2023 21:06:11
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

vector<ll> generateRandomNumbers(ll N) {
    vector<ll> numbers(N);
    for(ll i = 0; i < N; i++) {
        numbers[i] = i+1;
    }
    random_shuffle(numbers.begin(), numbers.end());
    return numbers;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n;i++) {
        cin >> arr[i];
    }
    ll maxi = 0;
    ll index = 0;
    for(ll i = 1; i < n; i++) {
        if(arr[i] > maxi) {
            maxi = arr[i];
            index = i;
        }
    }
    vector<vector<ll>> dp;

    for(ll i = 0; i < index; i++) {
        vector<ll> temp;
        for(ll j = index-1; j >= i; j--) {
            temp.push_back(arr[j]);
        }
        for(ll j = 0; j < i; j++) {
            temp.push_back(arr[j]);
        }
        dp.push_back(temp);
    }
    if(index == n-1) {
        vector<ll> temp;
        for(ll i = 0; i < index; i++) {
            temp.push_back(arr[i]);
        }
        dp.push_back(temp);
    }
    sort(all(dp), greater<vector<ll>>());
    for(ll i= index; i<n;i++) cout<<arr[i]<<" ";
    if(dp.size())
        for(auto x: dp[0]) cout<<x<<" ";
    cout<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}