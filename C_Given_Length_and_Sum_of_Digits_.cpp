/*
author:Karan
created:15.06.2021 14:45:37
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
    int m,s;
    cin>>m>>s;
    int k=s;
    int mini=1;
    int maxi=m*9;
    if(m==1&&s==0) {
        cout<<0<<" "<<0<<endl;
    }
    else{
        if(s<mini||s>maxi) {
        cout<<-1<<" "<<-1<<endl;
        }   
        else {
            
            {
                for(int i=0;i<m;i++) {
                    if(i==0){
                        cout<<max(1,max(s-((m-i-1)*9),0));
                        s-=max(1,max(s-((m-i-1)*9),0));
                    }
                    else {
                        cout<<max(0,max(s-((m-i-1)*9),0));
                        s-=max(0,max(s-((m-i-1)*9),0));
                    }
                }
                cout<<" ";
                s=k;
                for(int i=0;i<m;i++) {
                    cout<<min(9,s);
                    s-=min(9,s);
                }
                cout<<endl;
            }
            
        }
    }
    
}