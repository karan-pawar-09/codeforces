#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    vector<ll> price(n);
    for(int i=0;i<n;i++) {
        cin>>price[i];
    }
    vector<ll> pages(n);
    for(int i=0;i<n;i++) {
        cin>>pages[i];
    } 
    vector<ll> dp(x+1,0);
    for(int i=1;i<=n;i++) {
        for(int j=x;j>=price[i-1];j--) {           
            dp[j]=max(pages[i-1]+dp[j-price[i-1]],dp[j]);            
        }
    }
    cout<<dp[x]<<endl;
}