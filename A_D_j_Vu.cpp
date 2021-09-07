#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

bool isPalindrome(string s) {
    int n=s.size();
    bool ans=true;
    for(int i=0;i<(n/2);i++) {
        if(s[i]!=s[n-i-1]) {
            ans=false;
            break;
        }
    }
    return ans;
}
int count (string s) {
    int n=s.size();
    ll count=0;
    for(int i=0;i<n;i++) {
        if(s[i]=='a') {
            count++;
        }
    }
    return count;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        // ll a=0;
        // bool first=false;
        // for(int i=0;i<(s.size()/2)+1;i++) {
        //     if(s[i]!='a') {
        //         if(i==0) {
        //             cout<<"YES"<<endl<<s<<"a"<<endl;
        //         }
        //         else {
        //             cout<<"YES"<<endl<<s.substr(0,s.size()-i)<<"a"<<s.substr(s.size()-i,i)<<endl;
        //         }   
        //         first=true;             
        //         break;
        //     }
        // }
        // bool second=false;
        // if(!first) {
        //     for(int i=s.size()/2;i<s.size();i++) {
        //         if(s[i]!='a') {
        //             if(i==(s.size()-1)) {
        //                 cout<<"YES"<<endl<<"a"<<s<<endl;
        //             }
        //             else {
        //                 cout<<"YES"<<endl<<s.substr(0,s.size()-i-1)<<"a"<<s.substr(s.size()-i-1,i+1);
        //             }
        //             second=true;
        //             break;
        //         }
        //     }
        // }
        // if(first==false&&second==false) {
        //     cout<<"NO"<<endl;
        // }
        if(count(s)==s.size()) {
            cout<<"NO"<<endl;
        }
        else {
            if(isPalindrome(s)) {
                cout<<"YES"<<endl;
                cout<<s<<"a"<<endl;
            }
            else {
                string kp=s+'a';
                string pk = 'a'+s;
                if(!isPalindrome(kp)) {
                    cout<<"YES"<<endl;
                    cout<<kp<<endl;
                }
                else if( !isPalindrome(pk)) {
                    cout<<"YES"<<endl;
                    cout<<pk<<endl;
                }
                else {
                    cout<<"NO"<<endl;
                }
            }
        }
        
    }
}