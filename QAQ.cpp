#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    int n=s.size();
    vector<int> arr(n,0);
    int q=0;
    for(int i=n-1;i>=0;i--) {
        if(s[i]=='Q') {
            q++;
        }
        else if(s[i]=='A') {
            arr[i]=q;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++) {
        if(s[i]=='Q') {
            for(int j=i+1;j<n;j++) {
                ans+=arr[j];
            }
        }
    }
    cout<<ans;
}