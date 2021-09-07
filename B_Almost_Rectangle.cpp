#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<char>> arr(n,vector<char>(n));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin>>arr[i][j];
            }            
        }
        int i1=-1;
        int j1=-1;
        int i2=-1;
        int j2=-1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(arr[i][j]=='*'&&i1==-1&&j1==-1) {
                    i1=i;
                    j1=j;                
                }
                if(arr[i][j]=='*'&&i1!=-1&&j1!=-1) {
                    i2=i;
                    j2=j;
                }
            }
        }
        // cout<<i1<<" "<<j1<<endl<<i2<<" "<<j2<<endl<<endl;
        if(i1!=i2&&j1!=j2) {
            arr[i1][j2]='*';
            arr[i2][j1]='*';
        }
        else if(((i1==i2)&&(j1!=j2))||(i1!=i2&&j1==j2)) {
            if(i1==i2) {
                for(int i=0;i<n;i++) {
                    if(i!=i1) {
                        arr[i][j1]='*';
                        arr[i][j2]='*';
                        break;
                    }
                    
                }
            }
            else {
                for(int j=0;j<n;j++) {
                    if(j!=j1) {
                        arr[i1][j]='*';
                        arr[i2][j]='*';
                        break;
                    }
                }
            }
        }
        else {
            if(i1==0) {
                if(j1==0) {
                    arr[i1+1][j1+1]='*';
                }
                else {
                    arr[i1+1][j1-1]='*';
                }                
            }
            else {
                if(j1==0) {
                    arr[i1-1][j1+1]=='*';
                }
                else {
                    arr[i1-1][j1-1]=='*';
                }
            }
            i1=-1;
            j1=-1;
            i2=-1;
            j2=-1;
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(arr[i][j]=='*'&&i1==-1&&j1==-1) {
                        i1=i;
                        j1=j;                
                    }
                    if(arr[i][j]=='*'&&i1!=-1&&j1!=-1) {
                        i2=i;
                        j2=j;
                    }
                }
            }
            if(i1!=i2&&j1!=j2) {
                arr[i1][j2]='*';
                arr[i2][j1]='*';
            }
            else if(((i1==i2)&&(j1!=j2))||(i1!=i2&&j1==j2)) {
                if(i1==i2) {
                    for(int i=0;i<n;i++) {
                        if(i!=i1) {
                            arr[i][j1]='*';
                            arr[i][j2]='*';
                            break;
                        }
                        
                    }
                }
                else {
                    for(int j=0;j<n;j++) {
                        if(j!=j1) {
                            arr[i1][j]='*';
                            arr[i2][j]='*';
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cout<<arr[i][j];
            }
            cout<<endl;
        }
    }
}   