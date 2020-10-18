#include "header.h"

void singleplayer(int mode) //fungsi game
{
    system("cls");
    char tictactoe[3][3] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    int indexttt[3][3] = {10,11,12,13,14,15,16,17,18}, opsi[2], win, n = 0,j,k,l,x,y,m = 0;
    int z[10]; //varibel untuk enable fungsi algoritma
    printboard(tictactoe);//fungsi print board game
    srand(time(0)); // inisialisasi random dengan seed waktu
    while(win != 1 && m < 9)//loop akan berjalan selama belum ada yang menang atau seri
    { 
        m = 0; //variable untuk menghitung jumlah langkah kita
        for(j=0; j<3; j++)
        {
            l=0;
            y=0;
            for(k=0; k<3; k++)
            {
                if (indexttt[j][k] == 2 || indexttt[j][k] == 3)
                {
                    l++;
                    m++;
                }
                if (indexttt[k][j] == 2 || indexttt[k][j] == 3 )
                {
                    y++;
                }
            }
            if (l == 3)
            {
                if (j == 0){
                    z[0] = 1;
                }
                else if (j == 1){
                    z[1] = 1;
                }
                else if (j == 2){
                    z[2] = 1;
                }
            }
            if (y == 3)
            {
                if (j == 0){
                    z[3] = 1;
                }
                else if (j == 1){
                    z[4] = 1;
                    
                }
                else if (j == 2){
                    z[5] = 1;
                }
            }
        }
        if (n%2 == 0)//player 1 turn
        {
            printf("\n\nPlayer 1 turn\n",(n%2)+1);
            takeinput(opsi);//fungsi untuk meminta input row dan kolom
            while (opsi[0]>3 || opsi[0]<1 || opsi[1]>3 || opsi[1]<1)//error handling jika input lebih dari kotak boardgame
            {
                printf("\nInvalid input, please enter option again\n");
                takeinput(opsi);//meminta input ulang
            }
            while (indexttt[opsi[0]-1][opsi[1]-1] == 2 || indexttt[opsi[0]-1][opsi[1]-1] == 3)//error handling jika input sudah pernah dimasukan
            {
                printf("\nSlot taken, please enter option again\n");
                takeinput(opsi);//meminta input ulang
            }
        }
        else if (n % 2 == 1)//player 2 turn
        {
            if (mode == 1)//jika saat input di menu multiplayer
            {
                printf("Player 2 turn\n",(n%2)+1);
                takeinput(opsi);//fungsi untuk meminta input row dan kolom
                while (opsi[0]>3 || opsi[0]<1 || opsi[1]>3 || opsi[1]<1)
                {
                    printf("\nInvalid input, please enter option again\n");//error handling jika input lebih dari kotak boardgame
                    takeinput(opsi);//meminta input ulang
                }
                while (indexttt[opsi[0]-1][opsi[1]-1] == 2 || indexttt[opsi[0]-1][opsi[1]-1] == 3)//error handling jika input sudah pernah dimasukan
                {
                    printf("\nSlot taken, please enter option again\n");
                    takeinput(opsi);//meminta input ulang
                }
            }
            else if (mode == 2)//jika saat input di menu single player
            {
                printf("\n\n\n");
                x = botmove(indexttt, opsi,z,n); //fungsi untuk turn bot
                while (indexttt[opsi[0]-1][opsi[1]-1] == 2 || indexttt[opsi[0]-1][opsi[1]-1] == 3)// looping untuk error handling bot
                {
                    x = botmove(indexttt, opsi,z,n);//fungsi untuk turn bot
                }
                z[x] = 1; //variabel enable algoritma bot
            }
        }
        if (n%2 == 0)// untuk turn player pertama
        {
            indexttt[opsi[0]-1][opsi[1]-1] = 2;
            tictactoe[opsi[0]-1][opsi[1]-1] = 'X'; //player pertama adalah X
        }
        if (n%2 == 1)//untuk turn player 2
        {
            indexttt[opsi[0]-1][opsi[1]-1] = 3;
            tictactoe[opsi[0]-1][opsi[1]-1] = 'O'; //player 2 adalah O
        }
        printboard(tictactoe);//fungsi untuk print board game
        win = cekwin(indexttt);//fungsi untuk cek apakah sudah menang atau belum
        if (win == 1)//jika sudah menang
        {
            if (n%2+1==1){ //jika player 1 menang
            printf ("              _                         __  \n");
            printf ("             | |                       /  | \n");
            printf ("        _ __ | | __ _ _   _  ___ _ __  `| | \n");
            printf ("       | '_ \\| |/ _` | | | |/ _ \\ '__|  | | \n");
            printf ("       | |_) | | (_| | |_| |  __/ |    _| |_\n");
            printf ("       | .__/|_|\\__,_|\\__, |\\___|_|    \\___/\n");
            printf ("       | |             __/ |                \n");
            printf ("       |_|            |___/                 \n");
            printf ("            _    _ _____ _   _  _____ \n");
            printf ("           | |  | |_   _| \\ | |/  ___|\n");
            printf ("           | |  | | | | |  \\| |\\ `--. \n");
            printf ("           | |/\\| | | | | . ` | `--. \\ n");
            printf ("           \\  /\\  /_| |_| |\\  |/\\__/ / \n");
            printf ("            \\/  \\/ \\___/\\_| \\_/\\____/ \n");
            break;
            }
            else if (n%2+1==2){ // jika player 2 menang
            if (mode == 1)
			{
				printf ("              _                         _____ \n");
	            printf ("             | |                       / __  \\ \n");
	            printf ("        _ __ | | __ _ _   _  ___ _ __  `' / /' \n");
	            printf ("       | '_ \\| |/ _` | | | |/ _ \\ '__|   / /   \n");
	            printf ("       | |_) | | (_| | |_| |  __/ |    ./ /___ \n");
	            printf ("       | .__/|_|\\__,_|\\__, |\\___|_|    \\_____/ \n");
	            printf ("       | |             __/ |                  \n");
	            printf ("       |_|            |___/                   \n");
	 			printf ("            _    _ _____ _   _  _____ \n");
	            printf ("           | |  | |_   _| \\ | |/  ___|\n");
	            printf ("           | |  | | | | |  \\| |\\ `--. \n");
	            printf ("           | |/\\| | | | | . ` | `--. \\ n");
	            printf ("           \\  /\\  /_| |_| |\\  |/\\__/ / \n");
	            printf ("            \\/  \\/ \\___/\\_| \\_/\\____/ \n");
			}	
			else if (mode==2)// jika computer menang
			{
				printf("\n _____                             _            ");
			    printf("\n/  __ \\                           | |           ");
			    printf("\n| /  \\/ ___  _ __ ___  _ __  _   _| |_ ___ _ __ ");
			    printf("\n| |    / _ \\| '_ ` _ \\| '_ \\| | | | __/ _ \\ '__|");
			    printf("\n| \\__/\\ (_) | | | | | | |_) | |_| | ||  __/ |   ");
			    printf("\n \\____/\\___/|_| |_| |_| .__/ \\__,_|\\__\\___|_|   ");
			    printf("\n                      | |                       ");
			    printf("\n                      |_|                       ");
			    printf("\n  _    _ _____ _   _  _____                     ");
			    printf("\n | |  | |_   _| \\ | |/  ___|                    ");
			    printf("\n | |  | | | | |  \\| |\\ `--.                     ");
			    printf("\n | |/\\| | | | | . ` | `--. \\                    ");
			    printf("\n \\  /\\  /_| |_| |\\  |/\\__/ /                    ");
			    printf("\n  \\/  \\/ \\___/\\_| \\_/\\____/ ");
			}
            }
            
   		 }
            else if (m == 8) //jika permainan seri
            {
            printf ("############################################################\n");
            printf ("###########           #####   #####        #################\n");
            printf ("###############   #########   #####  #######################\n");
            printf ("###############   #########   #####        #################\n");
            printf ("###############   #########   #####  #######################\n");
            printf ("###############   #########   #####        #################\n");
            printf ("############################################################\n");
            }
        
        n++;
    
    }
    printf ("\n\tPress anything to go back to the menu");
    getch();
    menu(); //kembali ke menu
}
void takeinput(int opsi[2]) //fungsi meminta input row dan kolom
{
    printf("Select row :\t");  //input baris
    scanf("%d", &opsi[0]);
    printf("Select column :\t"); //input kolom
    scanf("%d", &opsi[1]);
}
void printboard(char tictactoe[3][3]) //fungsi untuk print boardgame
{
    printf ("\t\t       |       |      \n");
    printf ("\t\t   %c   |   %c   |   %c   \n", tictactoe[0][0], tictactoe[0][1], tictactoe[0][2]);
    printf ("\t\t_______|_______|_______\n");
    printf ("\t\t       |       |      \n");
    printf ("\t\t   %c   |   %c   |   %c   \n",tictactoe[1][0], tictactoe[1][1], tictactoe[1][2]);
    printf ("\t\t_______|_______|_______\n");
    printf ("\t\t       |       |      \n");
    printf ("\t\t   %c   |   %c   |   %c   \n",tictactoe[2][0], tictactoe[2][1], tictactoe[2][2]);
    printf ("\t\t       |       |      \n");
}
int cekwin(int indexttt[3][3]) //fungsi untuk cek kemenangan
{
    if (indexttt[0][0]==indexttt[0][1] && indexttt[0][1]==indexttt[0][2]) //akan menang jika isi baris 1
    {
        return 1;
    }
    else if (indexttt[1][0]==indexttt[1][1] && indexttt[1][1]==indexttt[1][2])//akan menang jika isi baris 2
    {
        return 1;
    }
    else if (indexttt[2][0]==indexttt[2][1] && indexttt[2][1]==indexttt[2][2])//akan menang jika isi baris 3
    {
        return 1;
    }
    else if (indexttt[0][0]==indexttt[1][0] && indexttt[1][0]==indexttt[2][0]) //akan menang jika isi kolom 1
    {
        return 1;
    }
    else if (indexttt[0][1]==indexttt[1][1] && indexttt[1][1]==indexttt[2][1]) //akan menang jika isi kolom 2
    {
        return 1;
    }
    else if (indexttt[0][2]==indexttt[1][2] && indexttt[1][2]==indexttt[2][2])//akan menang jika isi kolom 3
    {
        return 1;
    }
    else if (indexttt[0][0]==indexttt[1][1] && indexttt[1][1]==indexttt[2][2]) //akan menang jika horizontal
    {
        return 1;
    }
    else if (indexttt[0][2]==indexttt[1][1] && indexttt[1][1]==indexttt[2][0]) //akan menang jika horizontal
    {
        return 1;
    }
    else //belum ada yang menang
    {
        return 0;
    }
}
int botmove(int indexttt[3][3], int opsi[2], int z[9], int n)
{
    int i;
    opsi[0] = 0;
    opsi[1] = 0;
    if (n == 1)
    {//bot akan mengambil kotak tengah terlebih dahulu
        if (indexttt[1][1] != 2) //jika terisi maka diisi oleh bot
        {
            opsi[0]= 2;
            opsi[1]= 2;
            return 7;
        }
        else if (indexttt[1][1] == 2) //jika sudah terisi oleh player 1
        {
            opsi[0]= 1; //bot mengambil kotak baris 1 kolom 1
            opsi[1]= 1;
            return 7;
        } 
    }
    for(i=0;i<3;i++) //untuk bot serang dalam baris
    {//jika dalam suatu baris 2 kotak sudah diisi bot dan tinggal tersisa 1 kotak maka bot akan mengisi kotak itu
		if(indexttt[i][0]==3 && indexttt[i][1]==3 && indexttt[i][2] !=2)
		{
			opsi[0]= i+1;
            opsi[1]= 3;
            return 8;
		}
		else if(indexttt[i][2]==3 && indexttt[i][1]==3 && indexttt[i][0]!=2)
		{
			opsi[0]= i+1;
            opsi[1]= 1;
            return 8;
		}
		else if(indexttt[i][0]==3 && indexttt[i][2]==3 && indexttt[i][1]!=2)
		{
			opsi[0]= i+1;
            opsi[1]= 2;
            return 8;
		}
    }
    for(i=0;i<3;i++)//untuk bot serang dalam kolom
    {//jika dalam suatu kolom 2 kotak sudah diisi bot dan tinggal tersisa 1 kotak maka bot akan mengisi kotak itu
		if(indexttt[0][i]==3 && indexttt[1][i]==3 && indexttt[2][i]!=2)
		{
			opsi[0]= 3;
            opsi[1]= i+1;
            return 8;
		}
		else if(indexttt[2][i]==3 && indexttt[1][i]==3 && indexttt[0][i]!=2)
		{
			opsi[0]= 1;
            opsi[1]= i+1;
            return 8;
		}
		else if(indexttt[0][i]==3 && indexttt[2][i]==3 && indexttt[1][i]!=2)
		{
			opsi[0]= 2;
            opsi[1]= i+1;
            return 8;
		}
    }
    
    
	if(indexttt[1][1]==3) //jika dalam diagonal 2 kotak sudah diisi bot dan tinggal tersisa 1 kotak maka bot akan mengisi kotak itu
		if(indexttt[2][2]==3 && indexttt[0][0]!= 2)
		{
			opsi[0]= 1;
            opsi[1]= 1;
            return 8;
		}
		else if(indexttt[2][0]==3 && indexttt[0][2]!= 2)
		{
			opsi[0]= 1;
            opsi[1]= 3;
            return 8;
		}
		else if(indexttt[0][2]==3 && indexttt[2][0]!=2)
		{
			opsi[0]= 3;
            opsi[1]= 1;
            return 8;
		}
		else if(indexttt[0][0]==3 && indexttt[2][2]!=2)
		{
			opsi[0]= 3;
            opsi[1]= 3;
            return 8;
		}

    //fungsi defending melawan user jika user tinggal input 1 move lagi di baris, kolom atau diagonal
    if (z[0] != 1 && (indexttt[0][0]==indexttt[0][1] || indexttt[0][1]==indexttt[0][2] || indexttt [0][0]==indexttt[0][2]))
    {
		opsi[0] = 1;
        opsi[1] = (rand()%3) + 1;
        return 0;
    }
    else if (z[2] != 1 && (indexttt[2][0]==indexttt[2][1] || indexttt[2][1]==indexttt[2][2] || indexttt[2][0]==indexttt[2][2]))
    {
        opsi[0] = 3;
        opsi[1] = (rand()%3) + 1;
        return 2;
    }
    else if (z[1] != 1 && (indexttt[1][0]==indexttt[1][1] || indexttt[1][1]==indexttt[1][2] || indexttt[1][0]==indexttt[1][2]))
    {
        opsi[0] = 2;
        opsi[1] = (rand()%3) + 1;
        return 1;
    }
    else if (z[3] != 1 && (indexttt[0][0]==indexttt[1][0] || indexttt[1][0]==indexttt[2][0] || indexttt[0][0]==indexttt[2][0]))
    {
        opsi[0] = (rand()%3) + 1;
        opsi[1] = 1;
        return 3;
    }
    else if (z[4] != 1 && (indexttt[0][1]==indexttt[1][1] || indexttt[1][1]==indexttt[2][1] || indexttt[0][1]==indexttt[2][1]))
    {
        opsi[0] = (rand()%3) + 1;
        opsi[1] = 2;
        return 4;
    }
    else if (z[5] != 1 && (indexttt[0][2]==indexttt[1][2] || indexttt[1][2]==indexttt[2][2] || indexttt[0][2]==indexttt[2][2]))
    {
        opsi[0] = (rand()%3) + 1;
        opsi[1] = 3;
        return 5;
    }
    else if (indexttt[1][1]==2)
    {//fungsi defending diagonal
        if(indexttt[0][0] == 2 && indexttt[2][2] > 3 ) //contoh jika ditengah sudah diisi oleh player 1 
        {                                              //dibaris 1 kolom 1 player 2 juga sudah diisi 
            opsi[0] = 3;                               //maka bot mengisi baris 3 kolom 3
            opsi[1] = 3;
        }
        else if(indexttt[2][2] == 2 && indexttt[0][0] > 3 )
        {
            opsi[0] = 1;
            opsi[1] = 1;
        }
        else if(indexttt[0][2] == 2 && indexttt[2][0] > 3 )
        {
            opsi[0] = 3;
            opsi[1] = 1;
            
        }
        else if(indexttt[2][0] == 2 && indexttt[0][2] > 3 )
        {
            opsi[0] = 1;
            opsi[1] = 3;
        }
        return 6;
    }
    else// selain yang diatas bot akan merandom untuk mengisi kotaknya
    {
        opsi[0] = (rand() % 3) + 1;
        opsi[1] = (rand() % 3) + 1;
        printf(".\n");
    }
}
