/*
author:Karan
created:06.06.2021 20:52:21
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        bool ans=false;
        for(int i=0;i<26;i++) {
            ans=true;
            char k=(char)('a'+i);
            for(int j=0;j<n;j++) {
                if(k==s[j]) {
                    ans=false;
                }
            }
            if(ans==true) {
                cout<<k<<endl;
                break;
            }
        }
        if(ans==false) {
            for(int i=0;i<26;i++) {
                for(int j=0;j<26;j++) {
                    ans=true;
                    char k=(char)('a'+i);
                    char p=(char)('a'+j);
                    for(int q=0;q<n-1;q++) {
                        if(k==s[q]&&p==s[q+1]) {
                            ans=false;
                        }
                    }
                    if(ans==true) {
                        cout<<k<<p<<endl;
                        break;
                    }
                }
                if(ans==true) {                            
                    break;
                }
            }
        }
        if(ans==false) {
            for(int i=0;i<26;i++) {
                for(int j=0;j<26;j++) {
                    for(int k=0;k<26;k++) {
                        ans=true;
                        char fi=(char)('a'+i);
                        char se=(char)('a'+j);
                        char th=(char)('a'+k);
                        for(int q=0;q<n-2;q++) {
                            if(fi==s[q]&&se==s[q+1]&&th==s[q+2]) {
                                ans=false;
                            }
                        }
                        if(ans==true) {
                            cout<<fi<<se<<th<<endl;
                            break;
                        }
                    }
                    if(ans==true) {                            
                        break;
                    }
                }
                if(ans==true) {                            
                    break;
                }
            }
        }
        
    }   
}