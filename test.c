#include<stdio.h>
void foo( int m)
{
    int k;
 for(int j=1;j<=m;j++)
 {
 k*=j;
 }
}
int main(){ 
    int n=5;
for(int i=0;i<=foo(n);i++);
}