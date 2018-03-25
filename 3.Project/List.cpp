#ifndef _dictionary_           // to include only once
#define _dictionary_	
#include <math.h> //fatih KURU 150140040 
#include"List.h"

vector<BookCharacter>list_of_bookcharacter_forList;//list of book character in list

void List::insertion(vector<BookCharacter>&list_of_bookforinsertion){//insertion for list
	list_of_bookcharacter_forList.resize(131070);

	for (int i = 0; i < list_of_bookforinsertion.size(); i++){//adding one by one
		list_of_bookcharacter_forList[i] = list_of_bookforinsertion[i];
	}
}
void List::lookup(vector<BookCharacter>&list_of_bookforLookup){//look up function for list

	for (int i = 0; i < list_of_bookforLookup.size(); i++){
		int key_for_boookforlookup = list_of_bookforLookup[i].generate_key();
		for (int j = 0; j < list_of_bookcharacter_forList.size(); j++){
			int key_forbookcharacter_forlist = list_of_bookcharacter_forList[j].generate_key();
			if (key_for_boookforlookup == key_forbookcharacter_forlist){//if the keys are the same then character goes to lookup.txt
				string temp = list_of_bookcharacter_forList[j].get_character();
				list_of_bookforLookup[i].add_character(temp);
			}
		}
	}

}
#endif
