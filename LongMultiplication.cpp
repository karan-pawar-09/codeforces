#include<bits/stdc++.h> 
#include<string>
#include <sstream>
using namespace std; 
string f[1007];
namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}  
string findSum(string str1, string str2) 
{ 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
    string str = ""; 
    int n1 = str1.length(), n2 = str2.length(); 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
    if (carry) 
        str.push_back(carry+'0'); 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 
string multiply(string num1, string num2) 
{ 
    int len1 = num1.size(); 
    int len2 = num2.size(); 
    if (len1 == 0 || len2 == 0) 
    return "0"; 
    vector<int> result(len1 + len2, 0);  
    int i_n1 = 0;  
    int i_n2 = 0;  
    for (int i=len1-1; i>=0; i--) 
    { 
        int carry = 0; 
        int n1 = num1[i] - '0'; 
        i_n2 = 0;             
        for (int j=len2-1; j>=0; j--) 
        {
            int n2 = num2[j] - '0'; 
            int sum = n1*n2 + result[i_n1 + i_n2] + carry; 
            carry = sum/10; 
            result[i_n1 + i_n2] = sum % 10; 
            i_n2++; 
        } 
        if (carry > 0) 
            result[i_n1 + i_n2] += carry;  
        i_n1++; 
    } 
    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) 
    i--; 
    if (i == -1) 
    return "0"; 
    string s = "";       
    while (i >= 0) 
        s += patch::to_string(result[i--]);   
    return s; 
} 
string fib(int n) 
{     
    if (n == 0) 
        return "0"; 
    if (n == 1 || n == 2) 
        return (f[n] = "1"); 
       if (f[n].size()) 
        return f[n]; 
    int k = (n & 1)? (n+1)/2 : n/2; 
    f[n] = (n & 1)? findSum(multiply(fib(k),fib(k)),multiply(fib(k-1),fib(k-1))): multiply(findSum(multiply("2",fib(k-1)),fib(k)),fib(k)); 
    return f[n]; 
}
int main() {
    int a;
    cin>>a;
    cout<<fib(a)<<endl;
}