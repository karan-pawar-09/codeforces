#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    string sum;
    for(int i=0;i<s.size();i+=2) {
        sum.push_back(s[i]);
    }
    sort(sum.begin(),sum.end());
    for(int i=0;i<sum.size()-1;i++){
        sum.insert(sum.begin()+1+i,'+');
    }
    cout<<sum;
}
