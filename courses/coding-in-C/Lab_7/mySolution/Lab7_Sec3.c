/*
 *  File: Lab7_Sec3.c
 *  Description:  Implement a simple music playlist manager
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * @brief  element of the single linked list thats representing a playlist
 */
typedef struct Song {

  char *song_title;   //dynamically allocated string
  char *artist_name;  //dynamically allocated string
  Song *ptr_next_song;

} Song;

/*
 * @brief  header of the linked list representing a playlist
 */
typedef struct Playlist {

  Song *head;
  char *playlist_name;  //dynamically allocated string

} Playlist;

/*
 * @brief  initialize an empty playlist / set pointer to head to NULL
 *
 * @param[in] ptr_playlist    pointer to playlist
 */
void init_playlist(Playlist *ptr_playlist);

/*
 * @brief  add a new song to the end of the given playlist
 *
 * @param[in]  playlist   playlist to which end the new song should be appended
 * @param[out]            integer for error-detection
 */
int add_song(Playlist *playlist, char *song_title, char *artist_name);

/*
 * @brief  print all songs contained in the playlist
 *
 * @param[in]  playlist   playlist containing the songs
 * @param[out]            integer for error-detection
 */
int print_playlist(Playlist *playlist);

/*
 * @brief  removes the first song from the playlist and frees all allocated memory
 *
 * @param[in]  playlist   playlist containing the songs
 * @param[out]            integer for error-detection
 */
int delete_firstSong(Playlist *playlist);

/*
 * @brief  removes all songs from the playlist and frees all allocated memory
 *
 * @param[in]  playlist   playlist thats supposed to be deleted
 * @param[out]            integer for error-detection
 */
int delete_playlist(Playlist *playlist);

//-------------------------------------------------------------------------------------------------------

int main(){

  //creating and initializing playlist
  Playlist playlist_1;
  init_playlist(&playlist_1);

  //adding multiple songs to the playlist
  add_song(&playlist_1, "Crawling", "Linkin Park");
  add_song(&playlist_1, "Layle", "Eric Clapton");
  add_song(&playlist_1, "Esperanto", "Max Herre");

  //printing the playlist
  //deleting the first song
  //printing the playlist again
  //deleting the complete playlist

  return 0;
}

//-------------------------------------------------------------------------------------------------------

void init_playlist(Playlist *ptr_playlist){
  ptr_playlist->head = NULL;
}

int add_song(Playlist *playlist, char *song_title, char *artist_name){

  //dynamically allocate memory for song
  Song *new_Song = malloc(sizeof(*new_Song));

  if(new_Song == NULL){
    printf("Error in add_song(): Memory could not be allocated\n");
    return 1;
  }

  //dynamically allocate memory for strings
  new_Song->song_title = malloc(strlen(song_title)+1);
  new_Song->artist_name = malloc(strlen(artist_name)+1);

  if(song_title == NULL || artist_name == NULL){
    printf("Error in add_song(): Memory could not be allocated\n");
    free(new_Song->song_title);
    free(new_Song->artist_name);
    free(new_Song);
    return 1;
  }

  //copy titles and names to the song struct
  strcpy(new_Song->song_title, song_title);
  strcpy(new_Song->artist_name, artist_name);
  

  //set pointer to next song to NULL
  new_Song->ptr_next_song = NULL;

  //if playlist is empty, set head of playlist to this newly created song
  if(playlist->head == NULL){
    playlist->head = new_Song;
    return 0;
  }

  //

  return 0;
}

int print_playlist(Playlist *playlist){

}

int delete_firstSong(Playlist *playlist){

}

int delete_playlist(Playlist *playlist){

}