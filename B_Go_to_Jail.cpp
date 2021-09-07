#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int score=0;
    int contineus=0;
    vector<vector<int> > arr(n,vector<int> (2,0));
    for(int i=0;i<n;i++) {
        cin>>arr[i][0]>>arr[i][1];
    }
    bool ans=false;
    for(int i=0;i<n-2;i++) {
        if(arr[i][0]==arr[i][1]&&arr[i+1][0]==arr[i+1][1]&&arr[i+2][0]==arr[i+2][1]){
            ans=true;
            break;
        }
    }
    if(ans)
        cout<<"Yes";
    else
    {
        cout<<"No";
    }
    
}