#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>

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
	int find_arr_midpoint(int start_index, int end_index);
	int get_arr_size();
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

template<class T> int Sorter<T>::get_arr_size()
{
	return this->sorting_array_size;
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

template<class T> int Sorter<T>::find_arr_midpoint(int start_index, int end_index)
{
	if (start_index + end_index == 0)
	{
		return 0;
	}
	else
	{
		return (start_index + end_index) / 2;
	}
}






// BUBBLE SORTER

template<class T> class Bubble_Sorter : public Sorter <T>
{
public:
	

	Bubble_Sorter(T* ptr_arr[], int sorting_array_size);
	int sort();

private:
};


template<class T> Bubble_Sorter<T>::Bubble_Sorter(T* ptr_arr[], int sorting_array_size) : Sorter<T>::Sorter(ptr_arr, sorting_array_size)
{
	cout << "Bubble sorter successfully created! \n";
}

template<class T> int Bubble_Sorter<T>::sort()
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

template<class T> class Insertion_Sorter : public Sorter <T>
{
public:

	Insertion_Sorter(T* ptr_arr[], int sorting_array_size);
	int sort();


protected:

};

template<class T> Insertion_Sorter<T>::Insertion_Sorter(T* ptr_arr[], int sorting_array_size) : Sorter<T>::Sorter(ptr_arr, sorting_array_size)
{
	cout << "Insertion Sorter successfully created! \n";
}

template<class T> int Insertion_Sorter<T>::sort()
{
	T* temp;
	
	for (int i = 1; i < this->sorting_array_size; i++)
	{
		for (int z = i - 1; z >= 0; z--)
		{
			if (this->sorting_array[i]->compare(this->sorting_array[z]) == 0 || this->sorting_array[i]->compare(this->sorting_array[z]) == -1)
			{
				temp = this->sorting_array[i];

				for (int x = i; x >= z + 1; x--)
				{
					this->sorting_array[x] = this->sorting_array[x - 1];
				}

				this->sorting_array[z + 1] = temp;
				break;
			}
			else
			{ 
				if (z == 0)
				{
					temp = this->sorting_array[i];

					for (int h = i; h > 0; h--)
					{
						this->sorting_array[h] = this->sorting_array[h - 1];
					}

					this->sorting_array[0] = temp;
					break;
				}
				
				continue;
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
	int sort();


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

template<class T> int Quick_Sorter<T>::sort()
{
	return this->quick_sort_internal(this->sorting_array, this->sorting_array_size, 0, this->sorting_array_size - 1);
}







// Merge Sort

template<typename T> struct mSort_ReturnPkg
{
	T** arr_ptr;
	int arr_size;
};

template<class T> class Merge_Sorter : public Sorter<T>
{
public:
	Merge_Sorter(T* arr_ptr[], int array_size);
	void sort();
	mSort_ReturnPkg<T> merge_sort_internal(T* input_array[], int arr_size);
protected:

};

template<class T> Merge_Sorter<T>::Merge_Sorter(T* arr_ptr[], int array_size) : Sorter<T>::Sorter(arr_ptr, array_size)
{
	cout << "Merge sorter successfully created \n";
}

template<class T> void Merge_Sorter<T>::sort()
{
	this->merge_sort_internal(this->sorting_array, this->sorting_array_size);
}
template<class T> mSort_ReturnPkg<T> Merge_Sorter<T>::merge_sort_internal(T* input_array[], int arr_size)
{
	if(arr_size <= 1)
	{
		mSort_ReturnPkg<T> output;
		output.arr_ptr = input_array;
		output.arr_size = arr_size;
		return output;
	}


	T** left_half;
	T** right_half;	
	int left_size;
	int right_size;

	if(arr_size % 2 == 0)
	{
		left_size = arr_size / 2;
		right_size = left_size;
	
		left_half = new T*[left_size];
		right_half = new T*[right_size]; 
	}	
	else
	{
		left_size = arr_size / 2;
		right_size = left_size + 1;
		
		left_half = new T*[left_size];
		right_half = new T*[right_size];
	}

	for(unsigned int i = 0; i < left_size; i++)
	{
		left_half[i] = input_array[i];
	}

	int right_index = 0;
	for(unsigned int z = left_size; z < arr_size; z++)
	{
		right_half[right_index] = input_array[z];
		right_index++;
	}

	mSort_ReturnPkg<T> left_side;
	mSort_ReturnPkg<T> right_side;
			
	left_side = merge_sort_internal(left_half, left_size);
	right_side = merge_sort_internal(right_half, right_size);	

	int left_ind = 0;
	int right_ind = 0;
	int output_ind = 0;
	while(left_side.arr_size != 0 && right_side.arr_size != 0)
	{
		if(left_side.arr_ptr[left_ind]->compare(right_side.arr_ptr[right_ind]) == 1)
		{
			input_array[output_ind] = right_side.arr_ptr[right_ind];
			output_ind++;
			right_ind++;
			right_side.arr_size--;
		}
		else
		{
			input_array[output_ind] = left_side.arr_ptr[left_ind];
			output_ind++;
			left_ind++;
			left_side.arr_size--;
		}		
	}		

	if(right_side.arr_size == 0)
	{
		for(int i = output_ind; i < arr_size; i++)
		{
			input_array[i] = left_side.arr_ptr[left_ind];
			left_ind++;
		}
	}
	else if (left_side.arr_size == 0)
	{
		for(int i = output_ind; i < arr_size; i++)
		{
			input_array[i] = right_side.arr_ptr[right_ind];
			right_ind++;
		}
	}

	mSort_ReturnPkg<T> rtrn_pkg;
	rtrn_pkg.arr_ptr = input_array;
	rtrn_pkg.arr_size = arr_size;
	return rtrn_pkg;
}







	

// SORT ALG TIMER

struct alg_time_info_packet
{
	string name;
	int input_data_size;
	time_t start;
	time_t end;	
};

template<class T> class Alg_Timer
{
public:
	Bubble_Sorter<T>* alg1 = NULL;
	Insertion_Sorter<T>* alg2 = NULL;
	Quick_Sorter<T>* alg3 = NULL;
	Merge_Sorter<T>* alg4 = NULL;
	Sorter<T>* alg5 = NULL;
	
	vector<alg_time_info_packet*> alg1_performance_info;
	vector<alg_time_info_packet*> alg2_performance_info;
	vector<alg_time_info_packet*> alg3_performance_info;
	vector<alg_time_info_packet*> alg4_performance_info;
	vector<alg_time_info_packet*> alg5_performance_info;

	Alg_Timer(Bubble_Sorter<T>* alg1_input, Insertion_Sorter<T>* alg2_input, Quick_Sorter<T>* alg3_input, Merge_Sorter<T>* alg4_input, Sorter<T>* alg5_input)
	{
		alg1 = alg1_input;
		alg2 = alg2_input;
		alg3 = alg3_input;
		alg4 = alg4_input;
		alg5 = alg5_input;
	}

	void alg1_perform_test()
	{
		alg_time_info_packet* time_packet = new alg_time_info_packet;
		time_packet->input_data_size = alg1->get_arr_size();

		time(&time_packet->start);
		this->alg1->sort();		
		time(&time_packet->end);

		this->alg1_performance_info.push_back(time_packet);
	}	
};



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


	Bubble_Sorter<test_compare_object> *test1 = new Bubble_Sorter<test_compare_object>(test_arr, size);
	Insertion_Sorter<test_compare_object> *test2 = new Insertion_Sorter<test_compare_object>(test_arr, size);
	Quick_Sorter<test_compare_object> *test3 = new Quick_Sorter<test_compare_object>(test_arr, size);
	Merge_Sorter<test_compare_object> *test4 = new Merge_Sorter<test_compare_object>(test_arr, size);

	test1->sort();
	test2->sort();
	test3->sort();
	test4->sort();
	
	// alg timer test stuff
	Alg_Timer<test_compare_object> *test5 = new Alg_Timer<test_compare_object>(test1,NULL,NULL,NULL,NULL);
	test5->alg1_perform_test();
	cout << test5->alg1_performance_info[0]->start << endl;
	cout << test5->alg1_performance_info[0]->end << endl;

}
