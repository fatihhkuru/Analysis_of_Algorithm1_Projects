#ifndef _bookcharacter_           // to include only once
#define _bookcharacter_
//fatih KURU 150140040 

#include"BookCharacter.h"
BookCharacter::BookCharacter(){//default constructor
	page_number = NULL;
	line = NULL;
	index = NULL;
	character = "";
}
int BookCharacter::generate_key(){
	int key = page_number * 10000 + line* 100 + index;
	return key;
}
void BookCharacter::add_page_number(int new_page_number) {//adding page number to the Bookcharacter object
	page_number = new_page_number;
}

void BookCharacter::add_line(int new_line){//adding line to the Bookcharacter object
	line = new_line;
}

void BookCharacter::add_index(int new_index){//adding index to the Bookcharacter object
	index = new_index;
}
void BookCharacter::add_character(string new_character){//adding character to the Bookcharacter object
	character = new_character;
}

int BookCharacter::get_page_number(){//getting the page number from object
	return page_number;
}

int BookCharacter::get_index(){//getting the index from object
	return index;
}
int BookCharacter::get_line(){//getting the line from object
	return line;
}
string BookCharacter::get_character(){//getting the character from object
	return character;
}



#endif