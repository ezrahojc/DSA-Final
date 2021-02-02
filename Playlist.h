// Matthias Gan
// Playlist.h - Definition of Playlist class

#pragma once
#include<string>
#include<iostream>
using namespace std;

class Playlist
{
private:
	int playlistId;
	string name;

public:
	Playlist();
	Playlist(int id, string n);

	void setPlaylistId(int id);
	int getPlaylistId();

	void setName(string n);
	string getName();

};

