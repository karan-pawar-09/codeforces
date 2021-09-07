/*
author:Karan
created:25.06.2021 15:40:52
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()


void Calc(int arr[],int n)
{
  
  int i=2;
  while(i<=n)
  {
    int c1=(int)1e9,c2=(int)1e9,c3=(int)1e9;
    c1 = arr[i-1] + 1;
    if(i%2==0)
    {
      c2 = arr[i/2] +1;
    }
    if(i%3==0)
    {
      c3  = arr[i/3] +1;
    }

    arr[i] = min(min(c1,c2),min(c2,c3));
    i++;
  }
  
}

int check_oper(int i,int curr_i)
{
  if(i+1 == curr_i)  return 1;
  if(i*2 == curr_i)  return 1;
  if(i*3 == curr_i)  return 1;
  return 0;
}

vector<int> Primitive_Calc(int arr[],int n)
{
  vector<int> seq;
  seq.push_back(n);
  int i=n;
  int curr_i = i;
  while(curr_i>=2)
  {
    
    if((arr[i] != (arr[curr_i]-1)) ) {
        i--;
    }
    else {
        if(check_oper(i,curr_i)) {
            seq.push_back(i); 
            curr_i=i;
        }
        i--;
    }
      
  }
  reverse(seq.begin(),seq.end());
  return seq;
}

int main() {
  int n;
  std::cin >> n;  
  int arr[n+1]={0};
  Calc(arr,n);   
  vector<int> sequence = Primitive_Calc(arr,n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}