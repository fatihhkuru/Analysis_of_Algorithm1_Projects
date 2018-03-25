#ifndef _dictionary_           // to include only once
#define _dictionary_			
#include <math.h> //fatih KURU 150140040 
#include"Dictionary.h"


vector < BookCharacter >  list_of_BookCharacter;//vector class which keep the object of cards
double collisionNumber_for1k = 0;
double collisionNumber_for10k = 0;
double collisionNumber_for100k = 0;
double collisionNumber_forOverall = 0;

void hashing_key(vector<BookCharacter>&, int , int );//prototype for hashing key for insertion
//int generate_key(vector<BookCharacter>&, int);
void hashing_key_forlookup(vector<BookCharacter>&, int,int);//prototype for hashing key for lookup
void get_collisionNumber();



void Dictionary::lookup(vector<BookCharacter>&list_of_bookforLookup){//lookup function
	for (int i = 0; i < list_of_bookforLookup.size(); i++){
		int key = list_of_bookforLookup[i].generate_key();	//generate key 					//generate_key(list_of_bookforLookup, i);
		hashing_key_forlookup(list_of_bookforLookup,key,i);//hashing the key

	}
}
void hashing_key_forlookup(vector<BookCharacter>&list_of_bookforLookup, int key, int index){//hashing key for lookup
	unsigned long  h_ussu;//h prime
	unsigned long  h = 131071 * fmod(key*0.618, 1);//h constant
	
	int i = 0;//probing number
	while (1){//infinite loop
		h_ussu = fmod((h + (7 * i) + (3 * i*i)), 131071);//hashing equality
		int key_for_input = list_of_BookCharacter[h_ussu].generate_key();//generating key				//generate_key(list_of_BookCharacter, h_ussu);
		if (key_for_input==key){//comparison for probing which is right or not
			string temp = list_of_BookCharacter[h_ussu].get_character();//if it is right than getting the character to lookup objects
			list_of_bookforLookup[index].add_character(temp);
			i = 0;
			break;
		}
		else {//if colision is occured 
			h = h_ussu;
			i++;
		}

	}

}

void Dictionary::insertion(vector<BookCharacter> &list_of_bookread){//insertion function
	clock_t begin, finish;//definition of clocks
	begin = clock();
	list_of_BookCharacter.resize(131071);//bookcharacter objects keep the list of objects where hashing function is occured
	for (int i = 0; i < list_of_bookread.size(); i++){
		
		int key = list_of_bookread[i].generate_key();//generate key				//generate_key(list_of_bookread, i);
		hashing_key(list_of_bookread, key, i);//hashing
	}
	finish = clock();
	cout << "DICTIONARY" << endl;
	cout << "Insertion finished after " << ((double)finish - begin) / CLOCKS_PER_SEC << "seconds" << endl<<endl;//printing the time
	get_collisionNumber();
}

void hashing_key(vector<BookCharacter>&list_of_bookread,int key,int index){//hashing key for insertion
	unsigned long  h_ussu;//h prime
	unsigned long  h = 131071 * fmod(key*0.618, 1);//h

	int i = 0;//number of probing
	while (1){//infinite loop
		h_ussu = fmod((h + (7 * i) +  (3* i*i)),131071);//hashing equality
		
		if (list_of_BookCharacter[h_ussu].get_page_number() == NULL && list_of_BookCharacter[h_ussu].get_line() == NULL && list_of_BookCharacter[h_ussu].get_index() == NULL){//if the place is empty, we will fill with it

			list_of_BookCharacter[h_ussu] = list_of_bookread[index];
			i = 0;
			break;
		}
		else {//if it is not empty
			h = h_ussu;
			i++;
			if (index < 1000){
				collisionNumber_for1k++;
				collisionNumber_for10k++;
				collisionNumber_for100k++;
				collisionNumber_forOverall++;
			}
			else if (index < 10000){
				collisionNumber_for10k++;
				collisionNumber_for100k++;
				collisionNumber_forOverall++;
			}
			else if (index < 100000){
				collisionNumber_for100k++;
				collisionNumber_forOverall++;
			}
			else if (index >= 100000){
				collisionNumber_forOverall++;
			}
		}

	}

}
void get_collisionNumber(){
	
	cout <<"Average number of collisions(first 1,000)	| "<<collisionNumber_for1k/1000<<endl;
	cout << "Average number of collisions(first 10,000)	| " << collisionNumber_for10k / 10000 << endl;
	cout << "Average number of collisions(first 100,000)	| "  << collisionNumber_for100k / 100000 << endl;
	cout << "Average number of collisions(overall)	| "  << collisionNumber_forOverall / 131070 << endl<<endl;

}

#endif
