#include "MPlayer.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void PrintMenuA(){
    printf("P - Tocar musicas\n");
    printf("S - Sair\n");
}

void PrintMenuB(MPlayer *player){
    printf("P - Tocar musicas\n");
    printf("N - Proxima musica\n");
    printf("A - Musica anterior\n");
    printf("K - Randomizar Playlist\n");
    printf("L - Playlist em loop\n");
    printf("V - Pausar musica\n");
    printf("R - Continuar musica\n");
    printf("S - Sair\n");
}

int main(){
    MPlayer *player;
    int status = 0;
    
    player = CreatePlayer("config.dat");

    system("cls");
    PrintMenuA();

    while (1){
        if(kbhit()){
            char ch = getch();
            if(ch == 'p'){
                PlayMusic(player);
                system("cls");
                ListCurrentMusic(player);
                PrintMenuB(player);
            }

            if(ch == 'n'){
                NextMusic(player);
                system("cls");
                ListCurrentMusic(player);
                PrintMenuB(player);
            }

            if(ch == 'a'){
                PreviousMusic(player);
                system("cls");
                ListCurrentMusic(player);
                PrintMenuB(player);
            }

            if(ch == 'l'){
                LoopPlayList(player);
                system("cls");
                ListCurrentMusic(player);
                PrintMenuB(player);
            }

            if(ch == 'v'){
                PauseMusic(player);
                system("cls");
                ListCurrentMusic(player);
                PrintMenuB(player);
            }

            if(ch == 'r'){
                ResumeMusic(player);
                system("cls");
                ListCurrentMusic(player);
                PrintMenuB(player);
            }

            if(ch == 'k'){
                RandomizeMusic(player);
                system("cls");
                ListCurrentMusic(player);
                PrintMenuB(player);
            }

            if(ch == 's'){
                break;
            }
        }

        status = EstateMusic(player);

        if(status == STOP){
            NextMusic(player);
        }
    }

    DestroyPlayer(player);

    return 0;
}
