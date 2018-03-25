#ifndef CARDMANAGER_H          // to include only once
#define CARDMANAGER_H
//fatih KURU 150140040 

#include<string>
#include"Card.h"
#include<vector>

using namespace std;

class CardManager{

public:
	CardManager();//default constructor
	void fullSort(vector < Card > &unsorted, string i);//full sort function of CardManager which sorts cards using 3 attribitues
	void filtersort(vector < Card > &unsorted,string i);// filter sort function of CardManager which sorts cards using 3 attribitues

};
#endif
