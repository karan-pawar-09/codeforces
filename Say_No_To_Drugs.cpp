/*
author:Karan
created:02.09.2021 20:05:33
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    int n,l,k;
    cin>>n>>k>>l;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int maxi=*max_element(all(arr));
    vector<int> ans;
    for(int i=0;i<n;i++) {
        if(arr[i]==maxi) {
            ans.push_back(i);
        }
    }
    if(ans.size()==1) {
        if(ans[0]==n-1) {
            cout<<"Yes"<<endl;
        }
        else {
            if(((k*(l-1))+arr[n-1])>maxi) {
                cout<<"Yes"<<endl;
            }
            else {
                cout<<"No"<<endl;
            }
        }
    }
    else {
        if(((k*(l-1))+arr[n-1])>maxi) {
            cout<<"Yes"<<endl;
        }
        else {
            cout<<"No"<<endl;
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