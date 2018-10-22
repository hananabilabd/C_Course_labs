#include <stdio.h>
#include<windows.h>
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
	char menu[3][10]={"New" ,"Display","Exit"};

	int mainMenu=1,display=0 , create=0,exit =0 ,x=0 ,flag =1,flag2=1,i,state = 0;
	char c ;
	char  input_string[100];
while (exit !=1){
    if (mainMenu == 1 && display == 0 && create ==0 && exit ==0 ){

         if (flag ==1){
        system("cls");
		for (i =0 ; i< 3 ; i++){
                if (i ==0){
                    textattr(20);// Red = 4 and White = 7
                    printf("%s\n",menu[i]);
                }
                else {
                    textattr(7);// Red = 4 and White = 7
                    printf("%s\n",menu[i]);
                }
		}}

        c=getch();
        if (c == -32){

        c = getch();
          if (c == 72 ){ //up
             system("cls");
             state--;
             if (state <0){state =2;}
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

		}


        }
        else if (c ==80  ){//down

           system("cls");
           state++;
             if (state >2){state =0;}
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

		}





        }
        else if (c == 71 ){//home

            system("cls");
            for (i =0 ; i< 3 ; i++){
                if (i==0){
                    textattr(20);// Red = 4 and White = 7
                    printf("%s\n",menu[i]);
                    textattr(15);
                }
                else {
                    textattr(15);// Red = 4 and White = 7
                    printf("%s\n",menu[i]);
                }

		}




        }
        else if (c == 79 ){//end

           system("cls");
            for (i =0 ; i< 3 ; i++){
                if (i==2){
                    textattr(20);// Red = 4 and White = 7
                    printf("%s\n",menu[i]);
                    textattr(15);
                }
                else {
                    textattr(15);// Red = 4 and White = 7
                    printf("%s\n",menu[i]);
                }

		}

        }
            //printf("%d\n",ch); // up = 72  down = 80  home = 71  end = 79
            mainMenu =1 ;

        }
        else if (c== 13){
            if (state == 0){
            display =1 ;
            c = 0;
            }
            else if (state ==1){

            create =1 ;
            c = 0;

        }
        else if (state ==2 ){

            exit =1 ;
            c = 0;

        }
        mainMenu = 0;

        }


flag =0;
}
else if  (display == 1 && mainMenu ==0){

        system("cls");
        printf("Hello People\n ");
        printf("Hello From the Other Side\n ");
        printf("Press any Keys to return to the main menu\n ");

        x=getch();
            mainMenu =1 ;
            flag =1;
            display =0 ;



}
else if (mainMenu ==0 && create ==1){

    if (flag2 ==1){system("cls");}
    flag2 =0;

    printf("Please Enter Anything \n");
    scanf("%[^\n]s",&input_string);

    printf("%s",input_string);
    mainMenu =1  ;
    flag =1;
    create =0 ;


}
else if  (exit ==1){
    mainMenu =0;
    system("cls");

}
	}

   return(0);
}
