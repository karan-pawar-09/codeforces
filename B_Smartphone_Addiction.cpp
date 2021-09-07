#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,t;
    cin>>n>>m>>t;
    int cap=n;
    vector<vector<int>>arr(m,vector<int>(2,0));
    for(int i=0;i<m;i++) {
        cin>>arr[i][0]>>arr[i][1];
    }
    bool ans=true;
    for(int i=0;i<arr[0][0];i++) {
        n--;
        if(n<=0) {
            ans=false;
            break;
        }
    }
    for(int i=0;i<m;i++) {
        n+=arr[i][1]-arr[i][0];
        if(n>cap) {
            n=cap;
        }
        if(i+1<m){
            n-=arr[i+1][0]-arr[i][1];
        }
        if(n<=0) {
            ans=false;
            break;
        }
    }
    n-=t-arr[m-1][1];
    if(n<=0) {
        ans=false;
    }
    if(ans) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
}
