#include <stdio.h>

#include<windows.h>

int main () {
	int n ,i;
int x[100];
   printf("Enter Array Size = ");
	scanf("%d",&n);

	for (i = 0 ; i < n;i++ ){
        printf("x[%d] = ",i);
        scanf("%d",&x[i]);
	}
	for (i = 0 ; i < n;i++ ){
        printf("x[%d]= %d\n",i,x[i]);
	}



   return(0);
}
