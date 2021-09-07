/*
author:Karan
created:11.07.2021 12:15:51
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
        int k,n,m;
        cin>>k>>n>>m;
        vector<int> a(n),b(m);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        for(int i=0;i<m;i++) {
            cin>>b[i];
        }
        int i=0;
        int j=0;
        bool ans=true;
        vector<int> answer;
        while(i<n||j<m) {
            if(i<n&&a[i]<=k) {
                answer.push_back(a[i]);
                if(a[i]==0) k++;
                i++;
            }
            else if(j<m&&b[j]<=k) {
                answer.push_back(b[j]);
                if(b[j]==0) k++;
                j++;
            }
            else {
                ans=false;
                break;
            }
        }
        if(ans) {
            for(int i=0;i<answer.size();i++) {
                cout<<answer[i]<<" ";
            }
            cout<<endl;
        }
        else {
            cout<<-1<<endl;
        }
    }
}