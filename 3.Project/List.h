#ifndef _LIST_           // to include only once
#define _LIST_	
#include"BookCharacter.h"
#include<string>
#include<iostream>
#include <fstream>
#include<cstring>
#include<vector>
#include<time.h>
#include <sstream>
#include <cstdlib>

using namespace std;

class List{
public:
	void insertion(vector<BookCharacter>&);//insertion function
	void lookup(vector<BookCharacter>&);//lookup function
};
#endif
