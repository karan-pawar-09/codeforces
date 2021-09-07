#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        long a;
        int k;
        cin>>a>>k;
        if((a%2!=0&&k%2==0)||((k>=(a-1)&&k!=a))) {
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            if(a%2==0){
                if(k==1) {
                    cout<<a;
                }
                else if(k==a){
                    for(int i=0;i<k;i++) {
                        cout<<"1"<<" ";
                    }
                    
                }
                else{
                    for(int i=0;i<(k-1);i++){
                        cout<<"2"<<" ";
                    }
                    cout<<a-(2*(k-1));
                }
            }
            else{

                if(k==1) {
                    cout<<a;
                }
                else if(k==a){
                    for(int i=0;i<k;i++) {
                        cout<<"1"<<" ";
                    }
                    
                }
                else{
                    for(int i=0;i<(k-1);i++){
                        cout<<"1"<<" ";
                    }
                    cout<<a-(1*(k-1));
                }

            }
            cout<<endl;
        }

    }
}