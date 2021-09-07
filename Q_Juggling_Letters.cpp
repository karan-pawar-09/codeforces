#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<string> arr(n); 
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        vector<int>kar(26,0);
        for(int i=0;i<n;i++) {
            for(int j=0;j<arr[i].size();j++) {
                kar[arr[i][j]-'a']++;
            }
        }
        bool ans=true;
        for(int i=0;i<26;i++) {
            if(kar[i]%n) {
                ans=false;
                break;
            }
        }
        if(ans) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
}