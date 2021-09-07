/*
author:Karan
created:30.05.2021 20:07:08
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
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        m=min(m,1000);
        for(int j=0;j<m;j++) {
            vector<int> ar;
            for(int i=0;i<n;i++) {
                if(s[i]=='1') {
                    int k=-1;
                    int p=-1;
                    if(i+1<n&&s[i+1]=='0'&&((i+2<n&&s[i+2]=='0')||(i+1==n-1))) {
                        ar.push_back(i+1);
                    }
                    if(i-1>=0&&s[i-1]=='0'&&((i-2>=0&&s[i-2]=='0')||(i-1==0))) {
                        ar.push_back(i-1);
                    }
                }
            }
            for(int k=0;k<ar.size();k++) {
                s[ar[k]]='1';
            }
        }
        cout<<s<<endl;
    }
}