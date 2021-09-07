/*
authot:Karan
created:16.05.2021 17:41:24
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    set<int> sett;
    for(int i=0;i<10;i++) {
        if(s[i]=='o') {
            sett.insert(i);
        }
    }
    int ans=0;
    for(int i=0;i<10;i++)  {
        for(int j=0;j<10;j++) {
            for(int k=0;k<10;k++) {
                for(int l=0;l<10;l++) {
                    set<int> sette=sett;
                    if(s[i]=='x'||s[j]=='x'||s[k]=='x'||s[l]=='x') {
                        
                    }
                    else {
                        sette.erase(i);
                        sette.erase(j);
                        sette.erase(k);
                        sette.erase(l);
                        if(sette.size()==0) {
                            ans++;
                        }
                    }                    
                    
                }
            }
        }
    }
    cout<<ans<<endl;
}