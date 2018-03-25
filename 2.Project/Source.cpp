#include<iostream>
#include <fstream>
#include<cstring>
#include<vector>
#include<time.h>
#include <sstream>
#include <cstdlib>
#include"Residence.h"


//fatih KURU 150140040 

using namespace std;
static int Partition(vector<Residence>&, int, int);
int randomized_partition(vector<Residence>&, int, int);
static void QuickSort(vector<Residence>&, int, int);


int main(int argc, char*argv[]){

	const char* open_file = "population_by_zip_2010.csv";//our data set
	const char* write_file = "order_population_by_zip_2010.csv";//where we write

	string number_of_residences = argv[1];//Number of residences to be processed

	ifstream myfile(open_file);//opening the file.

	int word_order = 0;//keep the order of number

	vector < Residence >  list_of_Residence;//vector class which keep the object of residence
	string line;
	int i = 0;
	int n = atoi(number_of_residences.c_str())+1;// n equal to number of residences
	while (i<n) {
		getline(myfile, line, '\n');
		stringstream ss(line);//line spliting
		string temp;//temp string
		Residence templatePopulation;// template Residence Object
		while (getline(ss, temp, ',')) {
			if (word_order == 0){//first one->> population
				templatePopulation.add_population(temp);
				word_order++;
			}
			else if (word_order == 1){//second one goes to minimum age
				templatePopulation.add_minimum_age(temp);
				word_order++;
			}
			else if (word_order == 2){// third one goes to maximum age
				templatePopulation.add_maximum_age(temp);
				word_order++;
			}
			else if (word_order == 3){//fourth one-->gender
				templatePopulation.add_gender(temp);
				word_order++;
			}
			else if (word_order == 4){//fifth one -->zipcode
				templatePopulation.add_zipcode(temp);
				word_order++;
			}
			else if (word_order == 5){//sixth one --> geo_id
				templatePopulation.add_geo_id(temp);
				word_order = 0;
			}
		}
		if (i != 0){
			list_of_Residence.push_back(templatePopulation);
		}
		i++;
	}

	int r = list_of_Residence.size();//size of list of Residence vector

	ofstream myfile2(write_file);//writing file
	int x = 0;
	
	clock_t begin, finish;//definition of clocks
	begin = clock();
	QuickSort(list_of_Residence, 0, r-1);
	finish = clock();

	while (x < r){//writing the objects into the file
		if (x == 0){
			myfile2 << "population,minimum_age,maximum_age,gender,zipcode,geo_id" << "\n";
		}
		myfile2 << list_of_Residence[x].get_population() << "," << list_of_Residence[x].get_minimum_age() << "," << list_of_Residence[x].get_maximum_age() << "," << list_of_Residence[x].get_gender() << "," << list_of_Residence[x].get_zipcode() << "," << list_of_Residence[x].get_geoId() << "\n";
		x++;
	}

	cout << "time elapsed: " << ((double)finish - begin)/CLOCKS_PER_SEC << "seconds" << endl;//printing the time
	myfile2.close();//closing the opening txt's
	myfile.close();


}
static int Partition(vector<Residence> &unsorted, int p, int r)//Partition section
{
	Residence x = unsorted[r];//pivot
	int i = p - 1;//left holder

	for (int j = p; j <= r - 1; j++)
	{
		if (atoi(unsorted[j].get_population().c_str()) < atoi(x.get_population().c_str()))//first we compare the population
		{
			i = i + 1;
			Residence temp1 = unsorted[i];//swaping
			unsorted[i] = unsorted[j];
			unsorted[j] = temp1;
		}
		if (atoi(unsorted[j].get_population().c_str()) == atoi(x.get_population().c_str()) && unsorted[j].get_geoId() <= x.get_geoId()){//if population is same then we check geo_Id

			i = i + 1;
			Residence temp1 = unsorted[i];//swaping
			unsorted[i] = unsorted[j];
			unsorted[j] = temp1;

		}
	}

	Residence temp2 = unsorted[i + 1];//swaping to the pivot the correct place
	unsorted[i + 1] = unsorted[r];
	unsorted[r] = temp2;
	return i + 1;
}
int randomized_partition(vector<Residence> &unsorted, int p, int r){//randomize picking the pivot
	int i = rand() % (r - p + 1) + p;
	Residence temp = unsorted[r];
	unsorted[r] = unsorted[i];
	unsorted[i] = temp;
	return Partition(unsorted, p, r);
}
static void QuickSort(vector<Residence> &unsorted, int p, int r)//quick sort algorithm
{
	if (p < r)
	{
		int q = Partition(unsorted, p, r);//pivot picking
		QuickSort(unsorted, p, q - 1);//recursion
		QuickSort(unsorted, q + 1, r);//recursion
	}
}

