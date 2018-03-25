#ifndef DICTIONARY_H
#define DICTIONARY_H
//fatih KURU 150140040 
#include<string>
#include"BookCharacter.h"
#include<iostream>
#include <fstream>
#include<cstring>
#include<vector>
#include<time.h>
#include <sstream>
#include <cstdlib>

using namespace std;

class Dictionary{

public:
	void insertion(vector<BookCharacter>&);//insertion function
	void lookup(vector<BookCharacter>&);//lookup function


};
#endif