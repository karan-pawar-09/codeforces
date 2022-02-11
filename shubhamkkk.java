import java.util.*;

import java.lang.*;

import java.io.*;

 class shubhamkkk

{

public static void main (String[] args) throws Exception

{

     

    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();

    int a[] = new int[n];

    for(int i=0;i<n;i++)

        a[i] = sc.nextInt();

    int max=a[0], min=a[0];

    for(int i=1;i<n;i++) {

        if(a[i] > max)

            max = a[i];

        if(a[i] < min)

            min = a[i];

    }

    int sum = max+min;

    System.out.println(sum);

}

}