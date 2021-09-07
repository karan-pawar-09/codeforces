#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        long a,b,c,d;
        cin>>a>>b>>c>>d;
        long x,y,x1,x2,y1,y2;
        cin>>x>>y>>x1>>y1>>x2>>y2;
        long horizontal=x-a+b;
        
        long vertical=y-c+d;

      //  bool a=true;
      if((x1==x2)&&(y1==y2)){
          cout<<"No"<<endl;
      }
      else if(((x1==x2)&&((a||b)!=0))) {
          cout<<"No"<<endl;
      }
      else if(((y1==y2)&&((c||d)!=0))) {
          cout<<"No"<<endl;
      }
      else{
        if(((horizontal<x1)||(horizontal>x2))||((vertical<y1)||(vertical>y2))) {
            cout<<"No"<<endl;
        }
        else {
            cout<<"Yes"<<endl;
        }
        
      }
    }
}