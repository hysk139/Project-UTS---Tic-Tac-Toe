#include "header.h"

void quit()
{
    system("cls");
    int opsi;
    printf("Are you sure you wanna quit??\n");
    printf("Enter 1 to quit or 2 to go back :");
    scanf("%d", &opsi);//meminta input 
    switch(opsi)
    {
        case 1 :
            END();//void untuk keluar program
            break;
        case 2 :
            menu();//kembali ke menu lagi
            break;
        default : //default untuk input yang tidak ditentukan
            printf("\nWrong input, please try again. Press anything to continue");
            getch();
            quit();
    }
}
void END()//penutup program
{
    system("cls");
	printf ("\n ______________________________________");
	printf ("\n|______________________________________|");
	printf ("\n|                                      |");
	printf ("\n|         Thank You For Using          |");
	printf ("\n|            This Program              |");
 	printf ("\n|______________________________________|");
	printf ("\n|______________________________________|\n");
    sleep(3);
    printf ("#################################################\n");
    printf ("##      ##       ##       #######  ###  ###  ####\n");
    printf ("##  ######  #######  ############  ###  ###  ####\n");
    printf ("##      ##       ##       #######  ###  ###  ####\n");
    printf ("######  ##  #######  ############  ###  #########\n");
    printf ("##      ##       ##       #######       ###  ####\n");
    printf ("#################################################\n");
}
