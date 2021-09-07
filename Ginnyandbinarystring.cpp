#include<bits/stdc++.h>
using namespace std;
int main() {
    string input;
    cin>>input;
    long long a=0;
    int n=input.size();
    
   for(int i=n-1;i>=0;i--) {
       if(input[i]=='1') {
           cout<<a;
           break;
       }
       a++;
   }
}