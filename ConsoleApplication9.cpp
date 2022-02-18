#include <iostream>
#include <string>
#include <utility>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Timer.h"



///////exercise 1

template< typename T > 
void Swap(T *a, T *b) {
	T temp = *a;
	*a = *b;
	*b = temp;
}

/////////

/////////// exercise 2

template< typename S >
void SortPointers(S &a) {
	int size = a.size();
	int temp;
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size-i-1; j++)
		{
			if (*a[j] > *a[j+1])
			{
				temp = *a[j];
				*a[j] = *a[j + 1];
				*a[j + 1] = temp;
			}
		}
	}
}

/////////


////////// exercise 3.1

bool found1(std::string mybook) {
	char arr[] = { 'a' , 'A' , 'e' , 'E' , 'i' , 'I' , 'o' , 'O' , 'U' , 'u' , 'y' , 'Y' };
	size_t a;
	for (size_t i = 0; i < sizeof(arr); i++)
	{
		a = mybook.find(arr[i], 0);
		if (a != std::string::npos)
		{
			return true;
		}
	}
	if (a == std::string::npos)
	{
		return false;
	}
}


template< typename T >
int count_find(T mybook) {
	Timer timer("Count_if & Find");
	int	count = count_if(mybook.begin(), mybook.end(), found1);
	timer.print();
	return count;
}

///////////

////////// exercise 3.2
bool found(std::string mybook) {
	for (size_t i = 0; i < mybook.size(); i++)
	{
		if (mybook[i] == 'a' || mybook[i] == 'A' || mybook[i] == 'e' || mybook[i] == 'E' || mybook[i] == 'I' ||
			mybook[i] == 'i' || mybook[i] == 'O' || mybook[i] == 'o' || mybook[i] == 'u' || mybook[i] == 'U' ||
			mybook[i] == 'y' || mybook[i] == 'Y')
		{
			return true;
		}
	}
}

template< typename T >
int count_for(T mybook) {
	Timer timer("Count_if & For");
	int count = count_if(mybook.begin(), mybook.end(), found);
	timer.print();
	return count;
}

///////// exercise 3.3

template< typename T >
int for_find(T mybook) {
	Timer timer("For & Find");
	int count = 0;
	size_t a;
	char arr[] = { 'a' , 'A' , 'e' , 'E' , 'i' , 'I' , 'o' , 'O' , 'U' , 'u' , 'y' , 'Y' };
	for (int i = 0; i < mybook.size(); i++)
	{
		for (size_t j = 0; j < sizeof(arr); j++)
		{
			a = mybook[i].find(arr[j], 0);
			if (a != std::string::npos)
			{
				count++;
			}
		}
	}
	timer.print();
	return count;
}

//////////

///////// exercise 3.4

template< typename T >
int for_for(T mybook) {
	Timer timer("For & For");
	int count = 0;
	for (int i = 0; i < mybook.size(); i++)
	{
		for (int j = 0; j < mybook[i].size(); j++)
		{
			if (mybook[i][j] == 'a' || mybook[i][j] == 'A' || mybook[i][j] == 'e' || mybook[i][j] == 'E' || mybook[i][j] == 'I' ||
				mybook[i][j] == 'i' || mybook[i][j] == 'O' || mybook[i][j] == 'o' || mybook[i][j] == 'u' || mybook[i][j] == 'U' ||
				mybook[i][j] == 'y' || mybook[i][j] == 'Y')
			{
				count++;
			}
		}
	}
	timer.print();
	return count;
}


////////////

int main()
{


	///////// exercise 1

	int variable1 = 15;
	int variable2 = 24;
	int* p_variable1 = &variable1;
	int* p_variable2 = &variable2;

	Swap(&p_variable1, &p_variable2);

	////////// 

	//////// exercise 2

	int a = 10, b = 20, c = 1, d = 15, e = 21;
	std::vector<int*> vector_of_pointers = { &a,&b,&c,&d,&e };

	for (int i = 0; i < vector_of_pointers.size(); i++)
	{
		std::cout << *vector_of_pointers.at(i) << " ";
	}
	std::cout << std::endl;

	SortPointers(vector_of_pointers);

	for (int i = 0; i < vector_of_pointers.size(); i++)
	{
		std::cout << *vector_of_pointers.at(i) << " ";
	}
	std::cout << std::endl;

	//////////// 

	//////// exercise 3

	std::ifstream file("War and peace.txt");
	std::vector<std::string> book;
	while (!file.eof())
	{
		std::string srt_var;
		file >> srt_var;
		book.push_back(srt_var);
	}
	
	//std::cout << count_find(book) << std::endl;
	//std::cout << count_for(book) << std::endl;
	//std::cout << for_find(book) << std::endl;
	//std::cout << for_for(book) << std::endl;


	/////////////

	system("pause");
	return 0;
}

