#include <stdio.h>

int main () {
	int mainMenu=1,display=0 , create=0,exit =0 ,x=0 ,flag =1,flag2=1;
	char c ;
	char  input_string[100];
	while (exit !=1){
if (mainMenu == 1 && display == 0 && create ==0 && exit ==0 && flag ==1){
        mainMenu =0;
         flag =0;
        system("cls");

        printf("a) Display\n ");
        printf("b) Create\n ");
        printf("c) Exit\n ");
        c=getch();

        if (c == 'a' ){

            display =1 ;
            c = 0;

        }
        else if (c == 'b' ){

            create =1 ;
            c = 0;

        }
        else if (c == 'c' ){

            exit =1 ;
            c = 0;

        }


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
