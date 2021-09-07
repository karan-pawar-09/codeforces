#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>A(n);
    for(int i=0;i<n;i++) {
        cin>>A[i];
    }
    if(A.size()<3) {
           return 0;
       }
        int ans=0;
        int finalans=0;
        bool increasing=false; 
        bool mountain=false;
       for(int i=1;i<A.size();i++) {
            if(i!=A.size()-1) {
                if(A[i]>A[i-1]&&A[i]>A[i+1]) {
                    mountain=true;
                }
            }
            if(A[i]>A[i-1]) {
                if(increasing){                
                    ans++;
                    finalans=max(finalans,ans);
                }
                else {
                    ans=0;
                    ans++;
                    finalans=max(finalans,ans);
                    increasing=true;
                }
                
            }
            else if(A[i]<A[i-1]){               
                    increasing =false;
                    ans++;    
                    finalans=max(ans,finalans);
            }
            else if(A[i]==A[i-1]) {
                increasing=false;
                ans=0;
            }
        }
        if(finalans==0) 
            cout<<"0\n";
        else
            cout<<finalans+1<<endl;
}