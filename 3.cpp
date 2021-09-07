#include<bits/stdc++.h>
using namespace std;
int main() {
	long long n,m,a;
	cin>>n>>m>>a;
if(n>a&&m>a){

	if(n%a!=0&&m%a!=0) {
			cout<<((n/a)+1) * ((m/a)+1);
		}
	else if(n%a!=0&&m%a==0) {
			cout<<((n/a)+1) * (m/a);
		}
	else if(n%a==0&&m%a!=0) {
			cout<<(n/a) * ((m/a)+1);
		}
	else {
			cout<<(n/a) * (m/a);
		}
}
else if( n>a&&m<=a) {
		if(n%a!=0&&m%a!=0) {
			cout<<(n/a)+1;
		}
	else if(n%a!=0&&m%a==0) {
			cout<<(n/a)+1;
		}
	else if(n%a==0&&m%a!=0) {
			cout<<(n/a);
		}
	else {
			cout<<(n/a);
		}
	
}
else if( n<=a&&m>a) {
		if(n%a!=0&&m%a!=0) {
			cout<<(m/a)+1;
		}
	else if(n%a!=0&&m%a==0) {
			cout<<(m/a)+1;
		}
	else if(n%a==0&&m%a!=0) {
			cout<<(m/a);
		}
	else {
			cout<<(m/a);
		}
	
}
else{
	cout<<"1";
}

}
