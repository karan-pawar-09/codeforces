#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int m=n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int ans=0;
    vector<int> ar;
    int size=n/2;
    for(int i=size,j=0;i<n;i++,j++) {
        ar.push_back(arr[i]);
        if(j<size){
            ar.push_back(arr[j]);
        }
    }
    for(int i=1;i<ar.size()-1;i++) {
        if(ar[i]<ar[i+1]&&ar[i]<ar[i-1]) {
            ans++;
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<n;i++) {
        cout<<ar[i]<<" ";
    }
}