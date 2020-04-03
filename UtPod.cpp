//
// Created by Andrew on 3/24/2020.
//

#include "UtPod.h"
#include "Song.h"


#include <iostream>
#include <string>
#include <random>
#include <ctime>
using namespace std;

/*
 *
 * Default Constructor
 *
 */


UtPod::UtPod(){
    memSize = MAX_MEMORY;
    songs = NULL;
    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);
}

/*
 *
 * Non-Default Constructor
 *
 */

UtPod::UtPod(int size) {
    memSize = size;
    songs = NULL;
    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);
}

/*
 *
 * Destructor
 *
 */
UtPod::~UtPod(){
    clearMemory();
}

/*
 *
 * addSong
 * * attempts to add a new song to the UtPod
         o returns a 0 if successful
         o returns -1 if not enough memory to add the song

     precondition: s is a valid Song

     input parms - user must input a valid song

     output parms - will return 0 if input is valid and doesn't run over memory -1 otherwise
 *
 */

int UtPod::addSong(const Song &s) {
    int tempMemSize = getRemainingMemory();
    //check if there is enough memory

    int songSize = s.getSize();
    if((songSize)>tempMemSize){
        return -1;
    }else{
        // add the song to the front on the linked list
        auto songP = new SongNode;
        songP->next = songs;
        songP->s = s;
        songs = songP;
        return 0;
    }
}
/* FUNCTION - int removeSong
     * attempts to remove a song from the UtPod
     * removes the first instance of a song that is in the the UtPod multiple times
         o returns 0 if successful
         o returns -1 if nothing is removed


       input parms - song must exist in the list

       output parms - nothing is returned song is removed from the list
    */
int UtPod::removeSong(Song const &s) {
    int tempMemSize = getRemainingMemory();
    // return if there are no songs to remove from the list
    if(tempMemSize == memSize){
        return -1;
    }else{
        SongNode* prevSong = NULL;
        SongNode* currentSong = songs;

        // iterate through the list until the song is found

        while(((Song) s == (currentSong->s)) == false){
            prevSong = currentSong;
            currentSong = currentSong->next;
        }
        // if at the front of the list set songs
        if(currentSong==songs){
            songs = currentSong->next;
            delete currentSong;
        }else if((currentSong->next)==NULL){
            prevSong->next = NULL;
            delete currentSong;
        }else{
            prevSong->next = currentSong->next;
            delete currentSong;
        }
        return 0;
    }
}
/* FUNCTION - int getRemainingMemory
     *  returns the amount of memory available for adding new songs

       input parms - a valid UtPod

       output parms - returns amount of memory left for songs
    */
int UtPod::getRemainingMemory() {
    SongNode* loopNode = songs;
    int memTotal = 0;
    // iterate through the list and count memory as you go
    while((loopNode)!=NULL){
        memTotal = memTotal + loopNode->s.getSize();
        loopNode = loopNode->next;
    }
    memTotal = memSize - memTotal;
    return(memTotal);
}
/* FUNCTION - void showSongList
    * prints the current list of songs in order from first to last to standard output
    * format - Title, Artist, size in MB (one song per line)

      input parms - valid UtPod

      output parms - Prints list of songs in the UtPod
   */
void UtPod::showSongList() {
    SongNode* ptr = songs;
    while(ptr!=NULL){
        cout << ptr->s.getTitle() << ", " << ptr->s.getArtist() << ", " << ptr->s.getSize() << " in MB"<< endl;
        ptr = ptr->next;
    }
}
/* FUNCTION - void clearMemory
     * clears all the songs from memory

       input parms - none

       output parms - deletes and deallocates all memory in UtPod; all songs removed
    */
void UtPod::clearMemory() {
    SongNode* ptr = songs;
    SongNode* temp = NULL;
    while(ptr!=NULL){
        temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
    ptr = NULL;
    songs = NULL;
}




/* FUNCTION - void shuffle
     *  shuffles the songs into random order
        o will do nothing if there are less than two songs in the current list

       input parms - will do nothing if users UtPod has less than 3 songs otherwise songs are shuffled

       output parms - shuffled list of songs in the UtPod
    */
void UtPod::shuffle(){
    SongNode* countP = songs;
    int count = 0;
    while(countP!=NULL){    //count the number of songs
        count++;
        countP = countP->next;
    }
    if(count<3){
        return;
    }

    SongNode* firstSongP = songs;
    SongNode* swapSongP = songs;
    SongNode* firstSongPrev = NULL;
    SongNode* swapSongPrev = NULL;

    // find a random offset between 1 and the number of songs

    int offset = (rand() % count);


    //iterate through the list to the random offset

    for(int i=0;i<offset;i++){
        swapSongPrev = swapSongP;
        swapSongP = swapSongP->next;
    }


    // swap the first song with a random spot first
    // don't touch the first song for the rest of the swaps
    songs = swapSongP;
    SongNode* tempNext = swapSongP->next;
    if(firstSongP->next==swapSongP){
        swapSongP->next = firstSongP;
        firstSongP->next = tempNext;
    }else {
        swapSongP->next = firstSongP->next;
        firstSongP->next = tempNext;
        if (swapSongPrev != NULL) {
            swapSongPrev->next = firstSongP;
        }
    }


    //swap the rest of the songs in random order
    for(int i=0;i<count+20;i++) {

        swapSongP = songs;
        firstSongP = songs;
        offset = (rand() % count);

        //move to a random offset first song

        for (int j = 0; j < offset; j++) {
            swapSongPrev = swapSongP;
            swapSongP = swapSongP->next;
        }
        offset = (rand() % count);

        //move to a random offset second song

        for (int j = 0; j < offset; j++) {
            firstSongPrev = firstSongP;
            firstSongP = firstSongP->next;
        }

        //swap the two randomly offset songs

        if((swapSongP!=songs)&&(firstSongP!=songs)) {
            if(firstSongP->next == swapSongP) {
                firstSongP->next = swapSongP->next;
                swapSongP->next = firstSongP;
                firstSongPrev->next = swapSongP;
            }else if(swapSongP->next == firstSongP){
                swapSongP->next = firstSongP->next;
                firstSongP->next = swapSongP;
                swapSongPrev->next = firstSongP;
            }else {
                tempNext = swapSongP->next;
                firstSongPrev->next = swapSongP;
                swapSongPrev->next = firstSongP;
                swapSongP->next = firstSongP->next;
                firstSongP->next = tempNext;
            }
        }


    }

}

/* FUNCTION - void sortSongList
     *  sorts the songs in ascending order
        o will do nothing if there are less than two songs in the current list

       input parms - will do nothing if less than two songs

       output parms - sorted songs by artist, title, then size
    */
void UtPod::sortSongList(){
    SongNode* countP = songs;
    int count = 0;
    while(countP!=NULL){    //count the number of songs
        count++;
        countP = countP->next;
    }

    if(count<2){   //do nothing if less than two songs in the list
        return;
    }

    SongNode* insertP = songs;
    SongNode* iterateP = songs;
    SongNode* smallestP;
    SongNode* prev1 = NULL;
    SongNode* prev2 = NULL;
    SongNode* temp;

    while(insertP!=NULL){
        smallestP = insertP;
        iterateP = insertP;
        while(iterateP!=NULL){
            if((iterateP->s)<(smallestP->s)){
                smallestP = iterateP;
            }
            iterateP = iterateP->next;
        }
        temp = songs;
        prev1 = NULL;
        while(temp!=smallestP){
            prev1 = temp;
            temp = temp->next;
        }

        if(insertP!=smallestP) {
            if (insertP == songs) { // when switching the first song in the list
                if(insertP->next == smallestP){
                    songs = smallestP;
                    insertP->next = smallestP->next;
                    smallestP->next = insertP;
                    insertP = smallestP;
                }else {
                    songs = smallestP;
                    temp = insertP->next;
                    insertP->next = smallestP->next;
                    smallestP->next = temp;
                    prev1->next = insertP;
                    insertP = smallestP;
                }
            }else if(insertP->next == smallestP) {

                //if songs are right next to each other but aren't at front of list

                insertP->next = smallestP->next;
                smallestP->next = insertP;
                prev2->next = smallestP;
                insertP = smallestP;

            } else {

                // not at front of the list but aren't next to each other

                temp = insertP->next;
                insertP->next = smallestP->next;
                prev2->next = smallestP;
                smallestP->next = temp;
                prev1->next = insertP;
                insertP = smallestP;
            }
        }
        prev2 = insertP;
        insertP = insertP->next;
    }



}




























