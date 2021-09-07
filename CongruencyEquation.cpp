#include <iostream>
using namespace std;
string findSum(string str1, string str2) 
{ 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
  

    string str = "";  
 
    int n1 = str1.length(), n2 = str2.length(); 
    int diff = n2 - n1;    
    int carry = 0;   
    for (int i=n1-1; i>=0; i--) 
    { 
        int sum = ((str1[i]-'0') + 
                   (str2[i+diff]-'0') + 
                   carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    for (int i=n2-n1-1; i>=0; i--) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    }   
 
    if (carry) 
        str.push_back(carry+'0'); 
  
    
     for (int i = 0; i < str.length()/ 2; i++)
     {
        swap(str[i], str[ str.length()- i - 1]); 
    
     } 
  
   return str; 
}
int main()
{
    string a="0";
    string b="1";
    int n;
    string next;
    cin>>n;
    int count=2;
    while(count<=n)
    { 
        next=findSum(a,b);
        a=b;
        b=next;
        count++;
    }
   cout<<b;
}   