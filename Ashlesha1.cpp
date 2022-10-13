/*
    author:Karan
    created:04.09.2022 14:52:57
*/
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    deque<int> dq;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        dq.push_back(arr[i]);
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++) {
        int k = dq.back();
        dq.pop_back();
        dq.push_front(k);
        for(auto x: dq) {
            cout<<x<<" ";
        }
        cout<<endl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}