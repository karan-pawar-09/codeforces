#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    if(n>m+1||(n==3&&m==2)) {
        cout<<"NO"<<endl;
    }
    else {        
        vector<vector<int>>arr(n,vector<int>(m));
        vector<bool> used(m,true);
        for(int i=0;i<m;i++) {
            arr[0][i]=i;
        }
        for(int i=1;i<n;i++) {
            for(int j=i-1;j<m;j++) {
                arr[i][j]=j;
            }
            for(int j=0;j<i-2;j++) {
                arr[i][j]=j+1;
            }
            if(i>=2) {
                arr[i][i-2]=0;
            }
        }
        if(n>2&&m>2) {
            arr[2][0]=2;arr[2][2]=0;
        }
        int k=0;
        bool ans=true;
        if(ans) {
        cout<<"YES"<<endl;
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    cout<<arr[i][j]+1<<" ";
                }
                cout<<endl;
            }
        }
    }
}