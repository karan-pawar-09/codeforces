#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int a;
        cin>>a;

        int num = a; 
  
    
        ostringstream str1; 
  
        str1 << num; 
  
   
        string str = str1.str(); 
        vector<int> ans;

        int size=str.size();

        int zeros=0;

        for(int i=0;i<size;i++) {
            if(str[i]=='0'){
                zeros++;
            }
            else{
                int aaa=(str[i])-'0';
                int aq= aaa*((int)((pow(10,(size-(i+1))))+.5));
                ans.push_back(aq);
            }
        }
        if(size!=zeros){
        cout<<size-zeros<<endl;
        for(int j=0;j<ans.size();j++) {
            cout<<ans[j]<<"  ";
        }
        cout<<endl;

        }
        else{
            cout<<"1"<<endl<<num;
        }
    }
}