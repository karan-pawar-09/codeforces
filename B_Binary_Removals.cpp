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
        string s;
        cin>>s;
        int n=s.size();
        bool one=false;
        bool zero=false;
        int one1=0;
        int zero1=0;
        for(int i=1;i<n;i++) {
            if(s[i]==s[i-1]) {
                if(s[i]=='1') {

                }
                else {
                    zero=true;
                    zero1=i;
                }
            }
        }
        for(int i=n-1;i>=1;i--) {
            if(s[i]==s[i-1]) {
                if(s[i]=='1') {
                    one=true;
                    one1=i;
                }
            }
        }
        if((one&&zero)&&one1<zero1) {
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
}