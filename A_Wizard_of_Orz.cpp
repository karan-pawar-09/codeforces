#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int N;
    	cin >> N; 
    	cout << 9; 
    	int cont = 8;
    	for(int i = 0 ; i < N-1 ; i++)	{
    		cout << cont;
    		cont = (cont+1)%10;
    	} 
    	cout << '\n';
    }
}