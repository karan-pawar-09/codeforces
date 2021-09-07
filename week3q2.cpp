/*
authot:Karan
created:21.05.2021 15:01:40
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
    long double W;
    cin>>n>>W;
    long double ans=0;
    vector<pair<long double,pair<long double,long double>>> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i].second.first>>arr[i].second.second;
        arr[i].first=arr[i].second.first/arr[i].second.second;
    }
    sort(all(arr),greater<pair<long double,pair<long double,long double>>>());
    for(int i=0;i<n;i++) {
        if(W>=arr[i].second.second) {
            W-=arr[i].second.second;
            ans+=arr[i].second.first;
        }
        else {            
            ans+=W*arr[i].first;
            W=0;
            break;
        }
    }
    cout<<setprecision(4)<<fixed;
    cout<<ans<<endl;
}