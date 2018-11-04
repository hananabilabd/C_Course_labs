#include <stdio.h>
#include<windows.h>
#define null -32
#include<conio.h>



int main () {

	int i,row;

	printf("Enter Number of Employees You want= ");
	scanf("%d",&row);

	int *col =(int*)malloc(row *sizeof(int));//here define array called columns contains the size of each row
	char  ** input = (char**) malloc(row *sizeof(char*));
	for ( i=0 ; i< row ;i++){
    printf("Enter Number of characters of Employee[%d]= ",i);
	scanf("%d",&col[i]);
	input[i] = (char*) malloc(col[i] * sizeof(char));
	printf("Enter Employee[%d]= ",i);
	scanf("%s",input[i]); // or cab be scanf("%s",&input[i][0])
	}


	for (i =0 ; i< row ;i++){

        printf("Employee[%d]=%s\n",i,input[i]);
	}
	for (i =0 ; i< row ;i++){
            printf("Employee[%d]=",i);
        for (int j =0 ; j <col[i] ;j++){
        printf("%c",input[i][j]);
	}printf("\n");}
    //system("cls");









   return(0);
}
