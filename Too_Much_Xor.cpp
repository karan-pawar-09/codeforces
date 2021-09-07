/*
author:Karan
created:20.06.2021 21:53:37
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        if(n==1) {
            cout<<0<<endl;
        }
        else if(n==2) {
            if(arr[0]==arr[1]) {
                cout<<-1<<endl;
            }
            else {
                cout<<0<<endl;
            }
        }
        else {
            map<int,int> M;
            for(int i=0;i<n;i++) {
                M[arr[i]]++;
            }   
            
            if(M.size()==2) {
                bool ans=true;
                for(int i=1;i<n;i++) {
                    if(arr[i]==arr[i-1]) {
                        ans=false;
                    }
                }
                ans?cout<<0<<endl:cout<<-1<<endl;
            }
            else {                                    
                cout<<-1<<endl;                
            }
            
        }
    }   
}