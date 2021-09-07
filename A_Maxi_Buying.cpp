/*
author:Karan
created:19.06.2021 17:30:15
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int price=(n*108)/100;
    if(price<206) {
        cout<<"Yay!"<<endl;
    }
    else if(price>206) {
        cout<<":("<<endl;
    }
    else {
        cout<<"so-so"<<endl;
    }
}