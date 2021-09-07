#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    ll ans=0;
    // for(int b=k+1;b<=n;b++) {
    //     for(int a=b+1;a<=n;a++) {
    //         if(a%b>=k%b) {
    //             ans++;
    //         }
    //     }
    // }
    ans+=(n-k)*(n-k+1)/2;
    cout<<ans<<endl;
}