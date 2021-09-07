/*
author:Karan
created:12.08.2021 22:40:25
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        vector<int> arr(4);
        map<int,int> M;
        for(int i=0;i<4;i++) {
            cin>>arr[i];
            M[arr[i]]++;
        }      
        if(M.size()==4) {
            cout<<2<<endl;
        }
        else if(M.size()==3) {
            cout<<2<<endl;
        }
        else if(M.size()==2) {
            if((M[arr[0]]==3)||(M[arr[0]]==1)) {
                cout<<1<<endl;
            }
            else {
                cout<<2<<endl;
            }
        }
        else {
            cout<<0<<endl;
        }
    }
}