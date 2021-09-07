#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int stringsumeven (string s) {
    int a=0;
     for(int i=0;i<s.size();i+=2) {
        a+=s[i]-'0';
    }
    return a;
}
int stringsumodd(string s) {
    int b=0;
     for(int i=1;i<s.size();i+=2) {
        b+=s[i]-'0';
    }
    return b;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        string s;
        int n;
        cin>>s>>n;
        int oneodd=stringsumodd(s);
        int oneeven=stringsumeven(s);
        int k=stringsumodd(to_string(oneodd));
        int q=stringsumeven(to_string(oneodd));
        int p=stringsumeven(to_string(oneeven));  
        int z=stringsumodd(to_string(oneeven));      
        if(oneodd==n||oneeven==n||k==n||p==n||q==n||z==n) {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl \n

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

}
