#include<bits/stdc++.h>
#include<sstream>
using namespace std;
vector<string> ans(vector<string> a) {
	
	
	vector<string> answer;
	for(int i=0;i<a.size();i++) {
		int l=a[i].size();
		if(l<=10){
			answer.push_back(a[i]);
		}
		else {
		int z=l-2;
		stringstream ss;
		ss<<z;
		string asd=ss.str();
		string f=a[i][0]+asd+a[i][l-1];
		answer.push_back(f);
	}}
	return answer;
}
int main() {
	int k;
	cin>>k;
	vector<string> s;
	for(int i=0;i<k;i++) {
		string t;
		cin>>t;
		s.push_back(t);
	}
	
	vector<string> aaa=ans(s);
	for(int i=0;i<k;i++) {
		cout<<aaa[i]<<endl;
	}
}
