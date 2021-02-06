// Matthias Gan
// Song.cpp - Implementation of Song class

#include <string>
#include <iostream>
#include "Song.h"

using namespace std;

Song::Song() {}

Song::Song(int id, string t, string a, string g, int l, string des, string al)
{

	songId = id;
	title = t;
	artist = a;
	genre = g;
	length = l;
	description = des;
	album = al;
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

void Song::setDescription(string des) { description = des; }
string Song::getDescription() { return description; }

void Song::setAlbum(string al) { album = al; }
string Song::getAlbum() { return album; }

