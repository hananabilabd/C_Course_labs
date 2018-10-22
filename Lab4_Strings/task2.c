#include <stdio.h>
#include<windows.h>
#define null -32
#include<conio.h>
#include<string.h>

int main () {

	int n=5, i=1;
	char str1[100] ;
	char str2[100] ;
	printf("Enter First Name= ");
	scanf("%s",str1 );

	printf("Enter Second Name= ");
    scanf("%s",str2);
    strcat(str1," ");
    strcat(str1, str2);
    printf("Full Name= %s",str1);






   return(0);
}
