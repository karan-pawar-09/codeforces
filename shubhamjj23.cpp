/*
    author:Karan
    created:19.11.2021 22:59:29
*/
// #if true
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

ll n;
const ll inf=1e18+7;
ll arr[20];
ll ans;
ll step(ll no, ll x, ll k) {
    if(k==0) {
        return no^x;
    }
    else if(k==1) {
        return no+x;
    }
    else {
        return no|x;
    }
}
void sol(ll i,ll k,ll no) {    
    if(i==n) {     
        ans=max(ans,no);  
        cout<<no<<" "; 
        return;
    }    
    sol(i+1,(k+1)%3,step(no,arr[i],k));
    sol(i+1,k,no);
}
string solve() {
    cin>>n;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    sol(0,2,0);
    return ans%2?"Odd":"even";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    cin>>t;
    while(t--) {
        cout<<solve()<<endl;
    }
}