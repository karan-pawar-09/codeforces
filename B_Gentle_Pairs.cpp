#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i].first>>arr[i].second;
    }
    int ans=0;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(abs((double)(arr[j].second-arr[i].second)/(arr[j].first-arr[i].first))<=1) {
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}