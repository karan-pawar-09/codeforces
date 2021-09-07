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
        string a,b;
        cin>>a;
        cin>>b;
        a+='0';
        b+='0';
        n++;      
        vector<int> prefix(n+1,0);
        vector<int> prefixb(n+1,0);
        prefix[0]=0;
        for(int i=1;i<=n;i++) {
            if(a[i-1]=='1') {
                prefix[i]=prefix[i-1]+1;
            }
            else {
                prefix[i]=prefix[i-1];
            }
        }
       prefixb[0]=0;
        for(int i=1;i<=n;i++) {
            if(b[i-1]=='1') {
                prefixb[i]=prefixb[i-1]+1;
            }
            else {
                prefixb[i]=prefixb[i-1];
            }
        }
        bool ans=true;
        for(int i=0;i<n-1;i++) {
            if((a[i]!=b[i])&&(a[i+1]==b[i+1])) {
                if(i%2==0||(prefix[i+1]*2!=(i+1))) {
                    ans=false;
                    break;
                }
                if(i%2==0||(prefixb[i+1]*2!=(i+1))) {
                    ans=false;
                }
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