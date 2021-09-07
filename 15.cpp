#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string a;
    cin>>a;
    int one=0,zero=0;
    for(int i=0;i<a.size();i++){
        if(a[i]=='z'){
            zero++;
        }
        else if(a[i]=='n') {
            one++;
        }
    }
    for(int i=0;i<one;i++){
        cout<<1<<" ";
    }
    for(int i=0;i<zero;i++){
        cout<<0<<" ";
    }
}
