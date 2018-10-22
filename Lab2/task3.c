#include <stdio.h>
#include<string.h>
#include<windows.h>
 void gotoxy(int x,int y)
 {
   COORD coord={0,0};
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

// A function to generate odd sized magic squares
void generateSquare(int n)
{
    int i,c,r;

    //printf("n=%d\n",n );

    for(i=1;i<=n*n;i++)
    {
        //r=(n-i%n+1+2*((i-1)/n))%n;    // for row  //
        //c=((n-1)/2+i-1-(i-1)/n)%n;   // for column //
        if ( i==1){
            c = (n +1 ) /2 ;
            r =1;

        }
         else if ( (i-1) %n == 0){
            r++;
            if (r > n){r=1;}

        }
        else {
            r--;
            c--;
            if (r <= 0 ){r = n; }
            if (c <= 0 ){c = n; }
        }


       gotoxy(c,r*3);
       printf("%d",i);


    }
getch();
/*
    for(r=0;r<n;r++)
    {
        for(c=0;c<n;c++)
        {
            printf("%d\t",arr[r][c]);
        }
        printf("\n");
    }
*/

}
int main () {
	int n ;
    int i,c,r;
   printf("Enter Magic Square Size to be greater than 1 and odd = ");
	scanf("%d",&n);
	while ( n % 2 ==0 ){
		printf ("please Enter Size to be greater than 1 and odd = " );
		scanf("%d",&n);
	}


    for(i=1;i<=n*n;i++)
    {

        if ( i==1){
            c = (n +1 ) /2 ;
            r =1;

        }
         else if ( (i-1) %n == 0){
            r++;
            if (r > n){r=1;}

        }
        else {
            r--;
            c--;
            if (r <= 0 ){r = n; }
            if (c <= 0 ){c = n; }
        }


       gotoxy(c*3,r*3);
       printf("%d",i);

    }
getch();


   return(0);
}
