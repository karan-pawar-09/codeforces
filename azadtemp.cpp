/*
author:Karan
created:11.08.2021 19:13:27
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

vector<int> answer(vector<int> arr) {
    int n=arr.size();
    vector<int> ar=arr;
    sort(all(ar));
    int sum=0;
    for(int i=0;i<n;i++) {
        sum+=ar[i];
    }
    vector<int> ans;
    int sub=0;
    for(int i=n-1;i>=0;i--) {
        ans.push_back(ar[i]);
        sum-=ar[i];
        sub+=ar[i];
        if(sub>sum) {
            break;
        }
    }
    sort(all(ans));
    return ans;
} 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int> ans=answer(arr);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
