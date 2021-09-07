// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define all(ar) ar.begin(),ar.end()
// #define endl '\n'

// ll maxNO(ll n) {
//     string s=to_string(n);
//     ll max=0;
//     for(ll i=0;i<s.size();i++) {
//         if(s[i]-'0'>max) {
//             max=s[i]-'0';
//         }
//     }
//     return max;
// }
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     ll n;
//     cin>>n;
//     vector<ll> dp(n+1,0);
//     for(ll i=0;i<=9&&i<=n;i++) {
//         dp[i]=1;
//     }
//     dp[0]=0;
//     for(ll i=10;i<=n;i++) {
//         dp[i]=1+dp[i-maxNO(i)];
//     }
//     cout<<dp[n]<<endl;
// }



/*
author:Karan
created:25.07.2021 11:31:31
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

vector<int> fn(int a) {
    vector<int> ans;
    while(a) {
        ans.push_back(a%10);
        a/=10;
    }
    return ans;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<ll> dp(n+1,1e9+7);
    dp[0]=0;
    vector<int> arr;
    for(int i=1;i<=n;i++) {
        arr=fn(i);
        int m=arr.size();
        for(int j=0;j<m;j++) {
            if(arr[j]<=i) {
                dp[i]=min(dp[i],dp[i-arr[j]]+1);
            }
        }
    }
    cout<<dp[n]<<endl;
}