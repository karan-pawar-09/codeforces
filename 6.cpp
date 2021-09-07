#include<bits/stdc++.h>
using namespace std;
string ans(string k) {
	for(int i=k.size()-1;i>=0;i--) {
		if(k[i]=='a'||k[i]=='e'||k[i]=='i'||k[i]=='o'||k[i]=='u'||k[i]=='A'||k[i]=='E'||k[i]=='I'||k[i]=='O'||k[i]=='U'||k[i]=='y'||k[i]=='Y'){
			k.erase(k.begin()+i);
		}
	
	}
	for(int i=k.size()-1;i>=0;i--) {
			if(k[i]<97) {
			k[i]+=32;
		}	
		}
		
		for(int i=k.size()-1;i>=0;i--) {
			k.insert(i,".")	;	
		}
		return k;
}
int main() {
	string a;
	cin>>a;
	string d=ans(a);
	cout<<d;
}
