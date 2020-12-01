#include "MPlayer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

MPlayer *CreatePlayer(char *configure_file){
    MPlayer *player;
    FILE *fp;
    int buffer_size = 0;
    int n;
    int i;
    
    player = calloc(1, sizeof(MPlayer));
    player->state = -1;
    fp = fopen(configure_file, "ab+");
    
    while(!feof(fp)){
        Music music = {};

        n = getline(&music.author, &buffer_size, fp);
        if(music.author[n-1] == '\n'){
            music.author[n-1] = '\0';

            if(music.author[n-2] == '\r'){
                music.author[n-2] = '\0';
            }
        }

        n = getline(&music.name, &buffer_size, fp);
        if(music.name[n-1] == '\n'){
            music.name[n-1] = '\0';

            if(music.name[n-2] == '\r'){
                music.name[n-2] = '\0';
            }
        }

        player->numeberOfMusics ++;
        player->musics = (Music *) realloc(player->musics, player->numeberOfMusics * sizeof(Music));
        player->musics[player->numeberOfMusics - 1] = music;
    }

    player->reproduction = CreateList();

    for(i = 0; i < player->numeberOfMusics; i++){
        InsertList(player->reproduction, &player->musics[i]);
    }

    player->currentMusic = player->reproduction->begin;
    fclose(fp);
    return player;
}

void DestroyPlayer(MPlayer *player){
    int i;
    
    for(i = 0; i < player->numeberOfMusics; i++){
        free(player->musics[i].author);
        free(player->musics[i].name);
    }

    free(player->musics);
    free(player);
}


void ListMusics(MPlayer *player){
    int i;
    
    for(i = 0; i < player->numeberOfMusics; i++){
        printf("Musica: %s\n", player->musics[i].name);
        printf("Autor: %s\n\n", player->musics[i].author);
    }
}

void ListCurrentMusic(MPlayer *player){
    printf("Musica: %s\n", player->currentMusic->music->name);
    printf("Autor: %s\n\n", player->currentMusic->music->author);
}

void PlayMusic(MPlayer *player){
    char command[512];

    sprintf(command, "open \"musics/%s.mp3\" alias MUSIC", player->currentMusic->music->name);
    mciSendString(command, NULL, 0, 0);
    mciSendString("play MUSIC", NULL, 0, 0);

    player->state = PLAY;
}

int NextMusic(MPlayer *player){
    if(player->currentMusic->next == NULL){
        return 0;
    }

    mciSendString("close MUSIC", NULL, 0, 0);
    player->currentMusic = player->currentMusic->next;
    PlayMusic(player);
    return 1;
}


int PreviousMusic(MPlayer *player){
    if(player->currentMusic->prev == NULL){
        return 0;
    }

    mciSendString("close MUSIC", NULL, 0, 0);
    player->currentMusic = player->currentMusic->prev;
    PlayMusic(player);
    return 1;
}

int PauseMusic(MPlayer *player){
    mciSendString("pause MUSIC", NULL, 0, 0);
    player->state = PAUSE;
}

int ResumeMusic(MPlayer *player){
    mciSendString("resume MUSIC", NULL, 0, 0);
    player->state = PLAY;
}

void LoopPlayList(MPlayer *player){
    player->reproduction->begin->prev = player->reproduction->end;
    player->reproduction->end->next = player->reproduction->begin;
}

void RandomizeMusic(MPlayer *player){
    Stack *stack;
    LinkedList *list;
    int i, valor;
    stack = CreateStack(player->numeberOfMusics);

    for(i = 0; i < player->numeberOfMusics; i++){
        InsertStack(stack, i);
    }

    ShuffleStack(stack);
    list = CreateList();

    for(i = 0; i < player->numeberOfMusics; i++){
        RemoveStack(stack, &valor);
        InsertList(list, &player->musics[valor]);
    }

    DestroyList(player->reproduction);
    player->reproduction = list;
    player->currentMusic = player->reproduction->begin;

    DestroyStack(stack);

    mciSendString("close MUSIC", NULL, 0, 0);

    PlayMusic(player);
}

int EstateMusic(MPlayer *player){
    int status;
    char resp[512];

    status = mciSendString("status MUSIC mode", resp, 512, 0);

    if(!strcmp(resp, "stopped")){
        player->state = STOP;
    }

    return player->state;
}
