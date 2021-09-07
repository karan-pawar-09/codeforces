#include <stdio.h>
#include<string.h>
#include <cstdlib>

struct Student{
  char name[20];
  char id[20];
  char phNo[10];
};

void print(struct Student st[]){
    
    printf("\nStudent details are as follow: ");
    for(int i = 1; i<=2; i++){
        printf("\nStudent %d name: %s\nStudent %d id: %s\nStudent %d phone number: %s",i,st[i-1]->name,i,st[i-1]->id,i,st[i-1]->phNo);
    }
}

int main()
{   
    
    printf("Enter the details of 5 students: ");
    struct Student *st=(struct Student *)malloc(5 * sizeof(struct Student));
    for(int i = 1; i <= 2; i++ ){
        printf("\nEnter %dth student name: ",i);
        scanf("%s",&(st[i-1].name));
        printf("\nEnter %dth student's id: ",i);
        scanf("%s",&(st[i-1].id));
        printf("\nEnter %dth student's phone number: ",i);
        scanf("%s",&(st[i-1].phNo));
        
    }
    
    print(&st);
    return 0;
}