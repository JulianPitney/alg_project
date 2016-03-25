#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;





/*				Things To Do (Lower Level)
//
//	1. Make generic derived class' constructor work [COMPLETE]
//	2. Implement bubblesort as test once basic generic sorter structure is built [COMPLETE]
//	3. Make variable names better
//	4. Make passing pointer to array of pointers to generic objects that have constructors to the constructor of an object from a generic derived class work [COMPLETE]
//	5. Drink mountain dew [COMPLETE]
//	6. Implement generic quicksort
//  	7. Implement generic mergesort
//  	8. Implement generic heapsort
// 	9. Generic print function (probably need a standar object specific implementation)
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


// This is broken. Need to come up with generic way for printing list of objects. Probably need standardized get_val or print_val 
// inside the objects being sorted.
template<class T> void Sorter<T>::print_sorting_array()
{
	cout << this->sorting_array_size << " elements in array \n\n";

	for (int i = 0; i < this->sorting_array_size ; i++)
	{
		cout << "Element #" << i << ":  " << sorting_array[i]->a << endl;
	}
}








// BUBBLE SORTER

template<class T> class Bubble_Sorter : public Sorter <T>
{
public:
	

	Bubble_Sorter(T* ptr_arr[], int sorting_array_size);
	int bubble_sort();

private:
};


template<class T> Bubble_Sorter<T>::Bubble_Sorter(T* ptr_arr[], int sorting_array_size) : Sorter<T>::Sorter(ptr_arr, sorting_array_size)
{
	cout << "Bubble sorter successfully created! \n";
}

template<class T> int Bubble_Sorter<T>::bubble_sort()
{
	bool swap_made = true;

	while (swap_made)
	{
		swap_made = false;

		for (int i = 0; i < this->sorting_array_size - 1; i++)
		{
			if (this->sorting_array[i]->compare(this->sorting_array[i + 1]) == 1)
			{
				T* temp = this-> sorting_array[i];
				this->sorting_array[i] = this->sorting_array[i + 1];
				this->sorting_array[i + 1] = temp;
				swap_made = true; 
			}
		}                
	}

	return 1;
}







// INSERTION SORTER

template<class T> class Insertion_Sorter : public Sorter < T >
{
public:

	Insertion_Sorter(T* ptr_arr[], int sorting_array_size);
	int insertion_sort();


protected:

};

template<class T> Insertion_Sorter<T>::Insertion_Sorter(T* ptr_arr[], int sorting_array_size) : Sorter<T>::Sorter(ptr_arr, sorting_array_size)
{
	cout << "Insertion Sorter successfully created! \n";
}

template<class T> int Insertion_Sorter<T>::insertion_sort()
{
	T* temp;

	for (int i = 1; i < sorting_array_size; i++)
	{
		for (int x = i - 1; i >= 0; i--)
		{
			if (this->sorting_array[x]->compare(this->sorting_array[i]) == 0)
			{
				
			}
		}
	}


	return 1;
}






// QUICK SORTER

template<class T> class Quick_Sorter : public Sorter<T>
{
public:

	Quick_Sorter(T* ptr_arr[], int sorting_array_size);
	int quick_sort();


private:

	bool infinite_recursion_flag = false;
	int quick_sort_internal(T* input_array[], int intput_array_size, int start_index, int end_index);
		
};

template<class T> Quick_Sorter<T>::Quick_Sorter(T* ptr_arr[], int sorting_array_size) : Sorter<T>::Sorter(ptr_arr, sorting_array_size)
{
	cout << "Quick_Sorter successfully created! \n";
}

template<class T> int Quick_Sorter<T>::quick_sort_internal(T* input_array[], int input_array_size, int start_index, int end_index)
{
	if (input_array_size <= 1)
	{
		return 1;
	}

	int middle_index;

	if (input_array_size % 2 == 0)
	{
		middle_index = input_array_size / 2;
	}
	else if (input_array_size % 2 == 1)
	{
		middle_index = (input_array_size / 2.0) - 0.5;
	}

	int pivot_index = middle_index + start_index;
	T* pivot = input_array[pivot_index];


	bool partitioned = false;
	int left = start_index;
	int right = end_index;
	int swap_left_index;
	int swap_right_index = pivot_index;
	T* temp;

	while (!partitioned)
	{
		for (; left < pivot_index; left++)
		{
			if (input_array[left]->compare(pivot) == 1)
			{
				swap_left_index = left;
				break;
			}
			else if (left == pivot_index - 1)
			{
				swap_left_index = pivot_index;
				break;
			}
		}

		for (; right > pivot_index; right--)
		{
			if (input_array[right]->compare(pivot) == -1 || input_array[right]->compare(pivot) == 0)
			{
				swap_right_index = right;
				break;
			}
			else if (right == pivot_index + 1)
			{
				swap_right_index = pivot_index;
				break;
			}
		}

		if (swap_right_index == swap_left_index)
		{
			if (input_array_size == 2)
			{
				return 1;
			}

			partitioned = true;
			break;
		}
		else if (swap_left_index == pivot_index)
		{
			temp = input_array[swap_left_index];
			input_array[swap_left_index] = input_array[swap_right_index];
			input_array[swap_right_index] = temp;
			pivot_index = swap_right_index;
		}
		else if (swap_right_index == pivot_index)
		{
			temp = input_array[swap_right_index];
			input_array[swap_right_index] = input_array[swap_left_index];
			input_array[swap_left_index] = temp;
			pivot_index = swap_left_index;
		}
		else
		{
			temp = input_array[swap_right_index];
			input_array[swap_right_index] = input_array[swap_left_index];
			input_array[swap_left_index] = temp;
		}
	}




	// Breaks recursion if infinite-recursion is detected. (The bubble sort component is a makeshift solution
	// to an error in my partition phase. It works for most cases but if the error condition in the partition pops up
	// at arrays larger than 10k i've set bubble sort to ignore it for the sake of performance. This means
	// we can correctly sort most large arrays but as we start to get into the high millions the error condition starts
	// to show up in >10000 sub-arrays and we end up with incorrect values.

	if ((pivot_index + 1) - (start_index) == input_array_size)
	{
		if (infinite_recursion_flag == true)
		{
			if (input_array_size < 10000)
			{
				bool swap_made = true;
				T* temp2;
				while (swap_made)
				{
					swap_made = false;
					for (int i = start_index; i < end_index + 1; i++)
					{
						if (input_array[i]->compare(input_array[i + 1]) == 1)
						{
							temp2 = input_array[i];
							input_array[i] = input_array[i + 1];
							input_array[i + 1] = temp2;
							swap_made = true;
						}
					}
				}
			}

			return 1;
		}
		else
		{
			infinite_recursion_flag = true;
			quick_sort_internal(input_array, (pivot_index + 1) - (start_index), start_index, pivot_index);
			infinite_recursion_flag = false;
			return 1;	
		}
	}


	quick_sort_internal(input_array, (pivot_index + 1) - (start_index), start_index, pivot_index);
	quick_sort_internal(input_array, (end_index + 1) - (pivot_index + 1), pivot_index + 1, end_index);


	return 1;
}

template<class T> int Quick_Sorter<T>::quick_sort()
{
	return this->quick_sort_internal(this->sorting_array, this->sorting_array_size, 0, this->sorting_array_size - 1);
}




// ARRAY GENERATORS

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
		else
		{
			// Returning 2 indicates error in comparison
			return -2;
		}
	}
};




int main()
{

	const int size = 10;
	int* int_arr = int_arr_gen(size);

	test_compare_object** test_arr = new test_compare_object*[size];

	for (int i = 0; i < size; i++)
	{
		test_arr[i] = new test_compare_object(int_arr[i]);
	}

	Insertion_Sorter<test_compare_object> *test3 = new Insertion_Sorter<test_compare_object>(test_arr, size);
	test3->insertion_sort();

 }
