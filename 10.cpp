#include<bits/stdc++.h>
using namespace std;

string convert(string k) {

    for(int i=0;i<k.size();i++) {
        if(k[i]< 97){
            k[i] = k[i]+32;
        }

    }
    return k;
}
int main() {
    string a,b;
    cin>>a;
    cin>>b;
    string p = convert(a);
    string q = convert(b);
  //  cout<<p<<endl<<q<<endl;
    int k=p.compare(q);
    if(k<0){
        cout<<"-1";
    }
    else if(k>0) {
        cout<<"1";
    }
    else {
        cout<<"0";
    }
}
