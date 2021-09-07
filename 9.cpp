#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	int t=0;
	while(n--) {
        string s;
        cin>>s;
        for(int i=0;i<3;i++) {
            if(s[i]=='+') {
                t++;
                break;
            }
            else if(s[i]=='-') {
                t--;
                break;
            }
        }

	}
	 cout<<t;
}
