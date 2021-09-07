#include<bits/stdc++.h>
using namespace std;

int main() {
    int a;
    cin>>a;
    // ostringstream str1;  
    // str1 << a; 
    string b = to_string(a);
    int n=b.size();
    int sum=0;
    for(int i=0;i<n;i++) {
        int k=b[i]-'0';
        if(i%2==0) {
            sum+=k;
        }
        else{
            sum-=k;
        }
    }
    cout<<sum<<endl;
}