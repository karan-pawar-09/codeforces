#include<stdio.h>
#include<string.h>

const int mx=100000;

int main() {
    char s[mx];
    char str[mx];
    int k;
    scanf("%d",&k);
    scanf("%s",s);    
    int n=strlen(s);
    int val[mx];
    int is[mx];
    for(int i=0;i<mx;i++) {
        val[i]=0;
        is[i]=0;
    }
    int j=0;
    for(int i=0;i<n;i++) {
        if(s[i]<'a') {
            int value=s[i]-'0';
            i++;
            while(s[i]<'a') {
                value*=2;
                value+=s[i]-'0';
                i++;
            }
            if(i>=n) {
                break;
            }
            str[j]='*';
            val[j]=value;
            j++;
            str[j]=s[i];
            j++;
        }
        else {
            str[j]=s[i];
            j++;
        }
    }
    j=0;
    int prev=0;    
    for(int i=0;i<=k;i++) {                
        if(str[j]=='*') {
            if(val[j]==0&&!is[j]) {
                i=0;
                j=j+1;
            }
            else{
                is[j]=1;
                if(--val[j]) {
                    j=prev;                
                }  
                else {
                    prev=j+1;
                    j=j+1;
                } 
            }
        
        }
        else
            j++; 
            
        
    }
    if(str[j]=='*') {
        if(val[j]) {
            val[j]--;
            j=prev;                
        } 
        else {
            j++;
        }
    }
    printf("\n\n%c",str[j]);
}