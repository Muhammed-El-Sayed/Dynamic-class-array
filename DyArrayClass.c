#include <iostream>
#include<math.h>
#include<string>
using namespace std;


class DynamicArray {

	int size;
	float *pointer;

public:

	DynamicArray()
	{
		size = 0;

	}



	void setSize(int s)
	{
		if (size == 0) {
			size = s;
			pointer = new float[s];
		}

		if (size < s)
		{
			float *TempPointer1;
			TempPointer1 = new float[s];

			for (int i = 0; i < size; i++)
			{
				TempPointer1[i] = pointer[i];

			}
			delete[]pointer;
			pointer = TempPointer1;
			size = s;
		}

		if (size > s)
		{
			float *TempPointer2;
			TempPointer2 = new float[s];

			for (int i = 0; i < s; i++)
			{
				TempPointer2[i] = pointer[i];
			}
			delete[]pointer;
			pointer = TempPointer2;
			size = s;
		}
	}

	int getsize()
	{
		return size;
	}



	void setelement(int i, float num)//index i 
	{
		pointer[i] = num;

	}

	float getelement(int i)//index i
	{
		return pointer[i];
	}

	void insert(int i, float num)
	{
		size++;
		float *TempPointer;
		TempPointer = new float[size + 1];
		int k = 0, flag=1;
		for (int j = 0; j < size; j++)
		{
			if (j != i)
			{
				TempPointer[k] = pointer[j];
				k++;
			}
			else if ( j== i && flag ==1)
			{
				TempPointer[k] = num;
				k++;
				j--;
				flag = 0;

			}

		}
		delete[]pointer;
		pointer = TempPointer;

	}




	void addelement(float num)//add element by increasing size 1 and put this num to element of index size -1
	{
		size++;
		pointer[size - 1] = num;
	}


	void removeelement(int i) //removing element of index i , size decreses 1
	{
		if (i >= 0 && i <= size - 1)
		{
			float *TempPointer;
			TempPointer = new float[size - 1];
			int k = 0;
			for (int j = 0; j < size; j++)
			{
				if (j != i)
				{
					TempPointer[k] = pointer[j];
					k++;
				}
			}
			delete[]pointer;
			pointer = TempPointer;

			//decreasing member size 1
			size--;
		}
	}



	void print()//print your array
	{
		for (int i = 0; i < size; i++)
		{
			if (i == 0)
				cout << "[";
			cout << pointer[i];
			if (i != size - 1)
				cout << ",";
			if (i == size - 1)
				cout << "]";
		}
	}

	void removeDuplicates()//it removes the repeated elements and leave one model only
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (pointer[j] == pointer[i])
				{
					removeelement(j);
				}
			}
		}
	}

	int find(float num)//returns index of num (first num in array if repeated)
	{
		for (int i = 0; i < size; i++)
		{
			if (pointer[i] == num)
				return i;
		}
	}

	float Sum()//returns sum of elements of array
	{
		float sum = 0;
		for (int i = 0; i < size; i++)
		{
			sum += pointer[i];
		}
		return sum;
	}

	float average()
	{
		return Sum() / size;
	}

	void removeAll()
	{
		size = 0;
		delete[]pointer;
		pointer = NULL;

	}

	void DescendingSort()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (pointer[j] > pointer[i])
				{
					float Tempswap;
					Tempswap = pointer[i];
					pointer[i] = pointer[j];
					pointer[j] = Tempswap;
				}
			}
		}
	}

	void AscendingSort()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (pointer[j] < pointer[i])
				{
					float Tempswap;
					Tempswap = pointer[i];
					pointer[i] = pointer[j];
					pointer[j] = Tempswap;
				}
			}
		}
	}


};

//Member Functions

/*
  setSize(int )---sets the size of array,when you change the size the elements of array dont removed to remove them you have remove fnc
  getsize()--- gets the size of array
  setelement(int ,float)---sets the element of array of index int
  getelement(int)---gets element of index identified
  addelement(float)---adds 1 to size of array and adds element to the end of array
  removeelement(int)---removes element and sorting again in same order
  print()---prints array
  removeDuplicates()---remove the repeated except the Main Model
  find(float)---returns index of num float
  Sum()---returns sum of array elements
  average()---returns average
  removeAll()---removes all elements
  DescendingSort()--sorting from Largest to smallest
  AscendingSort()---sorting from smallest to Largest
*/

//Hints about Setting elements 

// if you sets size 5 after size 3 you have to set elements first not add ; add is to add over 5 elements ,set elements to set the 5 ones or 2 
//elements as 3 were already filled
//if you small size and print then it will give elements of this size
//if you then enlarge size you have to set elements of this enlargement but the last saved is always saved





int main()
{



	system("pause");
	return 0;
}
