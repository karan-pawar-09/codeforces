    #include<bits/stdc++.h>     
    using namespace std;
    typedef long long LL;         
    int main(){
    	int T;
    	cin>>T;
    	while(T--) {
    		LL a, b;
    		int c1 = 0, c2 = 0;
    		cin>>a>>b;
    		while (a % 2 == 0) c1++, a /= 2;
    		while (b % 2 == 0) c2++, b /= 2;
    		if (a != b) printf("-1\n");
    		else {
    			int Remainder = abs(c1 - c2);
    			int ans = Remainder / 3;
    			Remainder %= 3;
    			ans += Remainder / 2;
    			Remainder %= 2;
    			ans += Remainder;
    			cout<<ans<<endl;
    		}
    	}
    }