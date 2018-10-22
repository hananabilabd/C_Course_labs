
#include <stdio.h>
#include<windows.h>
#define null -32
#include<conio.h>

 struct employee {
    int id ;
    char name[20];
    int salary ;
};
typedef struct employee employee ;

int main () {

	int i,n;
	char ch[100] ;
	//employee emp[5] ;
	//employee *p = &emp ;
	printf("Enter Employee Number you wanna assign=");
	scanf("%d",&n);
	employee * p=(employee*) malloc (n*sizeof(employee));

	for (i =0 ; i<n ; i++) {
        printf("Enter Employee.ID[%d]= ",i);
	scanf("%d",&p[i].id);
	printf("Enter Employee.Salary[%d]= ",i);
	scanf("%d",&p[i].salary);
	printf("Enter Employee.Name[%d]= ",i);
	scanf("%s",&p[i].name); //Can be scanf("%s",emp[i].name);
	}

for (i =0 ; i<3 ; i++) {
	printf("\nEmployee.ID[%d] =%d\n",i,p[i].id);
	printf("Employee.Salary[%d]=%d\n",i,p[i].salary);
	printf("Employee.Name[%d] =%s\n",i,p[i].name);

}






   return(0);
}
