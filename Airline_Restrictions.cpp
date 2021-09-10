/*
    author:Karan
    created:10.09.2021 16:25:46
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    int d,e;
    vector<int> arr(3);
    for(int i=0;i<3;i++) {
        cin>>arr[i];
    }
    cin>>d>>e;
    sort(all(arr));
    if(arr[0]>e) {
        cout<<"NO"<<endl;
    }
    else {
        int i=0;
        while(((i+1) < 3) and arr[i+1]<=e) {
            i++;
        }
        int k=arr[i];
        if(arr[1]+arr[2]+arr[0]-k <= d) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}