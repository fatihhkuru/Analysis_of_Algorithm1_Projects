#ifndef BOOKCHARACTER_H
#define BOOKCHARACTER_H
//fatih KURU 150140040 
#include<string>

using namespace std;

class BookCharacter{
private:
	int page_number;//book variables 
	int line;
	int index;
	string character;
public:
	BookCharacter();//default constructor
	void add_page_number(int);//setter functions
	void add_line(int);
	void add_index(int);
	void add_character(string);//-------
	

	int get_page_number();//getter functions
	int get_line();
	string get_character();
	int get_index();//------

	int generate_key();

};
#endif