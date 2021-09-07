#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int k=0;
    while(n!=0){
        if((n/100)!=0){
            n-=100;
            k++;
        }
        else if((n/100)==0&&(n/20)!=0) {
            n-=20;
            k++;
        }
        else if((n/100)==0&&(n/20)==0&&(n/10)!=0){
            n-=10;
            k++;
        }
        else if((n/100)==0&&(n/20)==0&&(n/10)==0&&(n/5)!=0){
            n-=5;
            k++;
        }
        else{
            n--;
            k++;
        }
    }
    cout<<k;
}
