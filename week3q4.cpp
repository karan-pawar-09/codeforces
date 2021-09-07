/*
authot:Karan
created:21.05.2021 18:31:37
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++) {
        cin>>b[i];
    }
    sort(all(a));
    sort(all(b));
    ll ans=0;
    for(int i=0;i<n;i++) {
        ans+=a[i]*b[i];
    }
    cout<<ans<<endl;
}