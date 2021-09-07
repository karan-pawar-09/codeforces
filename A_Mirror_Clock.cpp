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
        int h,m;
        cin>>h>>m;
        
        if(m==0&&h!=12) {
            h=12-h;
        }
        
        if(h>=1&&h<=10) {
            if(m>=1&&m<=59) {
                h=11-h;
                m=60-m;
            }
        }
        if(h>=11&&h<=12) {
            if(m>=1&&m<=59) {
                h=23-h;
                m=60-m;
            }
        }
    
        cout<<h<<" "<<m<<endl;
    }
}