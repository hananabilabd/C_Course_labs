#include <stdio.h>
#include<windows.h>
#define null -32
#define line 0

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
    int  cursorX=0,cursorY =0 ,i,left_trim,esc =0,row ,col,insert_flag=0;
	char ch,temp1,temp2 ;
	//char  input[200];
	int *end;
	printf("Enter Number of Lines You want= ");
	scanf("%d",&row);
    printf("Enter Number of characters in each line You want= ");
	scanf("%d",&col);
	char  ** input = (char**) malloc(row *sizeof(char*));
	end = (int*)malloc(row *sizeof(int));
	for (i =0 ; i< row ;i++){
        input[i] = (char*) malloc(col * sizeof(char));
        end[i]=0;
	}
	for (i =0 ; i< row ;i++){
        for (int j =0 ; j <col ;j++){
        input[i][j] = '\0';
	}}
    system("cls");
    while ( esc !=1){


   ch = getch();
   if (ch == -32){

	   ch = getch();
	   if (ch==75){//left arrow
	       cursorX--;
	       if (cursorX <0){cursorX =0;}
           gotoxy(cursorX ,cursorY);


	   }
	   else if(ch ==77){//right arrow
	       cursorX++;
	       if (cursorX <=end[cursorY]){
            gotoxy(cursorX,cursorY);
            //end =cursorX+1;
	       }
	       else{
            cursorX =end[cursorY];
	       }
	   }
	    else if(ch ==72){//up arrow
	       cursorY--;
	       if (cursorY <0){
            cursorY =0 ;
	       }
	       if (cursorX >end[cursorY]){
            cursorX=end[cursorY];
	       }
	     gotoxy(cursorX,cursorY);
	   }
	    else if(ch ==80){//down arrow
	       cursorY++;
	       if (cursorY >row-1){
            cursorY =row -1;
	       }
	       if (cursorX >end[cursorY]){
            cursorX=end[cursorY];
	       }
	       gotoxy(cursorX,cursorY);

	   }
	   else if(ch ==71){//home
	        cursorX=0;
            gotoxy(cursorX,cursorY);
	   }
	   else if(ch ==79){//end
	       cursorX=end[cursorY];
            gotoxy(cursorX,cursorY);

	   }
	    else if (ch==115){//ctrl+left arrow

	       if (cursorX <0){cursorX =0;}
           gotoxy(cursorX ,cursorY);

	   textattr(20);
	   printf("%c",input[cursorY][cursorY]);
	   textattr(7);//  White = 15
	   cursorX--;
	   left_trim = cursorX;
   }
        else if (ch==116){//ctrl+right arrow

         if (cursorX <0){cursorX =0;}
           gotoxy(cursorX ,cursorY);
	   textattr(20);
	   printf("%c",input[cursorY][cursorX]);
	   textattr(7);//  White = 15 or 7
	   cursorX++;

   }
      else if (ch==82){//insert

        if (insert_flag ==1){insert_flag=0;}
        else {insert_flag=1;}




   }
      else if (ch==83){//delete
        //cursorX++;
          for(i=cursorX ; i<end[cursorY];i++){
            input[cursorY][i]=input[cursorY][i+1];
            }
            end[cursorY]--;
            input[cursorY][end[cursorY]+1]='\0';
            gotoxy(cursorX,cursorY);
            for(i=cursorX;i<=end[cursorY];i++){
            printf("%c",input[cursorY][i]);
            }
            //cursorX--;
            gotoxy(cursorX,cursorY);

   }


   }
   ////////////////////////////////////////////Normal Characters handling/////////////////////////////////
   else if (ch==13){//Enter

       gotoxy(0,8);
	   printf("You've Entered =\n");
	   for (i=0;i<row ;i++){
	   printf("%s\n",input[i]);
	   }
	   gotoxy(cursorX,cursorY);
   }
   else if ( (ch >= 65 && ch <=122) || (ch >=48 && ch<=57)|| (ch ==32)){ //handling from A =65 to Z=90 and from a=97 to z=122

        if (insert_flag ==0){
        if (cursorX == end[cursorY]){
            gotoxy(cursorX ,cursorY);
            printf("%c",ch);
            input[cursorY][cursorX]=ch;
            input[cursorY][cursorX+1]='\0';
            end[cursorY]++;
        }
        else if (cursorX< end[cursorY]){
            gotoxy(cursorX ,cursorY);
            printf("%c",ch);
            input[cursorY][cursorX]=ch;
        }
        cursorX++;
        }
        else if (insert_flag ==1){

         if (cursorX <= end[cursorY]){

            gotoxy(cursorX ,cursorY);
            printf("%c",ch);
            for(i=end[cursorY] ; i>=cursorX;i--){
            input[cursorY][i+1]=input[cursorY][i];
            }
            input[cursorY][cursorX]=ch;
            end[cursorY]++;
            input[cursorY][end[cursorY]+1]='\0';

            gotoxy(cursorX ,cursorY);
            for(i=cursorX; i<=end[cursorY];i++){
                 printf("%c",input[cursorY][i]);
            }
            cursorX++;
            gotoxy(cursorX ,cursorY);
            //printf("%s",input[cursorY]);
            //gotoxy(cursorX ,cursorY);


        }


        }


   }/*
   else if(ch ==32){ //space
       cursorX++;
       gotoxy(cursorX ,cursorY);
        printf("%c",' ');
        input[cursorY][cursorX]=ch;
        end[cursorY] =cursorX;
        input[cursorY][cursorX+1]='\0';

   }*/
   else if (ch ==3){//ctrl +c
        for (i=cursorX ; i<=end ;i++){
            textattr(7);//  White = 15 or 7
            gotoxy(cursorX,cursorY);
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
    else if (ch==8){//backspace
            cursorX--;
        for(i=cursorX ; i<end[cursorY];i++){
            input[cursorY][i]=input[cursorY][i+1];
            }
            end[cursorY]--;
            input[cursorY][end[cursorY]+1]='\0';
            gotoxy(cursorX,cursorY);
            for(i=cursorX;i<=end[cursorY];i++){
            printf("%c",input[cursorY][i]);
            }
            gotoxy(cursorX,cursorY);




	   //cursorX;

   }
   else if (ch==27){//Esc


	   printf("\nByeBye\n");
	   esc = 1;
   }


   }
   return(0);
}
