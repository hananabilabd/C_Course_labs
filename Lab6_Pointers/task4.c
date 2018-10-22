#include <stdio.h>
#include<windows.h>
#define null -32
#define line 0
char menu[3][10]={"New" ,"Display","Exit"};
void display_Items(state){
    int i ;
  for (i =0 ; i< 3 ; i++){
                if (i==state){
                    textattr(20);// Red = 4 and White = 7
                    printf("%s\n",menu[i]);
                    textattr(15);
                }
                else {
                    textattr(15);// Red = 4 and White = 7
                    printf("%s\n",menu[i]);

                }

		}}

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
    int  cursorX=0 ,end =0 ,i,left_trim,esc =0;
	char ch ;
	char  input[200];

    while ( esc !=1){

	//printf("Enter Any Character \n ");
   ch = getch();
   if (ch == -32){

	   ch = getch();
	   if (ch==75){//left arrow
	       cursorX--;
	       if (cursorX <0){cursorX =0;}
           gotoxy(cursorX ,line);


	   }
	   else if(ch ==77){//right arrow
	       cursorX++;
	       if (cursorX <=end){
            gotoxy(cursorX,line);
            //end =cursorX+1;
	       }
	       else{
            cursorX =end;
	       }
	   }
	   else if(ch ==71){//home
	        cursorX=0;
            gotoxy(cursorX,line);
            cursorX=-1;
	   }
	   else if(ch ==79){//end
	       cursorX=end;
            gotoxy(cursorX,line);

	   }
	    else if (ch==115){//ctrl+left arrow

	       if (cursorX <0){cursorX =0;}
           gotoxy(cursorX ,line);

	   textattr(20);
	   printf("%c",input[cursorX]);
	   textattr(7);//  White = 15
	   cursorX--;
	   left_trim = cursorX;
   }
        else if (ch==116){//ctrl+right arrow

         if (cursorX <0){cursorX =0;}
           gotoxy(cursorX ,line);
	   textattr(20);
	   printf("%c",input[cursorX]);
	   textattr(7);//  White = 15 or 7
	   cursorX++;

   }

   }
   else if (ch==13){//Enter

       gotoxy(0,2);
	   printf("You've Entered =");
	   printf("%s",input);
   }
   else if ( ch >= 65 && ch <=122){ //handling from A =65 to Z=90 and from a=97 to z=122

        //if (cursorX ==0){cursorX++;}

        if (cursorX == end){
            gotoxy(cursorX ,line);
            printf("%c",ch);
            input[cursorX]=ch;
            input[cursorX+1]='\0';
            end++;
        }
        else if (cursorX< end){
            gotoxy(cursorX ,line);
            printf("%c",ch);
            input[cursorX]=ch;
        }
        //end =cursorX;

        cursorX++;

   }
   else if(ch ==32){ //space
       cursorX++;
       gotoxy(cursorX ,line);
        printf("%c",' ');
        input[cursorX]=ch;
        end =cursorX;
        input[cursorX+1]='\0';

   }
   else if (ch ==3){//ctrl +c
        for (i=cursorX ; i<=end ;i++){
            textattr(7);//  White = 15 or 7
            gotoxy(cursorX,line);
            cursorX++;
            printf("%c",input[i]);
            }
            input[cursorX+1]='\0';
   }
   else if (ch==22){//ctrl+v
        for (i=left_trim+1 ; i<=end ;i++){
            textattr(7);//  White = 15 or 7
            gotoxy(cursorX,line);
            cursorX++;
            printf("%c",input[i]);
            input[cursorX]=input[i];
            }
            cursorX--;
            end=cursorX;
            input[cursorX+1]='\0';

   }
   else if (ch==27){//Esc


	   printf("\nByeBye\n");
	   esc = 1;
   }


   }
   return(0);
}
