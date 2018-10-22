#include <stdio.h>

#include<windows.h>

int main () {
	int n ,i ,min , max ;
int x[100];
   printf("Enter Array Size = ");
	scanf("%d",&n);


	for (i = 0 ; i < n;i++ ){
        printf("x[%d] = ",i);
        scanf("%d",&x[i]);
	}
	min = x[0];
	max = x[0];
	for (i = 0 ; i < n;i++ ){
            if (x[i]> max ){
                max = x[i];
            }
            if ( x [i] < min){
                min = x[i];
            }

	}
	 printf("Max =%d\n",max);
        printf("Min =%d\n",min);



   return(0);
}
