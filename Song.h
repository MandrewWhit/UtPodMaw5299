//
// Created by Andrew on 3/24/2020.
//
#include <iostream>
#include <string>
using namespace std;


#ifndef UNTITLED_SONG_H
#define UNTITLED_SONG_H


/*
 *Song Class
 *
 *private instance variables include the title, artist, and size in MB
 *
 *multiple constructors based on the input as well as the default constructor
 *destructor is also included as a public function
 *set and get functions allow for the UtPod to access instance variables
 *operators are overloaded to compare songs in the order artist, title, size
 *
 *
 *
 */

class Song
{
private:
        string title;
        string artist;
        int size;


public:
        Song();
        Song(string inputTitle);
        Song(string inputTitle, string inputArtist);
        Song(string inputTitle, string inputArtist, int inputSize);
        bool operator> (const Song &rhs);
        bool operator< (const Song &rhs);
        bool operator== (const Song &rhs);
        string getTitle() const;
        string getArtist() const;
        int getSize() const;
        void setTitle(string t);
        void setArtist(string a);
        void setSize(int s);
        ~Song();
};



#endif //UNTITLED_SONG_H




