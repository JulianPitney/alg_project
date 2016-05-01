#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>
#include <math.h>
using namespace std;


// THINGS TO DO:
//
// - Fix merge_sort memory leaks
// - Fix quick_sort error probly (kind of explained in quick_sort code)
// - Fix quick_sort memory leaks
// - Make generic print function in Sorter class
// - Make Print_Performance_Info function in Alg_Timer class prettier
// - Fix all my terrible function and variable names and format the code better
// - Fix memory leaks in main() during testing of algorithms (generates new array after each test and doesn't delete the old ones)





// Sorter class (not meant to be instantiated directly, just a base for individual sorter types)
template <class T> class Sorter
{
public:

	Sorter(T* ptr_arr[], int sorting_array_size);
	void update_sorting_array(T* ptr_arr[], int sorting_array_size);
	void print_sorting_array();
	int find_arr_midpoint(int start_index, int end_index);
	int get_arr_size();
	T** get_sorting_array();
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

template<class T> T** Sorter<T>::get_sorting_array()
{
	return this->sorting_array;
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

template<typename T> struct qSort_ReturnPkg
{
	T** arr;
	int arr_size;	
}

template<class T> class Quick_Sorter : public Sorter<T>
{
public:

	Quick_Sorter(T* ptr_arr[], int sorting_array_size);
	quick_sort(T* input_array[], int input_arr_size);

};

template<class T> Quick_Sorter<T>::Quick_Sorter(T* ptr_arr[], int sorting_array_size) : Sorter<T>::Sorter(ptr_arr, sorting_array_size)
{
	cout << "Quick_Sorter successfully created! \n";
}

template<class T> qSort_ReturnPkg Quick_Sorter<T>::quick_sort_internal(T* input_array[], int input_arr_size)
{
	if(input_arr_size < 2)
	{
		qSort_ReturnPkg<T> output;
		output.arr = input_array;
		output.arr_size = input_arr_size;
		return output;
	}


	int middle_index;

	
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

struct PIP // Performance Info Packet (PIP)
{
	string name;
	int input_data_size;
	time_t start;
	time_t end;	
};


// - Allows individual tests to be performed on any of the 4 sorting objects that are passed in on initialisation
// - Each performance_test produces a performance_info_packet that is stored in a vector pertaining to the sorting object that underwent the test
// - Has print function which displays contents of the performance info vector of each of the 4 sorting objects
// 
// NOTE: User is responsible for updating the sorting_array of the sorting objects after each test (as they become sorted after each test and therefore
// useless for further tests)
//
// NOTE: If we add a new sorting algorithm to this class we must; 1. Add a pointer to locate it's object and initilize that pointer in the Alg_Timer constructor
//								  2. Add a performance_test function for the new algorithm
//								  3. Add a new PIP vector to contain the data packets produced by the new performance_test function
//								  4. Add a loop in Print_Performance_Info to print the contents of the new PIP vector 
template<class T> class Alg_Timer
{
public:
	Bubble_Sorter<T>* BSort_ptr = NULL;
	Insertion_Sorter<T>* ISort_ptr = NULL;
	Quick_Sorter<T>* QSort_ptr = NULL;
	Merge_Sorter<T>* MSort_ptr = NULL;
	
	vector<PIP*> BSort_performance_info;
	vector<PIP*> ISort_performance_info;
	vector<PIP*> QSort_performance_info;
	vector<PIP*> MSort_performance_info;

	Alg_Timer(Bubble_Sorter<T>* BSort_input, Insertion_Sorter<T>* ISort_input, Quick_Sorter<T>* QSort_input, Merge_Sorter<T>* MSort_input)
	{
		BSort_ptr = BSort_input;
		ISort_ptr = ISort_input;
		QSort_ptr = QSort_input;
		MSort_ptr = MSort_input;
	}



	void Print_Performance_Info()
	{
		cout << "\n\n";

		cout << "Bubble Sort Performance Info" << endl << endl;	
	
		for(int i = 0; i < BSort_performance_info.size(); i++)
		{
			cout << "Input Size: " << BSort_performance_info[i]->input_data_size << endl;
			cout << "Elapsed Time: " << BSort_performance_info[i]->end - BSort_performance_info[i]->start << endl;
			cout << endl;
		}
	
		cout << "\n\n";

		cout << "Insertion Sort Performance Info" << endl << endl;	
	
		for(int i = 0; i < ISort_performance_info.size(); i++)
		{
			cout << "Input Size: " << ISort_performance_info[i]->input_data_size << endl;
			cout << "Elapsed Time: " << ISort_performance_info[i]->end - ISort_performance_info[i]->start << endl;
			cout << endl;
		}

		cout << "\n\n";

		cout << "Quick Sort Performance Info" << endl << endl;	
	
		for(int i = 0; i < QSort_performance_info.size(); i++)
		{
			cout << "Input Size: " << QSort_performance_info[i]->input_data_size << endl;
			cout << "Elapsed Time: " << QSort_performance_info[i]->end - QSort_performance_info[i]->start << endl;
			cout << endl;
		}

		cout << "\n\n";
	
		cout << "Merge Sort Performance Info" << endl << endl;	
	
		for(int i = 0; i < MSort_performance_info.size(); i++)
		{
			cout << "Input Size: " << MSort_performance_info[i]->input_data_size << endl;
			cout << "Elapsed Time: " << MSort_performance_info[i]->end - MSort_performance_info[i]->start << endl;
			cout << endl;
		}
		
		cout << "\n\n";
	}
	
	
	void BSort_performance_test()
	{
		PIP* test_data = new PIP;
		test_data->input_data_size = BSort_ptr->get_arr_size();

		time(&test_data->start);
		this->BSort_ptr->sort();		
		time(&test_data->end);

		this->BSort_performance_info.push_back(test_data);
	}

	void ISort_performance_test()
	{
		PIP* test_data = new PIP;
		test_data->input_data_size = ISort_ptr->get_arr_size();

		time(&test_data->start);
		this->ISort_ptr->sort();
		time(&test_data->end);

		this->ISort_performance_info.push_back(test_data);	
	}	

	void QSort_performance_test()
	{
		PIP* test_data = new PIP;
		test_data->input_data_size = QSort_ptr->get_arr_size();
	
		time(&test_data->start);
		this->QSort_ptr->sort();
		time(&test_data->end);
		
		this->QSort_performance_info.push_back(test_data);	
	}

	void MSort_performance_test()
	{
		PIP* test_data = new PIP;
		test_data->input_data_size = MSort_ptr->get_arr_size();
		
		time(&test_data->start);
		this->MSort_ptr->sort();
		time(&test_data->end);

		this->MSort_performance_info.push_back(test_data);
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

test_compare_object** test_arr_gen(int size)
{
	test_compare_object** test_arr = new test_compare_object*[size];
	int* int_arr = int_arr_gen(size);

	for(int i = 0; i < size; i++)
	{
		test_arr[i] = new test_compare_object(int_arr[i]);
	}

	return test_arr;
}





int main()
{

	const int size = 10;
	test_compare_object** test_arr1 = test_arr_gen(size);
	test_compare_object** test_arr2 = test_arr_gen(size);
	test_compare_object** test_arr3 = test_arr_gen(size);
	test_compare_object** test_arr4 = test_arr_gen(size);


	// Alg Objects + Sorting Functions
	Bubble_Sorter<test_compare_object> *test1 = new Bubble_Sorter<test_compare_object>(test_arr1, size);
	Insertion_Sorter<test_compare_object> *test2 = new Insertion_Sorter<test_compare_object>(test_arr2, size);
	Quick_Sorter<test_compare_object> *test3 = new Quick_Sorter<test_compare_object>(test_arr3, size);
	Merge_Sorter<test_compare_object> *test4 = new Merge_Sorter<test_compare_object>(test_arr4, size);


	// Alg Timer Code
	Alg_Timer<test_compare_object> *test5 = new Alg_Timer<test_compare_object>(test1,test2,test3,test4);


	// Performs tests on whatever sorting_objects contained in the Alg_Timer object are specified, feeding in a new array after each iteration
	// NOTE: Has memory leak, fix later
	


	
}
