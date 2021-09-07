#include<stdio.h>

// int minCoins(int coins[4], int m, int V) {
//     int table[V+1];
//     int ans[4];
//     table[0] = 0;
//     for (int i=1; i<=V; i++)
//         table[i] = INT_MAX;
//     for (int i=1; i<=V; i++) {
//         for (int j=0; j<m; j++)
//           if (coins[j] <= i) {
//               int sub_res = table[i-coins[j]];
//               if (sub_res != INT_MAX && sub_res + 1 < table[i]) {
//                   table[i] = sub_res + 1;
//               }
//           }
//     }
//     return table[V];
// }

int main() {
    // int arr[4]={20,10,5,2};
    // int index=0;
    // int value;
    // int arrayofvalues[4]={0,0,0,0};
    // scanf("%d",&value);
    // if(value==0) {
    //     printf("$2 notes = 0");
    // }
    // else {
       
    // }
    // while(index!=4&&value) {
    //     if(value/arr[index]) {
    //         arrayofvalues[index]=value/arr[index];
    //         value-=(value/arr[index])*arr[index];
    //         index++;
    //     }
    //     else {
    //         index++;
    //     }
    // }
    // if(value==0) {
    //     for(int i=0;i<4;i++) {       
    //         if(arrayofvalues[i]!=0) {    
    //         printf("$%d notes = %d, ",arr[i],arrayofvalues[i]);
    //         }
    //     }
    // }
    // else {
    //     printf("Not possible\n");
    // }
    
}