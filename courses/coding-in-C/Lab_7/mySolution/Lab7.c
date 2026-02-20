/*
 *  @title: Playlist Manager
 *  @description: 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
  char *title;
  char *artist;
  Song *ptr_next_Song;
} Song;

typedef struct Playlist {
  char *title;
  Song *ptr_head;
} Playlist;

//-------------------------------------------------

Playlist *init_playlist(char *title);

void add_song(Playlist *playlist, char *title, char *artist);

void print_playlist(Playlist *playlist);

void delete_firstSong(Playlist *playlist);

void delete_playlist(Playlist *playlist);

int main(){



  return 0;
}