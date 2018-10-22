#include <stdio.h>
#include<windows.h>
#include <Windows.h>
#define null -32

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
	int n=5, i=1;
	char menu[3][10]={"New" , "Display","Exit"};
   for (i =0 ; i< 3 ; i++){
        printf("%s",menu[i]);
   }
    



   return(0);
}
