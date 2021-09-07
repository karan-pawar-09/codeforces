#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    ll sum=0;
    for(int i=0;i<n;i++) {
        sum+=arr[i];
    }
    ll max=*(max_element(arr.begin(),arr.end()));
    if(sum%2==0&&max*2<=sum) {
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
}   