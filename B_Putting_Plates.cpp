
#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define endl '\n'
void solve() {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> matrix(n,vector<int> (m,0));
        
        for(int i=0;i<m;i+=2) {
            matrix[0][i]=1;
        }       
        for(int i=1;i<n;i++) {
            if(matrix[i-1][0]==0&&matrix[i-1][1]==0) {
                matrix[i][0]=1;
            }
        }
        for(int i=1;i<n;i++) {
            if(matrix[i-1][m-1]==0&&matrix[i-1][m-2]==0) {
                matrix[i][m-1]=1;
            }
        }
        for(int i=1;i<m-1;i++) {
            if(matrix[n-1][i-1]==0&&matrix[n-2][i-1]==0&&matrix[n-1][i+1]==0&&matrix[n-2][i+1]==0) {
                matrix[n-1][i]=1;
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cout<<matrix[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}