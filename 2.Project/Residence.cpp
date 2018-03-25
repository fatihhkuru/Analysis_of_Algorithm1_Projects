#ifndef _residence_           // to include only once
#define _residence_
//fatih KURU 150140040 

#include"Residence.h"

Residence::Residence(){//default constructor
	population = " ";
	maximum_age = " ";
	minimum_age = " ";
	gender = " ";
	zipcode = " ";
	geo_id = " ";
}
Residence::Residence(string pop, string max, string min, string gen, string zip, string geo){
	population = pop;
	maximum_age = max;
	minimum_age = min;
	gender = gen;
	zipcode = zip;
	geo_id = geo;
}
void Residence::add_population(string newPopulation){//set a new population for object
	population = newPopulation;
}
void Residence::add_maximum_age(string newMaximum_age){//adding a maximum_age for object
	maximum_age = newMaximum_age;
}
void Residence::add_minimum_age(string newMinimum_age){// addinng a minimum_age for object
	minimum_age = newMinimum_age;
}
void Residence::add_gender(string newGender){// adding a new gender for object
	gender = newGender;
}
void Residence::add_zipcode(string newZipcode){// adding a newZipcode for object
	zipcode = newZipcode;
}
void Residence::add_geo_id(string newGeo_id){// adding a new Geo_id for object
	geo_id = newGeo_id;
}
//-----getter Functions-----
string Residence::get_population(){
	return population;
}
string Residence::get_minimum_age(){
	return minimum_age;
}
string Residence::get_maximum_age(){
	return maximum_age;
}
string Residence::get_gender(){
	return gender;
}
string Residence::get_zipcode(){
	return zipcode;
}
string Residence::get_geoId(){
	return geo_id;
}
//--Destructor----
Residence::~Residence(){

}
#endif