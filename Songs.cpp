// Matthias Gan, Ezra Ho
// Song.cpp - Implementation of Song class
#include <string>
#include <iostream>
#include "Songs.h"

using namespace std;

Song::Song() {}

Song::Song(int id, string t, string a, string g, int l)
{

	songId = id;
	title = t;
	artist = a;
	genre = g;
	length = l;

}

void Song::setSongId(int id) { songId = id; }
int Song::getSongId() { return songId; }

void Song::setTitle(string t) { title = t; }
string Song::getTitle() { return title; }


void Song::setArtist(string a) { artist = a; }
string Song::getArtist() { return artist; }


void Song::setGenre(string g) { genre = g; }
string Song::getGenre() { return genre; }


void Song::setLength(int l) { length = l; }
int Song::getLength() { return length; }

