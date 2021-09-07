#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int x;
    cin>>n>>x;
    x=x*100;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i].first>>arr[i].second;
    }
    int ans=-1;
    int sum=0;
    for(int i=0;i<n;i++) {
        sum+=arr[i].first*arr[i].second;
        if(sum>x) {
            ans=i+1;
            break;
        }
    }
    cout<<ans<<endl;
}