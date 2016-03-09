#include <iostream>											// This program is meant to be a tool designed to give me access to generic high-performance sorting algorithms and data structures
#include <string>											// for use in my other projects. The learning goal is 2 pronged; I am trying to practice and learn better object-oriented
															// program design while also trying to gain a better understanding and familiarity with various useful algorithms/data structures.

using namespace std;																					// Author: Julian Pitney



/*				Things To Do (Lower Level)
//
//	1. Make generic derived class' constructor work [COMPLETE]
//	2. Implement bubblesort as test once basic generic sorter structure is built [COMPLETE]
//	3. Make variable names better
//	4. Make passing pointer to array of pointers to generic objects that have constructors to the constructor of an object from a generic derived class work [COMPLETE]
//	5. Drink mountain dew [COMPLETE]
//	6. Implement generic quicksort
//  7. Implement generic mergesort
//  8. Implement generic heapsort
//
//				Things To Do (Higher Level)
//
//  9. Implement various other interesting sorting algs (time permitting)
// 10. Implement generic high performance data structures for storing stuff before processing
// 11. See about alg visualization (maybe openGL?)
*/ 




// Sorter class (not meant to be instantiated directly, just a base for individual sorter types)
template <class T> class Sorter
{
public:

	Sorter(T* ptr_arr[], int sorting_array_size);
	void update_sorting_array(T* ptr_arr[], int sorting_array_size);
	void print_sorting_array();


protected:
	int sorting_array_size;
	T** sorting_array;

};

template<class T> Sorter<T>::Sorter(T* ptr_arr[], int sorting_array_size)
{
	this->sorting_array = ptr_arr;
	this->sorting_array_size = sorting_array_size;
}

template<class T> void Sorter<T>::update_sorting_array(T* updated_ptr_arr[], int sorting_array_size)
{
	this->sorting_array = updated_ptr_arr;
	this->sorting_array_size = sorting_array_size;
}

template<class T> void Sorter<T>::print_sorting_array()
{
	cout << this->sorting_array_size << " elements in array \n\n";

	for (int i = 0; i < this->sorting_array_size ; i++)
	{
		cout << "Element #" << i << ":  " << sorting_array[i]->a << endl;
	}
}









// Bubble-sorter
template<class T> class Bubble_Sorter : public Sorter <T>
{
public:
	

	Bubble_Sorter(T* ptr_arr[], int sorting_array_size);
	void bubble_sort();

private:
};


template<class T> Bubble_Sorter<T>::Bubble_Sorter(T* ptr_arr[], int sorting_array_size) : Sorter<T>::Sorter(ptr_arr, sorting_array_size)
{
	cout << "Bubble sorter successfully created! \n";
}




template<class T> void Bubble_Sorter<T>::bubble_sort()
{
	bool swap_made = true;

	while (swap_made)
	{
		swap_made = false;

		for (int i = 0; i < this->sorting_array_size - 1; i++)
		{
			if (this->sorting_array[i]->compare(this->sorting_array[i + 1]) == 1)
			{
				T* temp = sorting_array[i];
				sorting_array[i] = sorting_array[i + 1];
				sorting_array[i + 1] = temp;
				swap_made = true; 
			}
		}
	}
}



int* int_arr_gen(int size)
{
	int* output_arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		output_arr[i] = rand();
	}

	return output_arr;
}

string* str_arr_gen(int size)
{
	string* output_arr = new string[size];
	string s1;
	int askii_char;

	for (int i = 0; i < size; i++)
	{
		askii_char = rand() % 100 + 20;
		s1 = (char)askii_char;
		output_arr[i] = s1;
	}

	return output_arr;
}


class test_compare_object
{

public:

	int a;

	test_compare_object(int val)
	{
		this->a = val;
	}

	int get_val()
	{
		return this->a;
	}


	int compare(test_compare_object* compare_with)
	{
		if (this->a > compare_with->a)
		{
			return 1;
		}
		else if (this->a == compare_with->a)
		{
			return 0;
		}
		else if (this->a < compare_with->a)
		{
			return -1;
		}
	}
};




int main()
{

	const int size = 100;
	int* int_arr = int_arr_gen(size);

	test_compare_object** test_arr = new test_compare_object*[size];

	for (int i = 0; i < size; i++)
	{
		test_arr[i] = new test_compare_object(int_arr[i]);
	}

	Bubble_Sorter<test_compare_object> *test1 = new Bubble_Sorter<test_compare_object>(test_arr, size);

	test1->print_sorting_array();
	test1->bubble_sort();
	test1->print_sorting_array();

	
//  test1->bubble_sort();  <----- Don't work 

	




	return 0;
}