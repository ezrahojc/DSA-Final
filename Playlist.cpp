// Matthias Gan, Ezra Ho
// Playlist.cpp - Implementation of Playlist class

#include <string>
#include <iostream>
#include "Playlist.h"

Playlist::Playlist() {}

Playlist::Playlist(int id, string n)
{

	playlistId = id;
	name = n;

}

void Playlist::setPlaylistId(int id) { playlistId = id; }
int Playlist::getPlaylistId() { return playlistId; }

void Playlist::setName(string n) { name = n; }
string Playlist::getName() { return name; }

