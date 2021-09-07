#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,w;
    cin>>h>>w;
    vector<int> arr(h*w);
    for(int  i=0;i<h*w;i++) {
        cin>>arr[i];
    }
    int mini=*min_element(arr.begin(),arr.end());
    int ans=0;
    for(int i=0;i<h*w;i++) {
        ans+=arr[i]-mini;
    }
    cout<<ans<<endl;
}