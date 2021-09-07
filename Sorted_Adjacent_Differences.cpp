#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<long> arrp;
        vector<long> arrn;
         int pos = 0;
         int neg = 0;
        for(int i=0;i<n;i++) {           
            long l;
            cin>>l;
            if(l>=0) {
                arrp.push_back(l);
                pos++;
            }
            else {
                arrn.push_back(l);
                neg++;
            }
        }
        sort(arrn.begin(),arrn.end());
        sort(arrp.begin(),arrp.end(),greater<long>());
        
        cout<<pos<<" "<<neg<<endl;
        

        for(int i=0;i<min(pos,neg);i++) {
            
            cout<<arrp[i]<<" "<<arrn[i]<<" ";
            
        }
        
        for(int i=min(pos,neg);i<max(pos,neg);i++) {
            
            if(pos>neg) {
            cout<<arrp[i]<<" ";
            }
            else{
                cout<<arrn[i]<<" ";
            }
        }

        cout<<endl;
        
    }
}