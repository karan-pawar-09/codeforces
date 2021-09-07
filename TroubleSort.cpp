#include<bits/stdc++.h>
using namespace std;
void swap (int *a,int *b) {
    int k;
    k=*a;
    *a=*b;
    *b=k;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int a[n];
        int b[n];
        bool flag=true;
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        for(int i=0;i<n;i++) {
            cin>>b[i];
        }
        for(int i=1;i<n;i++) {
            if(a[i]<a[i-1]){
                flag=false;
            }
        }
        if(flag) {
            cout<<"Yes"<<endl;
        }
        else{
            bool ae=true;
            for(int i=1;i<n;i++) {
                if(b[i]!=b[i-1]) {
                    ae=false;
                }
            }
            if(ae){
                cout<<"No"<<endl;
            }
            else{
                cout<<"Yes"<<endl;
            }
        }
    }
}