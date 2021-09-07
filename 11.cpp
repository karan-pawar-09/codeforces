#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    if(s.size()<7){
        cout<<"NO";
    }

    else {
    int count=0;
    for(int i=0;i<s.size()-6;i++) {
        if(s[i]==s[i+1]&&s[i+1]==s[i+2]&&s[i+2]==s[i+3]&&s[i+3]==s[i+4]&&s[i+4]==s[i+5]&&s[i+5]==s[i+6]){
            count++;
        }
    }
    if(count==0){
        cout<<"NO";
    }
    else {
        cout<<"YES";
    }}
}
