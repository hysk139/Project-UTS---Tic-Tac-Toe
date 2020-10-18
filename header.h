#ifndef HEADER_H
    #define HEADER_H
    #include <stdio.h>
    #include <windows.h>
    #include <time.h>
    
    //game.c
    
    void singleplayer(int mode);
    void takeinput(int opsi[2]);
    void printboard(char tictactoe[3][3]);
    int cekwin(int indexttt[3][3]);
    int botmove(int indexttt[3][3], int opsi[2], int z[9], int n);
    
    //howtoplay.c
    void HowToPlay();
    
    //END.c
    void quit();
    void END();
    
    //menu.c
    void menu();
    
#endif
