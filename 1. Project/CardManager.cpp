#include"CardManager.h"
#include<iostream>
#include <cstdlib>
//fatih KURU 150140040 


static void mergeSort(vector<Card>&, int, int);
static void merge(vector<Card>&, int, int, int);
static void merge_filter(vector<Card>&, int, int, int);
static void mergeSort_filter(vector<Card>&, int, int);

CardManager::CardManager(){//default constructor

}
void CardManager::fullSort(vector<Card> &unsorted,string i){//Full sort 
	if (i == "-i"){//if user select insertion sort
		int r = unsorted.size();//size of unsorted list which is list of cards
		for (int j = 1; j < r; j++)//insertion sort algorithms
		{
			string keyClass = unsorted.at(j).class2;//Our priority is class 
			Card keyCard = unsorted[j];// template Card Object
			int i = j - 1;
			while (i >= 0 && ((unsorted.at(i).class2 > keyClass) || (unsorted.at(i).class2 == keyClass && atoi(unsorted.at(i).cost.c_str()) > atoi(keyCard.cost.c_str())) || (unsorted.at(i).class2 == keyClass && unsorted.at(i).cost == keyCard.cost && unsorted.at(i).name > keyCard.name)))
			{//we check fist i which is in before the key. Then we check class attributes . after that if classes are the same , we will look at costs. Ýf classes and cost are the same , we will look for names.
				unsorted[i + 1] = unsorted[i];
				i = i - 1;
			}

			unsorted[i + 1] = keyCard;
		}
	}
	else if (i == "-m"){//If users select merge sort 
		int k = unsorted.size();//size of unsorted vector
		mergeSort(unsorted, 0, k - 1);//merge sort calling
	}
	else{// If users select meaningless selection 
		std::cout << "Wrong choice" << endl;
	}

}
void CardManager::filtersort(vector<Card> &unsorted, string i){//Filter sort
	if (i == "-i"){//if user select insertion sort
		int r = unsorted.size();//size of unsorted list which is list of cards
		for (int j = 1; j < r; j++)//insertion sort algorithms
		{
			string keyType = unsorted.at(j).type;//Our priority is type
			Card keyCard = unsorted[j];// template Card Object
			int i = j - 1;
			while (i >= 0 && unsorted.at(i).type > keyType)
			{
				unsorted[i + 1] = unsorted[i];
				i = i - 1;
			}

			unsorted[i + 1] = keyCard;
		}
	}
	else if (i == "-m"){//Merge sort
		int k = unsorted.size();//size of unsorted vector
		mergeSort_filter(unsorted, 0, k-1);//merge sort 
	}
	else{
		std::cout << "Wrong Choice" << endl;
	}
}
static void mergeSort(vector<Card>&temp, int p, int r)//Merge sort for full sorts
{
	int q;

	if (p < r)//if p less than r which means left is not equal to right 
	{
		q = (p + r) / 2;//middle element of vector
		mergeSort(temp, p, q);//left recurrence
		mergeSort(temp, q + 1, r);//right recurrence
		merge(temp, p, q, r);//merging phase
	}

}
static void merge(vector<Card>& temp, int p, int q, int r)//Merge for full sorts
{
	int n1 = q - p + 1;//left size 
	int n2 = r - q;//right size

	vector<Card> left(n1 + 1);//left vector 
	vector<Card> right(n2 + 1);//right vector

	for (int i = 0; i < n1; i++)//left one is assigned
		left[i] = temp[p + i];

	for (int j = 0; j < n2; j++)//right one is assigned
		right[j] = temp[q + j + 1];

	left[n1].class2 = "}}}";// this is infinity for our datas
	right[n2].class2 = "}}}";///this is also infintiy for our datas

	int x = 0, y = 0;

	for (int k = p; k <= r; k++)//comparision phase starting
	{
		if (left[x].class2 < right[y].class2)//first we check class
		{
			temp[k] = left[x];
			x++;
		}
		else if (left[x].class2> right[y].class2)//
		{
			temp[k] = right[y];
			y++;
		}
		else if ((left[x].class2 == right[y].class2) && (atoi(left[x].cost.c_str()) < atoi(right[y].cost.c_str()))){//then classes are the same, we check coost
			temp[k] = left[x];
			x++;
		}
		else if ((left[x].class2 == right[y].class2) && (atoi(left[x].cost.c_str()) > atoi(right[y].cost.c_str()))){
			temp[k] = right[y];
			y++;
		}
		else if ((left[x].class2 == right[y].class2) && (atoi(left[x].cost.c_str()) == atoi(right[y].cost.c_str())) && (left[x].name <= right[y].name)){//if costs and classes are the same, we check name
			temp[k] = left[x];
			x++;
		}
		else{
			temp[k] = right[y];
			y++;
		}


	}
}
static void mergeSort_filter(vector<Card>&temp, int p, int r)//merge sort for filter sort 
{
	int q;

	if (p < r)//if p less than r which means left is not equal to right 
	{
		q = (p + r) / 2;
		mergeSort_filter(temp, p, q);//middle element of vector
		mergeSort_filter(temp, q + 1, r);//left recurrence
		merge_filter(temp, p, q, r);//right recurrence
	}

}
static void merge_filter(vector<Card>& temp, int p, int q, int r)
{
	int n1 = q - p + 1;//left size
	int n2 = r - q;//right size

	vector<Card> left(n1 + 1);//left vector 
	vector<Card> right(n2 + 1);//right vector

	for (int i = 0; i < n1; i++)//left one is assigned
		left[i] = temp[p + i];

	for (int j = 0; j < n2; j++)//right one is assigned
		right[j] = temp[q + j + 1];

	left[n1].type= "}}}";// this is infinity for our datas
	right[n2].type = "}}}";// this is also infinity for our datas

	int x = 0, y = 0;

	for (int k = p; k <= r; k++)//comparision phase starting
	{
		if (left[x].type <= right[y].type)//first we check type
		{
			temp[k] = left[x];
			x++;
		}
		else  {
			temp[k] = right[y];
			y++;
		}
		


	}
}



