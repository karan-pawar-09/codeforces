#include <iostream>
using namespace std;

int main() {
	int i,j,k,l,n;
	cout<<"enter n\n";
	cin>>n;
	i=1;
	while(i<=3){
	      for(j=1;j<=n;j=j+4){
	        cout<<"*";
	    }
	    i++;
	    for(k=2;k<=n;k=k+2){
	       cout<<"*"; 
	    }
	    i++;
	      for(l=3;l<=n;l=l+4){
	        cout<<"*";
	    }
	    i++;
	    cout<<endl;
	}
	return 0;
}