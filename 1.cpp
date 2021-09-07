/*
author:Karan
created:30.07.2021 02:00:08
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int calculate(string s) {
        stack<string> st;
        int n=s.size();
        int no=0;
        bool strt=false;
        for(int i=0;i<n;i++) {  
                     
            while(s[i]==' ') i++;
            if(s[i]==')') {    
                st.push(")");        
            }
            else if(s[i]=='(') {
                st.push("(");
            }
            else {
                string ss;
                if(s[i]=='-') {
                    ss.push_back(s[i]);
                    i++;
                }
                else if(s[i]=='+') {
                    i++;
                }
                while(s[i]>='0'&&s[i]<='9') {
                    ss.push_back(s[i]);
                    i++;
                }
                i--;
                if(ss.size())
                st.push(ss);
            
            }
            
        }
        while(!st.empty()) {   
            if(st.top().size()!=0) {
                if(st.top()==")") {    
                    st.pop();
                    int temp=0;            
                    while(st.top()!="(") {
                        while(st.top().size()==0) {
                            st.pop();
                        }
                        if(st.top().size()!=0) {
                            if(st.top()=="-") {
                                temp*=-1;
                                st.pop();
                            }
                            else 
                            temp+=stoi(st.top());
                        }
                        st.pop();
                    }
                    while(st.top().size()==0) {
                        st.pop();
                    }
                    if(st.top()=="(") {
                        st.pop();
                    }  
                    if(st.size()>1&&st.top()=="-") {
                        temp*=-1;
                        st.pop();
                    }  
                    no+=temp;            
                }
                if(st.top()=="-") {
                    no*=-1;
                }
                else 
                no+=stoi(st.top());
            }                
            st.pop();
        }
        return no;
    }

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    string s="- (3 + (4 + 5))";
    int n=calculate(s);
    cout<<n<<endl;
}