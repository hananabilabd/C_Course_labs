#include <stdio.h>
#include<windows.h>
#define null -32
#include<conio.h>


void strconcatenate(char arr1[],char arr2[]){
    int i=0,j=0,x ,t;
    while ( arr2[i] != '\0'){
        i++;
    }
    while ( arr1[j] != '\0'){
        j++;
    }

    for (x=j,t=0 ;x< i +j ; x++,t++){
        arr1[x] =arr2[t];
    }
    arr1[x]='\0';

}
void strcopy(char arr1[],char arr2[]){
     int i=0,x ;
    while ( arr2[i] != '\0'){
        i++;
    }

      for (x=0;x< i ; x++){
        arr1[x] =arr2[x];
    }
    arr1[x]='\0';

}
int main () {

	int i;
	char arr1[100] ,arr2[100] ,arr3[100],arr4[100];

	printf("Enter First Name=");
	scanf("%s",&arr1[0]);
	printf("Enter Last Name=");
	scanf("%s",&arr2[0]);
	strconcatenate(arr1,arr2);
	printf("Name= %s\n",arr1);
	printf("Enter Source to copy =");
	scanf("%s",&arr4[0]);

	strcopy(arr3,arr4);
	printf("Destination= %s",arr3);







   return(0);
}
