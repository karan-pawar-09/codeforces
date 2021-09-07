#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<vector<ll>> arr(n,vector<ll> (n));
    stack<pair<ll,ll>> black;
    stack<pair<ll,ll>> white;
    bool ans=true;
    if(n%2) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(ans) {
                    black.push({i,j});
                }
                else {
                    white.push({i,j});
                }
                ans=!ans;
            }
        }
    }
    else {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(ans) {
                    black.push({i,j});
                }
                else {
                    white.push({i,j});
                }
                ans=!ans;
            }
            ans=!ans;
        }
    }
    for(int i=0;i<(n*n);i++) {
        int k;
        cin>>k;
        if(k==1) {
            if(black.size()) {
                cout<<"2 "<<black.top().first+1<<" "<<black.top().second+1<<endl;
                black.pop();
       
            }
            else {
                cout<<"3 "<<white.top().first+1<<" "<<white.top().second+1<<endl;
                white.pop();
           
            }
        }
        else if(k==2) {
            if(white.size()) {
                cout<<"1 "<<white.top().first+1<<" "<<white.top().second+1<<endl;
                white.pop();
       
            }
            else {
                cout<<"3 "<<black.top().first+1<<" "<<black.top().second+1<<endl;
                black.pop();
             
            }
        }
        else {
            if(white.size()) {
                cout<<"1 "<<white.top().first+1<<" "<<white.top().second+1<<endl;
                white.pop();
            
            }
            else {
                cout<<"2 "<<black.top().first+1<<" "<<black.top().second+1<<endl;
                black.pop();
               
            }
        }
        cout<<endl;
        cout.flush();
    }
    return 0;
}