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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        // int ans=0;
        // for(int i=0;i<n;) {
        //     if(s[i]=='*') {
        //         ans++;
        //     }
        //     if((i+3)<n&&s[i+3]=='*') {
        //         i=i+3;
        //         continue;
        //     }
        //     else if((i+2)<n&&s[i+2]=='*') {
        //         i+=2;
        //         continue;
        //     }
        //     else {
        //         i++;
        //     }
        // }
        // int answer=0;
        // for(int i=n-1;i>=0;) {
        //     if(s[i]=='*') {
        //         answer++;
        //     }
        //     if((i-3)>=0&&s[i-3]=='*') {
        //         i-=3;
        //         continue;
        //     }
        //     if((i-2)>=0&&s[i-2]=='*') {
        //         i-=2;
        //         continue;
        //     }
        //     else {
        //         i--;
        //     }
        // }
        // cout<<min(ans,answer)<<endl;
        int start,end;
        for(int i=0;i<n;i++) {
            if(s[i]=='*') {
                start=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--) {
            if(s[i]=='*') {
                end=i;
                break;
            }
        }
        for(int i=start;i<end;i++) {
            int p=k;
            while(p) {
               if((i+p)<n&&s[i+p]=='*'&&s[i]=='*') {
                    for(int f=i+1;f<(i+p);f++) {
                        s[f]='.';
                    }
                    i+=(p-1);
                    break;
                } 
                else {
                    p--;
                }
            }
        }
        ll ans=0;
        for(int i=0;i<n;i++) {
            if(s[i]=='*') {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}