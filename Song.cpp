//
// Created by Andrew on 3/24/2020.
//

#include "Song.h"
#include <iostream>
#include <string>
/*
 *
 * Song Constructors
 *
 * 1. Default
 * 2-4. Non-Default
 *
 *
 *
 */
Song::Song(){
    title = "";
    artist = "";
    size = 0;
}

Song::Song(string inputTitle){
    title = inputTitle;
}

Song::Song(string inputTitle, string inputArtist){
    title = inputTitle;
    artist = inputArtist;
}

Song::Song(string inputTitle, string inputArtist, int inputSize){
    title = inputTitle;
    artist = inputArtist;
    size = inputSize;
}

/*
 *
 * Destructor
 *
 */

Song::~Song() =default;

void Song::setTitle(string s){
    title = s;
}
void Song::setArtist(string a){
    artist = a;
}
void Song::setSize(int s){
    size = s;
}
string Song::getTitle() const {
    return title;
}
string Song::getArtist() const {
    return artist;
}
int Song::getSize() const {
    return size;
}


/*
 * Overloading operators
 *
 * 1. < operator
 * 2. > operator
 * 3. == operator
 *
 *
 *
 */
bool Song::operator<(const Song &rhs) {
    if(artist<rhs.artist){
        return true;
    }else if((title<rhs.title)&&(artist==rhs.artist)){
        return true;
    }else if(((size<rhs.size)&&(artist==rhs.artist))&&(title==rhs.title)){
        return true;
    }else{
        return false;
    }
}


bool Song::operator>(const Song &rhs) {
    if(artist>rhs.artist){
        return true;
    }else if((title>rhs.title)&&(artist==rhs.artist)){
        return true;
    }else if(((size>rhs.size)&&(artist==rhs.artist))&&(title==rhs.title)){
        return true;
    }else{
        return false;
    }
}

bool Song::operator==(const Song &rhs) {
    if(((artist==rhs.artist)&&(title==rhs.title))&&(size==rhs.size)){
        return true;
    }else{
        return false;
    }
}









