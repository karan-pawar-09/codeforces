#include<bits/stdc++.h>
#define fo(i,n,a) for(int i=a;i<n;i++)
using namespace std;
bool compare(int a,int b) {
    if(a==b){
        return true;
    }
    else{
        return false;
    }
}
int main() {
    int n;
    cin>>n;
    int a[n],b[n];
    fo(i,n,0){cin>>a[i];}
    fo(i,n,0){cin>>b[i];}
    int k=0;
    for(k=0;k<n;k++) {
        if(a[0]==b[k]) {
            break;
        }
        else{
            continue;
        }
    }
    k--;
    int count=0;
    for(int i=1;i<n;i++) {
        if(((k+i)<n)?compare(a[i],b[k+i]):compare(a[i],b[k+i-n])){
            count++;
        }
    }
    if(k==0) {
        cout<<++count;
    }
    else{
        cout<<count;
    }
}