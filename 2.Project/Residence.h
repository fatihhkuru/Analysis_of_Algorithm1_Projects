#ifndef RESIDENCE_H
#define RESIDENCE_H
//fatih KURU 150140040 


#include<string>

using namespace std;
class Residence{
private:
	string population;//population of the residence class
	string minimum_age;//minimum age of the residence
	string maximum_age;// maximum age of the residence
	string gender;//gender of the residence
	string zipcode;// zipcode of the residence
	string  geo_id;// geo_id of the residence

public:
	Residence();//default constructor
	Residence(string, string, string, string, string, string);

	void add_population(string);//adding a population into the object
	void add_minimum_age(string);//adding a minimum age into the object
	void add_maximum_age(string);//adding a maximum age into the object
	void add_gender(string);//adding a gender into the object
	void add_zipcode(string);//adding a zipcode into the object
	void add_geo_id(string);//adding a geo_id into the object
	
	string get_population();//-----getter functions---
	string get_minimum_age();
	string get_maximum_age();
	string get_gender();
	string get_zipcode();
	string get_geoId();

	~Residence();//destructor
};
#endif