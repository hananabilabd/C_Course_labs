#include <stdio.h>
#include<windows.h>

int main () {
	int r ,c ,i ,j,min , max,sum=0 ;
    int x[100][100];
   printf("Enter Array Row Size = ");
	scanf("%d",&r);
	printf("Enter Array Column Size = ");
	scanf("%d",&c);

	for (i = 0 ; i <r ; i++ ){
	for (j = 0 ; j < c;j++ ){
        printf("x[%d][%d] = ",i,j);
        scanf("%d",&x[i][j]);
	}}
	for (i = 0 ; i <r ; i++ ){
	for (j = 0 ; j < c;j++ ){
        printf("x[%d][%d] =%d \n",i,j,x[i][j]);

	}}
	printf("\n\n");

    for (i = 0 ; i <r ; i++ ){
	for (j = 0 ; j <c;j++ ){

        printf("%d\t",x[i][j]);
        sum =sum + x[i][j];

	}
	printf("Sum = %d",sum);
	sum = 0;
	printf("\n");
	}
	//getch();




   return(0);
}
