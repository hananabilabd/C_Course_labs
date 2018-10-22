#include <stdio.h>
#include<windows.h>
#define null -32
#include<conio.h>



int main () {

	int i;
	int arr[100] ;
	int *p = arr;
	printf("\nUsing Pointer\n");
    for (i=0 ;i<5;i++){
	printf("Enter p[%d]= ",i);
	scanf("%d",p+i);
    }
     for (i=0 ;i<5;i++){
	printf("\nEnter p[%d]=%d ",i,*(p+i));

    }

    printf("\nUsing Array\n");
    for (i=0 ;i<5;i++){
	printf("Enter p[%d]= ",i);
	scanf("%d",&p[i]);
    }
       for (i=0 ;i<5;i++){
	printf("\nEnter p[%d]=%d ",i,p[i]);

    }









   return(0);
}
