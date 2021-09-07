/*
author:Karan
created:13.06.2021 21:06:17
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int n,m;

int a[4]={-1,0,1,0};
int b[4]={0,-1,0,1};
bool isGood(int a,int b) {
    if(a<0||a>=n||b<0||b>=m) {
        return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        
        cin>>n>>m;
        vector<vector<char>> arr(n,vector<char>(m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin>>arr[i][j];
            }
        }
        bool ans=true;
        int pp=110;
        while(pp--) {
            if(pp==55) {
                if(arr[0][0]=='.') {
                    arr[0][0]='R';
                }
            }
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    if(arr[i][j]=='R') {
                        for(int k=0;k<4;k++) {
                            if(isGood(i+a[k],j+b[k])) {
                                if(arr[i+a[k]][j+b[k]]=='R') {
                                    ans=false;
                                }
                                if(arr[i+a[k]][j+b[k]]=='.') {
                                    arr[i+a[k]][j+b[k]]='W';
                                }
                            }
                        }
                    }
                    else if(arr[i][j]=='W') {
                        for(int k=0;k<4;k++) {
                            if(isGood(i+a[k],j+b[k])) {
                                if(arr[i+a[k]][j+b[k]]=='W') {
                                    ans=false;
                                }
                                if(arr[i+a[k]][j+b[k]]=='.') {
                                    arr[i+a[k]][j+b[k]]='R';
                                }
                            }
                        }
                    }
                }
            }
        }

        if(ans) {
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    cout<<arr[i][j];
                }
                cout<<endl;
            }
        }
        else {
            cout<<"NO"<<endl;
        }
    }

}