#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,w;
    cin>>h>>w;
    vector<vector<ll>> arr(h,vector<ll> (w));
    for(int i=0;i<h;i++) {
        for( int j=0;j<w;j++) {
            char c;
            cin>>c;
            if(c=='#') {
                arr[i][j]=1;
            }
            else {
                arr[i][j]=0;
            }
        }
    }
    int ans=0;
    for(int i=0;i<h-1;i++) {
        for(int j=0;j<w-1;j++) {
            if((arr[i][j]+arr[i+1][j]+arr[i][j+1]+arr[i+1][j+1])==1||(arr[i][j]+arr[i+1][j]+arr[i][j+1]+arr[i+1][j+1])==3) {
               ans++;
            }
        }
    }
    cout<<ans<<endl;
}