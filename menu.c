#include "header.h"

void menu()//menu utama
{
    system("cls");
    int pilihan;
    printf("\n\t___  ___ _____ _   _ _   _ ");
    printf("\n\t|  \\/  ||  ___| \\ | | | | |");
    printf("\n\t| .  . || |__ |  \\| | | | |");
    printf("\n\t| |\\/| ||  __|| . ` | | | |");
    printf("\n\t| |  | || |___| |\\  | |_| |");
    printf("\n\t\\_|  |_/\\____/\\_| \\_/\\___/ ");
	
	printf ("\n  ______________________________________");
	printf ("\n |______________________________________|");
	printf ("\n |                                      |");
	printf ("\n |           1. Multi Player            |");
	printf ("\n |                                      |");
	printf ("\n |           2. Single Player           |");
	printf ("\n |                                      |");
	printf ("\n |           3. How to Play             |");
	printf ("\n |                                      |");
	printf ("\n |              4. Exit                 |");
 	printf ("\n |______________________________________|");
	printf ("\n |______________________________________|");
	printf ("\n            Select menu :\t");
	scanf ("%d", &pilihan);
	switch (pilihan)
    {
		case 1:
			singleplayer(pilihan);//fungsi program
			break;
		case 2 :
            singleplayer(pilihan);//fungsi program
            break;
        case 3:
            HowToPlay();//void petunjuk
            menu();
			break;
		case 4:
			quit();  // void untuk quit
			break;
		default ://default untuk input yang tidak ditentukan
            printf("Wrong Input, Please Try Again...\n");
            getch();
            menu();  // meminta input ulang sampai inputnya valid
            break;
    }
}
