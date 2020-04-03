//
// Created by Andrew on 3/24/2020.
//

#include <iostream>
#include <string>
#include "UtPod.h"
#include "Song.h"
using namespace std;



int main() {
    UtPod t;

    /*
     * ****************************************************************************
     * Sort Tests
     * 1. Size
     * 2. Title
     * 3. Artist
     * 4. Combination
     * 5. Three of the same
     * 6. Less than two songs
     *
     ******************************************************************************
     */

    cout << "***Sort Tests***" << endl;

    cout << "Size Test:" << endl;
    Song s1("A","A",1);
    int result = t.addSong(s1);
   // t.showSongList();

    Song s2("A", "A", 0);
    result = t.addSong(s2);
   // t.showSongList();

    Song s3("A", "A", 2);
    result = t.addSong(s3);
   // t.showSongList();

    Song s4("A", "A", 200);
    result = t.addSong(s4);
    t.showSongList();
    cout << endl << "sort:" <<endl;
    t.sortSongList();
    t.showSongList();
    int rMemory = t.getRemainingMemory();
    cout << endl << "remaining memory should be 309; remaining memory:" << rMemory <<endl;
    t.clearMemory();



    cout << "Title Test:" << endl;
    Song s5("A","A",1);
    result = t.addSong(s5);
    // t.showSongList();

    Song s6("B", "A", 1);
    result = t.addSong(s6);
    // t.showSongList();

    Song s7("C", "A", 1);
    result = t.addSong(s7);
    // t.showSongList();

    Song s8("Z", "A", 1);
    result = t.addSong(s8);
    t.showSongList();
    cout << endl << "sort:" <<endl;
    t.sortSongList();
    t.showSongList();
    rMemory = t.getRemainingMemory();
    cout << endl << "remaining memory should be 508; remaining memory:" << rMemory <<endl;
    t.clearMemory();



    cout << "Artist Test:" << endl;
    Song s9("A","A",1);
    result = t.addSong(s9);
    // t.showSongList();

    Song s10("A", "B", 1);
    result = t.addSong(s10);
    // t.showSongList();

    Song s11("A", "C", 1);
    result = t.addSong(s11);
    // t.showSongList();

    Song s12("A", "Z", 1);
    result = t.addSong(s12);
    t.showSongList();
    cout << endl << "sort:" <<endl;
    t.sortSongList();
    t.showSongList();
    t.clearMemory();



    cout << "Combination Test:" << endl;
    Song s20("Old Town Road", "Lil Nas X", 5);
    result = t.addSong(s20);
    Song s21("Senorita", "Shawn Mendes", 10);
    result = t.addSong(s21);
    Song s22("bad guy", "Billie Eilish", 50);
    result = t.addSong(s22);
    Song s23("Sucker", "Jonas Brothers", 15);
    result = t.addSong(s23);
    Song s24("Memories", "Maroon 5", 5);
    result = t.addSong(s24);
    Song s25("Old Town Road", "Lil Nas X", 5);
    result = t.addSong(s25);
    Song s26("Blinding Lights", "The Weeknd", 200);
    result = t.addSong(s26);
    Song s27("Circles", "Post Malone", 4);
    result = t.addSong(s27);
    Song s28("7 rings", "Ariana Grande", 20);
    result = t.addSong(s28);
    Song s29("The Box", "Roddy Ricch", 1);
    result = t.addSong(s29);

    t.showSongList();
    cout << endl << "Sorted:" << endl;
    t.sortSongList();
    t.showSongList();
    t.clearMemory();
    cout << endl;

    //Three of the same song test
    cout << "Three of a kind test:" << endl;
    Song s30("Baby", "Justin Bieber", 5);
    result = t.addSong(s30);
    Song s31("Baby", "Justin Bieber", 5);
    result = t.addSong(s31);
    Song s32("Baby", "Justin Bieber", 5);
    result = t.addSong(s32);
    Song s33("Dancing with a Stranger", "Sam Smith", 5);
    result = t.addSong(s33);
    Song s34("Adore You", "Harry Styles", 5);
    result = t.addSong(s34);
    t.showSongList();
    cout << endl << "sorted:" << endl;
    t.sortSongList();
    t.showSongList();
    cout << endl;
    t.clearMemory();

    cout << "Less than two test:" << endl;
    Song s45("EARFQUAKE", "Tyler, the Creator", 5);
    t.addSong(s45);
    t.showSongList();
    cout << endl;
    t.sortSongList();
    t.showSongList();



    /*
     ****************************************************************
     * shuffle test
     *
     ****************************************************************
     */

    t.clearMemory();
    cout << "***Shuffle Tests***";
    cout << endl << "Shuffle Test 1:" << endl;
    Song s13("A", "Z", 1);
    result = t.addSong(s13);
    cout << result << endl;

    Song s14("B", "Z", 1);
    result = t.addSong(s14);
    cout << result << endl;

    Song s15("C", "Z", 1);
    result = t.addSong(s15);
    cout << result << endl;

    Song s16("D", "Z", 1);
    result = t.addSong(s16);
    cout << result << endl;

    Song s17("E", "Z", 1);
    result = t.addSong(s17);
    cout << result << endl << endl;

    t.showSongList();
    cout << endl << "shuffled:" << endl;
    t.shuffle();
    t.showSongList();
    cout << endl;
    t.clearMemory();


    //Shuffle Test 2

    cout << endl << "Shuffle Test 2:" <<endl;
    Song s35("Old Town Road", "Lil Nas X", 5);
    result = t.addSong(s35);
    Song s36("Senorita", "Shawn Mendes", 10);
    result = t.addSong(s36);
    Song s37("bad guy", "Billie Eilish", 50);
    result = t.addSong(s37);
    Song s38("Sucker", "Jonas Brothers", 15);
    result = t.addSong(s38);
    Song s39("Memories", "Maroon 5", 5);
    result = t.addSong(s39);
    Song s40("Old Town Road", "Lil Nas X", 5);
    result = t.addSong(s40);
    Song s41("Blinding Lights", "The Weeknd", 200);
    result = t.addSong(s41);
    Song s42("Circles", "Post Malone", 4);
    result = t.addSong(s42);
    Song s43("7 rings", "Ariana Grande", 20);
    result = t.addSong(s43);
    Song s44("The Box", "Roddy Ricch", 1);
    result = t.addSong(s44);

    t.showSongList();
    cout << endl << "Shuffled:" << endl;
    t.shuffle();
    t.showSongList();
    t.clearMemory();
    cout << endl;

    cout << "two or less songs test:" << endl;
    Song s47("7 rings", "Ariana Grande", 20);
    result = t.addSong(s47);
    Song s48("The Box", "Roddy Ricch", 1);
    result = t.addSong(s48);
    t.showSongList();
    t.shuffle();
    t.showSongList();
    t.removeSong(s48);
    cout <<endl;
    t.shuffle();
    t.showSongList();
    t.clearMemory();
    cout << endl;


    /*
     *****************************************************************************
     *
     * addSong max limit test & removeSong test
     *
     * ***************************************************************************
     */

    cout << "***addSong limit test & removeSong test***" <<endl;
    t.clearMemory();
    Song s18("A", "A", 512);
    result = t.addSong(s18);
    cout << "add song result = " << result << endl;
    t.showSongList();
    cout << endl;
    rMemory = t.getRemainingMemory();
    cout << endl << "remaining memory should be 0; remaining memory:" << rMemory <<endl;

    t.removeSong(s18);
    Song s19("B", "B",513);
    result = t.addSong(s19);
    cout << result << endl;
    t.showSongList();
    cout << endl;

    /*
     ****************************************************************************
     *
     * showSongList Tests
     *
     * **************************************************************************
     */

    cout << "***showSongList Tests***" << endl;

    cout << "nothing in list test:" << endl;

    t.clearMemory();
    t.showSongList();


    cout << "***getRemainingMemory Tests & removing non-existant songs Test***" << endl;

    cout << "Test 1: desired result: 197" << endl;
    Song s50("Old Town Road", "Lil Nas X", 5);
    result = t.addSong(s50);
    Song s51("Senorita", "Shawn Mendes", 10);
    result = t.addSong(s51);
    Song s52("bad guy", "Billie Eilish", 50);
    result = t.addSong(s52);
    Song s53("Sucker", "Jonas Brothers", 15);
    result = t.addSong(s53);
    Song s54("Memories", "Maroon 5", 5);
    result = t.addSong(s54);
    Song s55("Old Town Road", "Lil Nas X", 5);
    result = t.addSong(s55);
    Song s56("Blinding Lights", "The Weeknd", 200);
    result = t.addSong(s56);
    Song s57("Circles", "Post Malone", 4);
    result = t.addSong(s57);
    Song s58("7 rings", "Ariana Grande", 20);
    result = t.addSong(s58);
    Song s59("The Box", "Roddy Ricch", 1);
    result = t.addSong(s59);

    t.showSongList();
    int reMem = t.getRemainingMemory();
    cout << "actual result: " << reMem << endl;
    t.removeSong(s50);
    t.removeSong(s51);
    t.removeSong(s52);
    t.removeSong(s53);
    t.removeSong(s54);
    t.removeSong(s55);
    t.removeSong(s56);
    t.removeSong(s57);
    t.removeSong(s58);
    t.removeSong(s59);
    //attempt to remove a song not in list
    t.removeSong(s59);
    t.showSongList();


    cout << "Test 2: desired result: 61" << endl;
    Song s60("Old Town Road", "Lil Nas X", 134);
    result = t.addSong(s60);
    Song s61("Senorita", "Shawn Mendes", 67);
    result = t.addSong(s61);
    Song s62("bad guy", "Billie Eilish", 250);
    result = t.addSong(s62);

    t.showSongList();
    reMem = t.getRemainingMemory();
    cout << "actual result: " << reMem << endl;
    t.removeSong(s60);
    t.removeSong(s61);
    t.removeSong(s62);
    t.showSongList();
    t.clearMemory();


    //Constructor test
    /*
     ****************************************************************
     * Non-Default UtPod Constructor Test
     *
     ****************************************************************
     */

    cout << "***Non-Default UtPod Constructor Test***" << endl;

    UtPod iPod(250);
    cout << "input memory: 250" << endl;

    Song s63("Old Town Road", "Lil Nas X", 1);
    result = iPod.addSong(s63);
    cout << "result = " << result << endl;
    iPod.showSongList();
    Song s64("Senorita", "Shawn Mendes", 1);
    result = iPod.addSong(s64);
    cout << "result = " << result << endl;
    iPod.showSongList();
    Song s65("bad guy", "Billie Eilish", 248);
    result = iPod.addSong(s65);
    cout << "result = " << result << endl;
    iPod.showSongList();
    iPod.getRemainingMemory();
    Song s70("Sunflower", "Swae Lee", 1);
    result = iPod.addSong(s70);
    cout << "result = " << result << endl;
    if(result == -1){
        cout << "can't add over 250" << endl;
    }
    iPod.clearMemory();


    /*
     ****************************************************************
     * Default Song Constructor Test
     *
     ****************************************************************
     */

    cout << "***Default Song Test***" << endl;

    Song s71;
    iPod.addSong(s71);
    cout << "default song should print:" << endl;
    iPod.showSongList();
    iPod.clearMemory();

    /*
    ****************************************************************
    * getTotalMemory Test
    *
    ****************************************************************
    */

    cout << "***getTotalMemory Tests***" << endl;

    UtPod mp3(35);
    UtPod radio(111);
    UtPod bluesClues;

    result = mp3.getTotalMemory();
    cout << endl << "desired: 35";
    cout << endl << "actual: " << result << endl;
    result = radio.getTotalMemory();
    cout << endl << "desired: 111";
    cout << endl << "actual: " << result << endl;
    result = bluesClues.getTotalMemory();
    cout << endl << "desired: 512";
    cout << endl << "actual: " << result << endl;












/*
    Song s5("Zrange", "A", 4);
    result = t.addSong(s5);
  //  t.showSongList();

    Song s6("Zranga", "A", 5);
    result = t.addSong(s6);
  //  t.showSongList();

    Song s7("Zrange", "Ab", 5);
    result = t.addSong(s7);
 //   t.showSongList();

    Song s8("Zrange", "A", 5);
    result = t.addSong(s8);
    t.showSongList();
    cout << endl << "sort" << endl;
    t.sortSongList();
    t.showSongList();
*/
/*
    Song s1("A", "A", 1);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;

    t.showSongList();

    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;

    t.showSongList();

    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;

    Song s4("Bpple", "Bpple", 6);
    result = t.addSong(s4);
    cout << "result = " << result << endl;

    Song s5("Apple", "Apple", 8);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    t.showSongList();
    cout << "sort" << endl;
    t.sortSongList();
    t.showSongList();

    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();

    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;


    t.showSongList();

    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;

    cout << "before clear:" <<endl;
    t.showSongList();
    cout << "after clear:" << endl;
    t.clearMemory();
    t.showSongList();
*/
}
