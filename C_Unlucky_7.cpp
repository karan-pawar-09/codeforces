#include<bits/stdc++.h>
using namespace std;
#define ll long long
string toOctal(int n) {
    string s;
    while(n) {
        s+=to_string(n%8);
        n/=8;
    }
    return s;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int no=0;
    for(int j=1;j<=n;j++) {
        string s=to_string(j);
        string o=toOctal(j);
        int ans=true;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='7') {
                ans=false;
                break;
            }
        }
        for(int i=0;i<o.size();i++) {
            if(o[i]=='7') {
                ans=false;
                break;
            }
        }
        if(ans) {
            no++;
        }
    }
    cout<<no<<endl;
    

}