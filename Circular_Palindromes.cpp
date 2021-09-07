#include<bits/stdc++.h>
using namespace std;
#define ll long long
int longestPalSubstr(string str) {
    int maxLength = 1; 
    int start = 0; 
    int len = str.size(); 
    int low, high;  
    for (int i = 1; i < len; ++i) { 
        low = i - 1; 
        high = i; 
        while (low >= 0 && high < len 
               && str[low] == str[high]) { 
            if (high - low + 1 > maxLength) { 
                start = low; 
                maxLength = high - low + 1; 
            } 
            --low; 
            ++high; 
        } 
        low = i - 1; 
        high = i + 1; 
        while (low >= 0 && high < len 
               && str[low] == str[high]) { 
            if (high - low + 1 > maxLength) { 
                start = low; 
                maxLength = high - low + 1; 
            } 
            --low; 
            ++high; 
        } 
    }    
    return maxLength; 
} 
  
  
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int  n;
    cin>>n;
    string s;
    cin>>s;
    string str=s+s;
    for(int i=0;i<n;i++) {
        cout<<longestPalSubstr(str.substr(i,n))<<"\n";
    }
}