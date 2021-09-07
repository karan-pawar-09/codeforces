/*
authot:Karan
created:19.05.2021 13:25:42
*/
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
        vector<vector<int>> arr(n,vector<int> (n,2));
        for(int i=0;i<n;i++) {
            arr[i][i]=0;
        }
        int matches=n-1;
        int l,w,d;
        if(matches%2==0) {
            w=l=matches/2;
            d=0;
        }
        else {
            d=1;
            w=l=(matches-1)/2;
        }
        if(n%2==0) {
            for(int i=0;i<n;i+=2) {
                arr[i][i+1]=0;
                arr[i+1][i]=0;
            }
        }
        
        for(int i=0;i<n;i++) {
            int win=w;
            int lose=l;
            int draw=d;
            for(int j=0;j<n;j++) {
                if(arr[i][j]==1) {
                    win--;
                }
                if(arr[i][j]==-1) {
                    lose--;
                }
                if(arr[i][j]==0) {
                    if(i!=j) {
                        draw--;
                    }                    
                }
                if(n%2) {
                    if(arr[i][j]==2) {
                        if(win>0) {
                            win--;
                            arr[i][j]=1;
                            arr[j][i]=-1;
                        }
                        else if(lose>0) {
                            lose--;
                            arr[i][j]=-1;
                            arr[j][i]=1;
                        }
                        else {
                            draw--;
                            arr[i][j]=0;
                            arr[j][i]=0;
                        }
                    }
                }
                else {
                    if(arr[i][j]==2) {
                        if(i==0) {
                            if(lose>0) {
                                lose--;
                                arr[i][j]=-1;
                                arr[j][i]=1;
                            }
                            else {
                                win--;
                                arr[i][j]=1;
                                arr[j][i]=-1;
                            }
                        }
                        else  {
                            if(arr[i-1][j]==1) {
                                if(lose>0) {
                                    lose--;
                                    arr[i][j]=-1;
                                    arr[j][i]=1;
                                }
                                else if (win>0){
                                    win--;
                                    arr[i][j]=1;
                                    arr[j][i]=-1;
                                }
                                
                            }
                            else if(arr[i-1][j]==-1) {
                                if(win>0){
                                    win--;
                                    arr[i][j]=1;
                                    arr[j][i]=-1;
                                }
                                else if(lose>0){
                                    lose--;
                                    arr[i][j]=-1;
                                    arr[j][i]=1;
                                }
                            }
                        }
                    }
                }
                
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {   
                if(i<j)            
                    cout<<arr[i][j]<<" ";                
            }
        }
        cout<<endl;
    }
}