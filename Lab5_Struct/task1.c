#include <stdio.h>
#include<windows.h>
#define null -32
#include<conio.h>

typedef struct employee {
    int id ;
    char name[20];
    int salary ;
}Employee;
//typedef struct employee employee ;

int main () {

	int n=5;
	char ch[100] ;
	Employee emp ;
	printf("Enter Employee ID= ");
	scanf("%d",&emp.id);
	printf("Enter Employee Salary= ");
	scanf("%d",&emp.salary);
	printf("Enter Employee Name= ");
	//emp.name=getch();
	scanf("%s",&emp.name);

	printf("\nEmployee ID =%d\n",emp.id);
	printf("Employee Salary =%d\n",emp.salary);
	printf("Employee Name =%s\n",emp.name);








   return(0);
}
