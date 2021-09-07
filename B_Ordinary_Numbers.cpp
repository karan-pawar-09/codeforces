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
        string s=to_string(n);
        int k=s.size();
        int ans=0;
        ans+=9*(k-1);
        for(int i=1;i<=9;i++) {
            string ss;
            for(int j=0;j<k;j++) {
                ss+=to_string(i);
            }
            if(stoi(ss)>n) {
                break;
            }
            else{
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}