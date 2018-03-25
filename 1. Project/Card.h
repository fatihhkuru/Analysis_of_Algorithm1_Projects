#ifndef CARD_H
#define CARD_H
//fatih KURU 150140040 


#include<string>

using namespace std;
class Card{
public:
	string name;//name of the card
	string class2;//class of the card
	string rarity;// rarity of the card
	string set;//set of the card
	string type;// type of the card
	string  cost;// cost of the card

public:
	Card();//default constructor

	void add_name(string);//adding a name into the object
	void add_class(string);//adding a class into the object
	void add_rarity(string);//adding a rarity into the object
	void add_set(string);//adding a set attributes into the object
	void add_type(string);//adding a type attributes into the object
	void add_cost(string);//adding a cost attributes into the object
	~Card();//destructor
};
#endif