#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    vector<int>ans;
    int start=0;
    int end=n-1; 
    while(start<=end) {
        if(abs(arr[start])<abs(arr[end])) {
            ans.push_back(arr[end]*arr[end]);
            end--;
        }
        else{
            ans.push_back(arr[start]*arr[start]);
            start++;
        }
    }
    for(int i=0;i<ans.size();i++) {
        cout<<ans[ans.size()-1-i]<<endl;
    }
}