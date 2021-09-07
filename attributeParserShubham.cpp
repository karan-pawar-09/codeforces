#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


int main() {
    int n,q;
    //cin>>n>>q;
    scanf("%d %d",&n,&q);
    string strr;
    vector<string>code;
    vector<string>query;
    getline(cin,strr);
    for(int i=0;i<n;i++) {
        getline(cin, strr);
        code.push_back(strr);
        //cout<<code[i]<<endl;
    }     
    for(int i=0;i<q;i++) {
        getline(cin, strr);
        query.push_back(strr);
        //cout<<query[i]<<endl;
    }
    map<string,string> answer;
    vector<string>key;
    vector<string>value;

    string store;    
    if(code[0][1]!='/') {
        int k=1;
        while(code[0][k]!=' ') {
            store+=code[0][k];
            k++;
        }
    }
    //cout<<store<<endl;
    for(int j=0;j<code[0].size();j++) {
        string qq="~";
        string kans;
        if(code[0][j-1]==' '&&code[0][j]!='='&&code[0][j]!='\"') {
            qq+=code[0][j];
            int pp=j+1;
            while(code[0][pp]!=' ') {
                qq+=code[0][pp];
                pp++;
            }
            //cout<<store+qq<<endl;
            key.push_back(store+qq);
            qq="~";
        }
        if(code[0][j-1]=='\"'&&code[0][j]!='>'&&code[0][j]!=' ') {
            int ww=j;
            for(int z=j;code[0][z]!='\"'&&z<code[0].size();z++) {
                kans+=code[0][z];
            }
           // cout<<kans;
            value.push_back(kans);
            kans="";
        }
    }
    for(int i=1;i<n;i++) {
        string lll;
        if(code[i][1]!='/') {
        int k=1;
        while(code[i][k]!=' ') {
            lll+=code[i][k];
            k++;
        }
    }
        store=store+"."+lll;
        string kans;
        for(int j=i;j<code[i].size();j++) {
        string qq="~";
        if(code[i][j-1]==' '&&code[i][j]!='='&&code[i][j]!='\"') {
            qq+=code[i][j];
            int pp=j+1;
            while(code[i][pp]!=' ') {
                qq+=code[i][pp];
                pp++;
            }
            //cout<<store+qq<<endl;
            key.push_back(store+qq);
            qq="~";
        }
        if(code[i][j-1]=='\"'&&code[i][j]!='>'&&code[i][j]!=' ') {
            // kans+=code[0][j];
            int ww=j;
            for(int z=j;code[i][z]!='\"'&&z<code[i].size();z++) {
                kans+=code[i][z];
            }
            //cout<<kans;
            value.push_back(kans);
            kans="";
        }
    }
    }   
    for(int i=0;i<key.size();i++) {
        cout<<key[i]<<" "<<value[i]<<endl;
    }
    // for(int i=0;i<q;i++) {
    //     cout<<query[i]<<endl;
    // }
    // for(int i=0;i<q;i++) {
    //     bool a=false;
    //     for(int j=0;j<key.size();j++) {
    //         if(query[i]==key[j]) {
    //             cout<<value[j]<<endl;
    //             a=true;
    //             break;
    //         }
    //     }
    //     if(a==false) {
    //         cout<<"Not Found!"<<endl;
    //     }
    // }
    //cout<<key[0]<<query[2]<<endl;
    return 0;
}



