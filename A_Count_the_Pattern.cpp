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
    vector<vector<int>>arr(n,vector<int>(n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<n-1;i++) {
        for(int j=1;j<n-1;j++) {
            if(arr[i][j]==0&&arr[i-1][j]==1&&arr[i][j-1]==1&&arr[i+1][j]==1&&arr[i][j+1]==1) {
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}