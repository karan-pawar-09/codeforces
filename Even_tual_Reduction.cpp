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
        string s;
        cin>>s;
        vector<int> arr(26,0);
        for(int i=0;i<n;i++) {
            arr[s[i]-'a']++;
        }
        bool ans=true;
        for(int i=0;i<26;i++) {
            if(arr[i]%2) {
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