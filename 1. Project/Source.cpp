#include"Card.h"
#include"CardManager.h"
#include<iostream>
#include <fstream>
#include<cstring>
#include<vector>
#include<time.h>
#include <sstream>
//fatih KURU 150140040 

using namespace std;
int main(int argc,char*argv[]){

	string full_or_filter = argv[1];//first we assign the full or filter
	string insertion_or_merge = argv[2];// argument 2 is merge or insertion
	const char* open_file = argv[3];// input file name
	const char* write_file = argv[4];//output file name

	ifstream myfile(open_file);//opening the hs-set- series txt.
	
	int word_order = 0;//keep the order of number
	
	vector < Card >  list_of_Cards;//vector class which keep the object of cards
	string line;
	while (getline(myfile, line, '\n')) {
		stringstream ss(line);//line spliting
		string temp;//temp string
		Card templateCard;// template Card object
		while (getline(ss, temp, '\t')) {
			if (word_order == 0){//first one->> name
				templateCard.add_name(temp);
				word_order++;
			}
			else if (word_order == 1){//second one goes to class name
				templateCard.add_class(temp);
				word_order++;
			}
			else if (word_order == 2){// third one goes to rarity attributes
				templateCard.add_rarity(temp);
				word_order++;
			}
			else if (word_order == 3){//fourth one-->set
				templateCard.add_set(temp);
				word_order++;
			}
			else if (word_order == 4){//fifth one -->type
				templateCard.add_type(temp);
				word_order++;
			}
			else if (word_order == 5){//sixth one --> cost
				templateCard.add_cost(temp);
				word_order = 0;
			}
		}
		list_of_Cards.push_back(templateCard);
		
	}
	
	int r = list_of_Cards.size();//size of list of cards vector
	
	CardManager cardManager;//CardManager begins 
	
	clock_t begin,end;//definition of clocks
	
	int x = 0;
	begin = clock();
	if (argc == 5){
		if (full_or_filter == "-full"){//if user select the -full
			cardManager.fullSort(list_of_Cards, insertion_or_merge);
		}
		else if (full_or_filter == "-filter"){//if user select the -filter
			cardManager.filtersort(list_of_Cards, insertion_or_merge);
		}
		else{//wrong choice
			cout << "wrong choice of full or filter selection";
		}
	}
	else{
		cout << "wrong size of argument count" << endl;
		return 0;
	}
	end = clock();
	ofstream myfile2(write_file);
	while (x < r){//writing the objects into the file
		myfile2 << list_of_Cards[x].name << "\t" << list_of_Cards[x].class2 << "\t" << list_of_Cards[x].rarity << "\t" << list_of_Cards[x].set << "\t" << list_of_Cards[x].type << "\t" << list_of_Cards[x].cost << "\n";
		x++;
	}
	myfile2.close();//closing the opening txt's
	myfile.close();
	cout << "time elapsed: " << ((double)end - begin) / CLOCKS_PER_SEC <<"seconds"<< endl;//printing the time
}