#include <stdio.h>
#include<windows.h>
#define null -32
#include<conio.h>
void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

}

 void gotoxy(int x,int y)
 {
   COORD coord={0,0};
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

int main () {
    while ( 1){
	char ch ;
	printf("Enter Any Character \n ");
   ch = getch();
   if (ch == -32){
	   printf("You've Entered Extened Character =");
	   ch = getch();
	   printf("%d\n",ch); // up = 72  down = 80  home = 71  end = 79
   }
   else {
	   printf("You've Entered Normal Character =");
	   printf("%d\n",ch);
   }}


   return(0);
}
