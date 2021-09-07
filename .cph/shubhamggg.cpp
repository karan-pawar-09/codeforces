/*
author:Karan
created:17.08.2021 18:17:55
*/
#include <bits/stdc++.h>
using namespace std;
#define SIZE (int) 1e6+7

int P[SIZE * 2];

string convertToNewString(const string &s) {
    string newString = "@";
    for (int i = 0; i < s.size(); i++) {
        newString += "#" + s.substr(i, 1);
    }
    newString += "#$";
    return newString;
}

int longestPalindromeSubstring(const string &s) {
    string Q = convertToNewString(s);
    int c = 0, r = 0;
    for (int i = 1; i < Q.size() - 1; i++) {
        int iMirror = c - (i - c);
        if(r > i) {
            P[i] = min(r - i, P[iMirror]);
        }
        while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]]){
            P[i]++;
        }
        if (i + P[i] > r) {
            c = i;        
            r = i + P[i];
        }
    }
    int maxPalindrome = 0;
    int centerIndex = 0;
    for (int i = 1; i < Q.size() - 1; i++) {
        if (P[i] > maxPalindrome) {
            maxPalindrome = P[i];
            centerIndex = i;
        }
    }
    return maxPalindrome;
}
int difference(string input1) {
    return longestPalindromeSubstring(input1)-1;
}
int main() {
    string s;
    cin>>s;
    cout<<difference(s)<<endl;
    return 0;
}