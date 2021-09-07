#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,d;
    cin>>n>>d;
    string a;
    cin>>a;
    bool flag=true;
    int number=0;
    for(int i=0;i<n;) {
        for(int j=i+d;j>=i;j++) {
            
            if(j==i) {
                flag=false;
            }
            else {
                if(a[j]=='1') {
                i=j;
                number++;
                break;
            }
            }
        }
    }
    if(flag){
        cout<<number;
    }
    else{
        cout<<"-1";
    }
}