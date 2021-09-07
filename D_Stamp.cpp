#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;   
    vector<int>arr(m+2,0);
    for(int i=1;i<=m;i++) {
        cin>>arr[i];
    }
    arr[m+1]=n+1;
    sort(arr.begin(),arr.end());
    int mini = (int)1e9+7;
    for(int i=1;i<=m+1;i++) {
        if(arr[i]!=arr[i-1]+1) {
            mini=min(mini,arr[i]-arr[i-1]-1);
        }            
    }
    int answer=0;
    for(int i=1;i<=m+1;i++) {
         if(arr[i]!=arr[i-1]+1) {
            answer+=ceil((double)(arr[i]-arr[i-1]-1)/mini);
        }        
    }
    cout<<answer<<endl;
}
    
    