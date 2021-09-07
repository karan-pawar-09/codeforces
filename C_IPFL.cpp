#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void swap(string &y,string &z,int a,int b) {
    char k;
    k=y[a];
    y[a]=z[b];
    z[b]=k;
}
void swapin(string &y,int a,int b) {
    char k;
    k=y[a];
    y[a]=y[b];
    y[b]=k;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    string y=s.substr(0,n);
    string z=s.substr(n,n);
    int q;
    cin>>q;
    int kk=0;
    while(q--) {
        int t,a,b;
        cin>>t>>a>>b;
        a--;
        b--;
        
        if(t==1) {
            if(kk%2) {
                if(a<n) {
                    if(b>=n) {
                        b=b-n;
                        swap(z,y,a,b);
                    }
                    else {
                        swapin(z,a,b);
                    }
                }
                else {
                    a=a-n;
                    b=b-n;
                    swapin(y,a,b);
                }
            }
            else {
                if(a<n) {
                    if(b>=n) {
                        b=b-n;
                        swap(y,z,a,b);
                    }
                    else {
                        swapin(y,a,b);
                    }
                }
                else {
                    a=a-n;
                    b=b-n;
                    swapin(z,a,b);
                }
            }
    
            
        }
        else{
            kk++;
        }
    }    
    if(kk%2) {
        cout<<z<<y<<endl;
    }
    else{
        cout<<y<<z<<endl; 
    }  
    

}