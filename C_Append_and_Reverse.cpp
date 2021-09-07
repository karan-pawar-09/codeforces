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
    vector<ll> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    deque<ll> ans;
    ans.push_back(arr[0]);
    for(int i=1;i<n;i++) {
        if(i%2) {
            ans.push_back(arr[i]);
        }
        else {
            ans.push_front(arr[i]);
        }
    }
    if(n%2) {
        for(int i=0;i<n;i++) {
            cout<<ans[i]<<" ";
        }
    }
    else {
        for(int i=0;i<n;i++) {
            cout<<ans[n-1-i]<<" ";
        }
    }
    cout<<endl;
}