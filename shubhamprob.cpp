
/*
author:Karan
created:23.05.2021 16:44:51
*/
#include<bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'


string sumBig(string a, string b)
{
  
    // Compare their lengths
    if (a.length() > b.length())
        swap(a, b);
  
    // Stores the result
    string str = "";
  
    // Store the respective lengths
    int n1 = a.length(), n2 = b.length();
  
    int diff = n2 - n1;
  
    // Initialize carry
    int carry = 0;
  
    // Traverse from end of both strings
    for (int i = n1 - 1; i >= 0; i--) {
  
        // Compute sum of
        // current digits and carry
        int sum
            = ((a[i] - '0')
               + (b[i + diff] - '0') + carry);
  
        // Store the result
        str.push_back(sum % 10 + '0');
  
        // Update carry
        carry = sum / 10;
    }
  
    // Add remaining digits of str2[]
    for (int i = n2 - n1 - 1; i >= 0; i--) {
  
        int sum = ((b[i] - '0') + carry);
  
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
  
    // Add remaining carry
    if (carry)
        str.push_back(carry + '0');
  
    // Reverse resultant string
    reverse(str.begin(), str.end());
  
    return str;
}
  
// Function return 10's
// complement of given number
string compliment10(string v)
{
    // Stores the compliment
    string compliment = "";
  
    // Calculate 9's compliment
    for (int i = 0; i < v.size(); i++) {
  
        // Subtract every bit from 9
        compliment += '9' - v[i] + '0';
    }
  
    // Add 1 to 9's compliment
    // to find 10's compliment
    compliment = sumBig(compliment, "1");
    return compliment;
}
  
// Function returns subtraction
// of two given numbers as strings
string subtract(string a, string b)
{
  
    // If second string is larger
    if (a.length() < b.length())
        swap(a, b);
  
    // Calculate respective lengths
    int l1 = a.length(), l2 = b.length();
  
    // If lengths aren't equal
    int diffLen = l1 - l2;
  
    for (int i = 0; i < diffLen; i++) {
  
        // Insert 0's to the beginning
        // of b to make both the lengths equal
        b = "0" + b;
    }
  
    // Add (complement of B) and A
    string c = sumBig(a, compliment10(b));
  
    // If length of new string is greater
    // than length of first string,
    // than carry is generated
    if (c.length() > a.length()) {
        string::iterator it;
  
        // Erase first bit
        it = c.begin();
  
        c.erase(it);
  
        // Trim zeros at the begnning
        it = c.begin();
  
        while (*it == '0')
            c.erase(it);
  
        return c;
    }
  
    // If both lengths are equal
    else {
        return compliment10(c);
    }
}
// Get size of the numbers
int getSize(string num)
{
    return num.size();
}
string add(string number1,string number2) {
   if (number1.length() > number2.length())
    swap(number1, number2);
   string sum = "";
   int len1 = number1.length();
   int len2 = number2.length();
   int digitDiff = len2 - len1;
   int carry = 0;
   int intSum;
   for (int i=len1-1; i>=0; i--) {
      intSum = ((number1[i]-'0') + (number2[i+digitDiff]- '0') + carry);
      sum.push_back(intSum%10 + '0');
      carry = intSum/10;
   }
   for (int i=digitDiff-1; i>=0; i--) {
      intSum = ((number2[i]-'0')+carry);
      sum.push_back(intSum%10 + '0');
      carry = intSum/10;
   }
   if (carry)
    sum.push_back(carry+'0');
   reverse(sum.begin(), sum.end());
   return sum;
}
string append(string a,int c) {
    for(int i=0;i<c;i++) {
        a+="0";
    }
    return a;
}
string karatsuba(string X, string Y)
{
    // Base Case
    if (X.size()==1&& Y.size()==1)
        return to_string((X[0]-'0') * (Y[0]-'0'));

    // determine the size of X and Y
    int size =(int) X.size();
    // int xsize=X.size();
    // int ysize=Y.size();
    // Split X and Y
    int n = size/2;
    // long long int p = (long long int)pow(10, n);
    string a = X.substr(0,n);
    string b = X.substr(n,size-n);
    string c = Y.substr(0,n);
    string d = Y.substr(n,size-n);

    // Recur until base case
    string ac = karatsuba(a, c);
    string bd = karatsuba(b, d);
    // string e =subtract(subtract(karatsuba(sumBig(a,b), sumBig(c,d)),ac), bd);
    string ad=karatsuba(a,d);
    string bc=karatsuba(b,c);
    ac=append(ac,size);
    ad=append(ad,n);
    bc=append(bc,n);
    ac=add(ac,bd);
    bc=add(bc,ad);
    string ans=add(ac,bc);
    return ans;
}

int main() {
    string X,Y;   cin>>X>>Y;
    string ans = karatsuba(X,Y);
    cout<<ans;
}