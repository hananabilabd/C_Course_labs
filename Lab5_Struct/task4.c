#include <stdio.h>
#include<windows.h>
#define null -32
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
 struct employee {
    int id ;
    char name[20];
    int salary ;
};
typedef struct employee employee ;

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
 employee add_Employee(employee emp ,int count){
     printf("Enter Employee.ID[%d]= ",count);
	scanf("%d",&emp.id);
	printf("Enter Employee.Salary[%d]= ",count);
	scanf("%d",&emp.salary);
	printf("Enter Employee.Name[%d]= ",count);
	scanf("%s",&emp.name);
	return emp ;
 }
void display_Employee(employee emp[],int id ){
    int found_ID=0 ,found_flag=0;
     for (int i =0 ; i<5 ;i++){
            if (emp[i].id == id){
                found_ID=i;
                found_flag = 1;
            }
        }
        if (found_flag =1){
        printf("\nEmployee.ID[%d] =%d\n",found_ID,emp[found_ID].id);
        printf("Employee.Salary[%d]=%d\n",found_ID,emp[found_ID].salary);
        printf("Employee.Name[%d] =%s\n",found_ID,emp[found_ID].name);}
        else {
        printf("No Employee Found\n");
        }
 }
 int count =0 ;
int main () {

    employee emp[5] ;
	int mainMenu=1,display=0 , create=0,exit =0 ,x=0 ,flag =1,flag2=1,i,state = 0;
	char c ;
	char  input_string[100];
while (exit !=1){
    if (mainMenu == 1 && display == 0 && create ==0 && exit ==0 ){

         if (flag ==1){
        system("cls");
        state =0;
		display_Items(state);
		}

        c=getch();
        if (c == -32){

        c = getch();
          if (c == 72 ){ //up
             system("cls");
             state--;
             if (state <0){state =2;}

		display_Items(state);

        }
        else if (c ==80  ){//down

           system("cls");
           state++;
             if (state >2){state =0;}
          display_Items(state);
        }
        else if (c == 71 ){//home

            system("cls");
            state =0;
      display_Items(state);
        }
        else if (c == 79 ){//end

           system("cls");
           state =2;
        display_Items(state);

        }
        // up = 72  down = 80  home = 71  end = 79
            mainMenu =1 ;

        }
        else if (c== 13){
            if (state == 0){
            create =1 ;
            c = 0;
            }
            else if (state ==1){

            display =1 ;
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
else if  (display == 1 && create ==0 && mainMenu ==0){

        int id ;
        system("cls");
        printf("Enter Employee ID=");
        scanf("%d",&id);
        display_Employee(emp ,id);//Function to Search Employee Structure
        printf("Press any Keys to return to the main menu\n ");
        x=getch();
        mainMenu =1 ;
        flag =1;
        display =0 ;
        state=0;



}
else if (mainMenu ==0 && create ==1 && display ==0){
   if (flag2 ==1){system("cls");}
    flag2 =0;
    system("cls");
    emp[count]=add_Employee(emp[count],count );

    count++;
    printf("Please Enter Anything \n");
    scanf("%[^\n]s",&input_string);
    mainMenu =1  ;
    flag =1;
    create =0 ;
    state=0;


}
else if  (exit ==1){
    mainMenu =0;
    system("cls");

}
	}

   return(0);
}
