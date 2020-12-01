#ifndef M_PLAYER_H
#define M_PLAYER_H
#include "Stack.h"
#include "List.h"
#define PLAY    0
#define STOP    1
#define PAUSE   2

typedef struct Music{
    char *author;
    char *name;
}Music;

typedef struct{
    Music *musics;
    int numeberOfMusics;
    LinkedList *reproduction;
    Node *currentMusic;
    int state;
}MPlayer;

MPlayer *CreatePlayer(char *configure_file);
void DestroyPlayer(MPlayer *player);
void ListMusics(MPlayer *player);
void ListCurrentMusic(MPlayer *player);
void PlayMusic(MPlayer *player);
int NextMusic(MPlayer *player);
int PreviousMusic(MPlayer *player);
int PauseMusic(MPlayer *player);
int ResumeMusic(MPlayer *player);
void LoopPlayList(MPlayer *player);
void RandomizeMusic(MPlayer *player);
void AddMusic(MPlayer *player, char *music_name);
int EstateMusic(MPlayer *player);

#endif /* M_PLAYER_H */
