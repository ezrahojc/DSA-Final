#pragma once
// Matthias Gan, Ezra Ho
// Songs.h - Definition of Song class

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

public:
	Song();
	Song(int id, string t, string a, string g, int l);

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
};

