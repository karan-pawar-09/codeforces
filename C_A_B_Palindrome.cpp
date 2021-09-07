#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
 
bool isGood(string s,ll a,ll b) {
    ll n=s.size();
    ll ones=0;
    ll zeros=0;
    bool ans=true;
    for(ll i=0;i<n;i++) {
        if(s[i]!=s[n-i-1]) {
            ans=false;
        }
        if(s[i]=='1') {
            ones++;
        }
        if(s[i]=='0') {
            zeros++;
        }
        if(s[i]=='?') {
            ans=false;
        }
    }
    if(ones!=b) {
        ans=false;
    }
    if(zeros!=a) {
        ans=false;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) {
        ll a,b;
        cin>>a>>b;
        string s;
        cin>>s;      
        ll one=0;
        ll zero=0;
        ll n=s.size();
        for(ll i=0;i<n;i++) {
            if(s[i]=='1') {
                one++;
            }
            if(s[i]=='0') {
                zero++;
            }
        }  
        ll i=0;
        ll j=s.size()-1;
        while(i<j) {
            if(s[i]!='?'&&s[j]!='?') {
 
            }
            else if(s[i]=='?'&&s[j]!='?') {
                s[i]=s[j];
                if(s[j]=='0') {
                    zero++;
                }
                else {
                    one++;
                }
            }
            else if(s[i]!='?'&&s[j]=='?'){
                s[j]=s[i];
                if(s[i]=='0') {
                    zero++;
                }
                else {
                    one++;
                }
            }
            
            i++;
            j--;
        }
        int zeroremainder=a-zero;
        int oneremainder=b-one;
        if(s.size()%2) {
            if(s[(s.size()/2)]=='?') {
                if(oneremainder%2) {
                    s[(s.size()/2)]='1';
                    one++;
                }
                else if(zeroremainder%2){
                    s[(s.size()/2)]='0';
                    zero++;
                }
                
            }
        }
        i=0;
        j=s.size()-1;
        while(i<j) {
            if(s[i]=='?'&&s[j]=='?'){
                if(zero<a) {
                    s[i]=s[j]='0';
                    zero+=2;
                }
                else {
                    s[i]=s[j]='1';
                    one+=2;
                }                
            }
            i++;
            j--;
        }
        
        if(isGood(s,a,b)) {
            cout<<s<<endl;
        }
        else {
            cout<<"-1"<<endl;
        }
        
    }
}