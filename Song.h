#pragma once
// Matthias Gan
// Song.h - Definition of Song class

#include <string>
#include <iostream>
using namespace std;

class Song
{
private:
	int songId;
	string title;
	string artist;
	string genre;
	int length;
	string description;
	string album;

public:
	Song();
	Song(int id, string t, string a, string g, int l, string des, string al);

	void setSongId(int id);
	int getSongId();

	void setTitle(string t);
	string getTitle();

	void setArtist(string a);
	string getArtist();

	void setGenre(string g);
	string getGenre();

	void setLength(int l);
	int getLength();

	void setDescription(string g);
	string getDescription();

	void setAlbum(string g);
	string getAlbum();
};

