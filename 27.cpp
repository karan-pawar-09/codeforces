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
        for(int i=0;i<n;i++) {
            long l;
            cin>>l;
            if(l>=0) {
                arrp.push_back(l);
            }
            else {
                arrn.push_back(l);
            }
        }
        sort(arrn.begin(),arrn.end());
        sort(arrp.begin(),arrp.end(),greater<long>());
        int pos=arrp.size();
        int neg = arrn.size();
        int min_neg= abs(*(min_element(arrn.begin(),arrn.end())));
        int max_pos= abs(*(max_element(arrp.begin(),arrp.end())));
        for(int i=0;i<min(pos,neg);i++) {
            if(max_pos>min_neg) {
            cout<<arrp[i]<<" "<<arrn[i];
            }
            else{
                cout<<arrn[i]<<" "<<arrp[i];
            }
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