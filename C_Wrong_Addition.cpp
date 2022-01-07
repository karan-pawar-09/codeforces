/*
    author:Karan
    created:20.12.2021 21:12:43
*/
#if true
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define mset(a,x) memset(a,x,sizeof(a))
#endif

void solve() {
    string a,s;
    cin>>a>>s;
    int j=s.size()-1;
    string ans;
    for(int i=a.size()-1;i>=0;i--) {
        int p=s[j]-'0';
        int cur=a[i]-'0';
        if(p>=cur) {
            int res=p-cur;
            if(res>9 or res<0) {
                cout<<-1<<endl;
                return;
            }
            else {
                ans+=to_string(res);
            }
        }
        else {
            if(j>=0) {
                j--;
                p+=(s[j]-'0')*10;
                int res=p-cur;
                if(res>9 or res<0) {
                    cout<<-1<<endl;
                    return;
                }
                else {
                    ans+=to_string(res);
                }
            } else {
                cout<<-1<<endl;
                return;
            }
        }
        j--;
    }
    for(j;j>=0;j--) {
        ans+=s[j];
    }
    reverse(all(ans));
    bool kk=true;
    for(int i=0;i<ans.size();i++) {
        if(ans[i]=='0' and kk) {
            
        }
        else if(ans[i]!='0' and kk) {
            cout<<ans[i];
            kk=false;
        }
        else {
            cout<<ans[i];
        }
    }
    cout<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}