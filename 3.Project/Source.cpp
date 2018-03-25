#include<iostream>
#include <fstream>
#include<cstring>
#include<vector>
#include<time.h>
#include <sstream>
#include <cstdlib>
#include"BookCharacter.h"
#include"Dictionary.h"
#include"List.h"
//fatih KURU 150140040 
vector<BookCharacter> reading_file();
vector<BookCharacter> reading_file_forLookup();
void write_tofile(vector<BookCharacter>&,int);

int main(){
	Dictionary dictionary;
	List list;

	
	vector<BookCharacter>list_of_readforLookup;//Reading file which is lookup
	list_of_readforLookup.resize(131070);
	list_of_readforLookup = reading_file_forLookup();


	vector<BookCharacter>list_of_readforLookup_forlist;//reading file which is lookup 
	list_of_readforLookup.resize(131070);
	list_of_readforLookup_forlist = reading_file_forLookup();


	vector < BookCharacter >  list_of_BookCharacter_read;//vector class which keep the object of bookcharacter. Also reading a file from input
	list_of_BookCharacter_read.resize(131071);
	list_of_BookCharacter_read = reading_file();


	//-----Dictionary------
	dictionary.insertion(list_of_BookCharacter_read);//---insertion---

	clock_t begin, finish;//definition of clocks
	begin = clock();
	dictionary.lookup(list_of_readforLookup);//----lookup--------
	finish = clock();
	cout << "Lookup finished after " << ((double)finish - begin) / CLOCKS_PER_SEC << "seconds" << endl<<endl;//printing the time
	
	write_tofile(list_of_readforLookup,0);
	
	//--------List----------
	cout  << "LIST" << endl << endl;
	begin = clock();
	list.insertion(list_of_BookCharacter_read);//-------Insertion-------
	finish = clock();
	cout << "Insertion finished after " << ((double)finish - begin) / CLOCKS_PER_SEC << "seconds" << endl ;//printing the time

	begin = clock();
	list.lookup(list_of_readforLookup_forlist);//----Lookup------
	finish = clock();
	cout << "Lookup finished after " << ((double)finish - begin) / CLOCKS_PER_SEC << "seconds" << endl << endl;//printing the time
	write_tofile(list_of_readforLookup_forlist, 1);
	
}
vector<BookCharacter> reading_file(){
	const char* open_file = "ds-set-input.txt";//our data set


	ifstream myfile(open_file);//opening the txt.

	int word_order = 0;//keep the order of number

	vector < BookCharacter >  list_of_BookCharacter;//vector class which keep the object of bookcharacters
	list_of_BookCharacter.reserve(131071);
	string line;
	while (getline(myfile, line, '\n')) {
		stringstream ss(line);//line spliting
		string temp;//temp string
		BookCharacter templateBookCharacter;// template Bookcharacter object
		while (getline(ss, temp, '\t')) {
			if (word_order == 0){//first one->> page number
				templateBookCharacter.add_page_number(atoi(temp.c_str()));
				word_order++;
			}
			else if (word_order == 1){//second one goes to line name
				templateBookCharacter.add_line(atoi(temp.c_str()));
				word_order++;
			}
			else if (word_order == 2){// third one goes to index attributes
				templateBookCharacter.add_index(atoi(temp.c_str()));
				word_order++;
			}
			else if (word_order == 3){// third one goes to character attributes
				templateBookCharacter.add_character(temp.c_str());
				word_order = 0;
			}

		}
		list_of_BookCharacter.push_back(templateBookCharacter);
	}
	myfile.close();
	return list_of_BookCharacter;
}

vector<BookCharacter> reading_file_forLookup(){
	const char* open_file = "ds-set-lookup.txt";//our data set


	ifstream myfile(open_file);//opening the  txt.

	int word_order = 0;//keep the order of number

	vector < BookCharacter >  list_of_BookCharacter;//vector class which keep the object of bookcharacter
	list_of_BookCharacter.reserve(131071);
	string line;
	while (getline(myfile, line, '\n')) {
		stringstream ss(line);//line spliting
		string temp;//temp string
		BookCharacter templateBookCharacter;// template Bookcharacter object
		while (getline(ss, temp, '\t')) {
			if (word_order == 0){//first one->> page number
				templateBookCharacter.add_page_number(atoi(temp.c_str()));
				word_order++;
			}
			else if (word_order == 1){//second one goes to line name
				templateBookCharacter.add_line(atoi(temp.c_str()));
				word_order++;
			}
			else if (word_order == 2){// third one goes to index attributes
				templateBookCharacter.add_index(atoi(temp.c_str()));
				word_order=0;
			}
			
		}
		list_of_BookCharacter.push_back(templateBookCharacter);
	}
	myfile.close();
	return list_of_BookCharacter;
}

void write_tofile(vector<BookCharacter>&newlist_of_bookcharacter,int i){//write to file 
	const char* write_file;
	
	if (i==0)//if i equal to 0 that means dictionary is selected
		write_file = "ds-set-output-[dict].txt";
	else if (i == 1)//if i equal to 1 that means list is selected
		write_file = "ds-set-output-[list].txt";
	else//wrong i selection
		write_file = "wrong.txt";

	ofstream myfile2(write_file);//writing file

	for (int i = 0; i < newlist_of_bookcharacter.size(); i++){//writing one by one
		myfile2 << newlist_of_bookcharacter[i].get_page_number() << "\t" << newlist_of_bookcharacter[i].get_line() << "\t" << newlist_of_bookcharacter[i].get_index() << "\t" << newlist_of_bookcharacter[i].get_character()<<"\n";
	}
	myfile2.close();//closing the opening txt's



}