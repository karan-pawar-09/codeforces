#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c;
    int n;
    cin>>n;    
    if(n==1) {
        cout<<"? 1"<<endl;
        cout.flush();
        cin>>a;
        cout<<"! "<<a<<endl;
        return 0;
    }
    if(n!=1) {
          cout<<"? 1"<<endl;  
        cout.flush();  
        cin>>a;
        cout<<"? 2"<<endl;
        cout.flush();
        cin>>b;
        if(a<b) {
            cout<<"! 1"<<endl;
            cout.flush();
            return 0;
        }
        cout<<"? "<<n<<endl;  
        cout.flush();  
        cin>>a;
        cout<<"? "<<n-1<<endl;
        cout.flush();
        cin>>b;
        if(a<b) {
            cout<<"! "<<n<<endl;
            cout.flush();
            return 0;
        }
    }
    int l=1;
    int r=n+1;
    bool ans=true;
    ll answer=-1;
    while(r>=l&&ans) {
        int m=l+(r-l)/2;
        cout<<"? "<<m<<endl;
        cout.flush();
        cin>>a;
       
        
        if(m==1) {
            c=(ll)1e18;
        }
        else {
            cout<<"? "<<m-1<<endl;
            cout.flush();
            cin>>c;
        }
        if(m==n) {
            b=(ll)1e18;
        }
        else {
             cout<<"? "<<m+1<<endl;
            cout.flush();
            cin>>b;
        }
        if(a>b) {
            l=m;
        }
        else {
            r=m;
        }

        if(a<b&&a<c) {
            answer=m;
            ans=false;
        }
    }
    cout<<"! "<<answer<<endl;
}