#include<stdio.h>
int main() {
    int x1,y1,x2,y2;
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    int num=y2-y1;
    int den=x2-x1;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int tempnum,tempden;
        int a,b;
        scanf("%d %d",&a,&b);
        tempnum=b-y2;
        tempden=a-x2;
        if(den*(b-y2)==num*(a-x2)) {
            printf("STRAIGHT ");
        }
        else if(den*(b-y2)<num*(a-x2)) {
            printf("RIGHT ");
        }
        else {
            printf("LEFT ");
        }
        num=tempnum;
        den=tempden;
    }
}
 