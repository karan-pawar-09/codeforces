#include<bits/stdc++.h>
using namespace std;
int main() {
    int v,n;
    cin>>n>>v;
    int k=0;
    int money=0;
    if(v>=(n-1)){
        cout<<v;
    }
    else{
        int dist=0;
        int money=0;
        int i=0;
        for(i=0;(dist+v)<=(n-1);i++){
            money+=(i+1)*v;
            dist+=v;
        }
        money+=(i+1)*(n-1-v);
        cout<<money;
        }
    }

