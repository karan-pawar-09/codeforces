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
    vector<pair<ll,ll>> arr(n);
    ll sum=0;
    for(int i=0;i<n;i++) {
        cin>>arr[i].first>>arr[i].second;
        sum+=arr[i].first;
    }
    vector<ll> k(n);
    for(int i=0;i<n;i++) {
        k[i]=(2*arr[i].first)+arr[i].second;
    }
    sort(all(k));
    reverse(all(k));
    ll an=0;
    ll dis=0;
    for(int i=0;i<n;i++) {
        dis++;
        an+=k[i];
        if(an>sum) {
            break;
        }
    }
    cout<<dis<<endl;
}