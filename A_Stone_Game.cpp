/*
author:Karan
created:10.06.2021 20:07:18
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        int a=max_element(all(arr))-arr.begin();
        int b=min_element(all(arr))-arr.begin();
        int k=min(a+1,n-a);
        int p=min(b+1,n-b);
        int ans=k+p;
        ans=min(ans,max(a+1,b+1));
        ans=min(ans,max(n-a,n-b));
        cout<<ans<<endl;
    }   
}