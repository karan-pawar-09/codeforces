#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,w,x,y;
    cin>>h>>w>>x>>y;
    vector<string> arr(h);
    for(int i=0;i<h;i++) {
        cin>>arr[i];
    }
    x--;
    y--;
    int ans=0;
    for(int i=x-1;i>=0;i--) {
        if(arr[i][y]=='.') {
            ans++;
        }
        else {
            break;
        }
    }
    for(int i=x+1;i<h;i++) {
        if(arr[i][y]=='.') {
            ans++;
        }
        else {
            break;
        }
    }
    for(int i=y+1;i<w;i++) {
        if(arr[x][i]=='.') {
            ans++;
        }
        else {
            break;
        }
    }
    for(int i=y-1;i>=0;i--) {
        if(arr[x][i]=='.') {
            ans++;
        }
        else {
            break;
        }
    }
    ans++;
    cout<<ans<<endl;
}