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

	int i;
	char ch[100] ;
	employee emp[5] ;
	for (i =0 ; i<3 ; i++) {
        printf("Enter Employee.ID[%d]= ",i);
	scanf("%d",&emp[i].id);
	printf("Enter Employee.Salary[%d]= ",i);
	scanf("%d",&emp[i].salary);
	printf("Enter Employee.Name[%d]= ",i);
	scanf("%s",&emp[i].name); //Can be scanf("%s",emp[i].name);
	}

for (i =0 ; i<3 ; i++) {
	printf("\nEmployee.ID[%d] =%d\n",i,emp[i].id);
	printf("Employee.Salary[%d]=%d\n",i,emp[i].salary);
	printf("Employee.Name[%d] =%s\n",i,emp[i].name);

}






   return(0);
}
