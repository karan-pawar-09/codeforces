/*
    author:Karan
    created:23.11.2021 20:44:07
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

bool isPalindrome(vector<ll> &arr) {
    ll n=arr.size();
    for(ll i=0;i<(n/2);i++) {
        if(arr[i]!=arr[n-1-i]) {
            return false;
        }
    }
    return true;
}
void solve() {
    ll n;
    cin>>n;
    vector<ll> arr(n);
    vector<ll> freq(n+1,0);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    bool find=false;
    ll one=0;
    ll two=0;
    for(ll i=0;i<(n/2);i++) {
        if(arr[i]!=arr[n-1-i]) {
            find=true;
            one=arr[i];
            two=arr[n-1-i];
            break;
        }
    }
    if(!find) {
        cout<<"YES"<<endl;
    }
    else {
        bool ispalindrome=false;
        {   
            vector<ll> newarr;
            for(ll i=0;i<n;i++) {
                if(arr[i]!=one) {
                    newarr.push_back(arr[i]);
                }
            }
            ispalindrome|=isPalindrome(newarr);
        }
        {
            vector<ll> newarr;
            for(ll i=0;i<n;i++) {
                if(arr[i]!=two) {
                    newarr.push_back(arr[i]);
                }
            }
            ispalindrome|=isPalindrome(newarr);
        }
        if(ispalindrome) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
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