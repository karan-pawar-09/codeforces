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
        int opening=0;
        int ans=0;
        for(int i=0;i<n;i++) {
            if(s[i]=='(') {
                if(opening<0) {
                    opening=1;
                }
                else{
                    opening++;
                }
            }
            else {
                if(opening<=0) {
                    opening--;
                    ans++;
                }
                else {
                    opening--;
                }
            }
        }
        cout<<ans<<endl;
    }
}