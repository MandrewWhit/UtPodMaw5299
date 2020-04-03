//
// Created by Andrew on 3/24/2020.
//

#ifndef UNTITLED_UTPOD_H
#define UNTITLED_UTPOD_H
#include "Song.h"


//UtPod class declaration
class UtPod
{
private:
    static const int MAX_MEMORY = 512;
    static const int SUCCESS = 0;
    static const int NO_MEMORY = -1;
    static const int NOT_FOUND = -2;

    struct SongNode
    {
        Song s;
        SongNode *next;
    };

    SongNode *songs;  //the head pointer

    int memSize;


public:
    //Default constructor
    //set the memory size to MAX_MEMORY
    UtPod();

    //Constructor with size parameter
    //The user of the class will pass in a size.
    //If the size is greater than MAX_MEMORY or less than or equal to 0,
    //set the size to MAX_MEMORY.
    UtPod(int size);

    /* FUNCTION - int addSong
     * attempts to add a new song to the UtPod
         o returns a 0 if successful
         o returns -1 if not enough memory to add the song

     precondition: s is a valid Song

     input parms - user must input a valid song

     output parms - will return 0 if input is valid and doesn't run over memory -1 otherwise
    */

    int addSong(Song const &s);


    /* FUNCTION - int removeSong
     * attempts to remove a song from the UtPod
     * removes the first instance of a song that is in the the UtPod multiple times
         o returns 0 if successful
         o returns -1 if nothing is removed


       input parms - song must exist in the list

       output parms - nothing is returned song is removed from the list
    */

    int removeSong(Song const &s);


    /* FUNCTION - void shuffle
     *  shuffles the songs into random order
        o will do nothing if there are less than two songs in the current list

       input parms - will do nothing if users UtPod has less than 3 songs otherwise songs are shuffled

       output parms - shuffled list of songs in the UtPod
    */

    void shuffle();




    /* FUNCTION - void showSongList
     * prints the current list of songs in order from first to last to standard output
     * format - Title, Artist, size in MB (one song per line)

       input parms - valid UtPod

       output parms - Prints list of songs in the UtPod
    */

    void showSongList();


    /* FUNCTION - void sortSongList
     *  sorts the songs in ascending order
        o will do nothing if there are less than two songs in the current list

       input parms - will do nothing if less than two songs

       output parms - sorted songs by artist, title, then size
    */

    void sortSongList();


    /* FUNCTION - void clearMemory
     * clears all the songs from memory

       input parms - none

       output parms - deletes and deallocates all memory in UtPod; all songs removed
    */
    void clearMemory();


    /* FUNCTION - int getTotalMemory
     *  returns the total amount of memory in the UtPod
        o will do nothing if there are less than two songs in the current list

       input parms - must be more than a single song

       output parms - returns the total memory
    */

    int getTotalMemory() {

        return memSize;
    }



    /* FUNCTION - int getRemainingMemory
     *  returns the amount of memory available for adding new songs

       input parms - a valid UtPod

       output parms - returns amount of memory left for songs
    */

    int getRemainingMemory();


    ~UtPod();

};



#endif //UNTITLED_UTPOD_H
