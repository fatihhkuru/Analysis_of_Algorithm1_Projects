	#ifndef _card_           // to include only once
#define _card_
//fatih KURU 150140040 

#include"Card.h"

Card::Card(){//default constructor
	name = " ";
	class2 = " ";
	rarity = " ";
	set = " ";
	cost = " ";
	type = " ";
}
void Card::add_name(string newName){//set a new name for object
	name = newName;
}
void Card::add_class(string newClass){//adding a class for object
	class2 = newClass;
}
void Card::add_rarity(string newRarity){// addinng a rarity attributes for object
	rarity = newRarity;
}
void Card::add_set(string newSet){// adding a set attributes for object
	set = newSet;
}
void Card::add_cost(string newCost){// adding a cost attributes for object
	cost = newCost;
}
void Card::add_type(string newType){// adding a type attributes for object
	type = newType;
}

Card::~Card(){

}
#endif