#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<ll>a(n);
    vector<ll>b(m);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<m;i++) {
        cin>>b[i];
    }
    ll ans=0;
    for(int i=1;i<n;i++) {
        ans=__gcd((a[i]-a[0]),ans);
    }
    for(int i=0;i<m;i++) {
        cout<<abs(__gcd(ans,(a[0]+b[i])))<<" ";
    }
}