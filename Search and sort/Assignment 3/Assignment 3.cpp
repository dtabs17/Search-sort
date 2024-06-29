#include <iostream>
#include <string>
using namespace std;
struct ListType
{
	int length;
	string array[14];
};
ListType list;

int BinarySearch(ListType list, string& item, bool& found);
int main()
{
	string nameToSearch;
	int temp;
	string array[14];
	
	for (int i = 0; i < 14; ++i) {
		cout << "Enter name " << i + 1 << ": ";
		cin >> array[i];
	}

	for (int i = 0; i < 14; i++)
	{
		list.array[i] = array[i];
	}
	list.length = 14;
	string min = list.array[0];
	int p = 0,j;
	int n = 14;
	for (int i = 1; i < 14; i = i + 1)
	{
		if (list.array[i] < min) 
		{
			min = list.array[i];
			p = i;
		}
	}
	list.array[p] = list.array[0];
	list.array[0] = min;
	string x;

	for (int i = 2; i < 14; i = i + 1)
	{
		x = list.array[i];
		j = i;
		while (x < list.array[j - 1])
		{
			list.array[j] = list.array[j - 1];
			j = j - 1;
		}
		list.array[j] = x;
	}


	cout << "The ordered array is: " <<  endl;
	for (int i = 0; i < 14; i++)
	{
		cout << list.array[i] << " ";
	}
	cout << endl;


	cout << "What name would you like to search for: ";
	cin >> nameToSearch;

	bool s = false;
	temp = BinarySearch(list, nameToSearch, s);
	if (s == true)
	{
		cout << nameToSearch << " has been found" << " at index: " << temp;
	}
	else
	{
		cout << nameToSearch << " was not found";
	}
}

int BinarySearch(ListType list, string& item, bool& found)
{
	int midPoint;
	int first = 0;
	int last = list.length - 1;
	bool moreToSearch = first <= last;
	found = false;
	while (moreToSearch && !found)
	{
		midPoint = (first + last) / 2;
			if (item < list.array[midPoint])
			{
				last = midPoint - 1;
				moreToSearch = first <= last;
			}
			else if (item > list.array[midPoint])
			{
				first = midPoint + 1;
				moreToSearch = first <= last;
			}
			else
			{
				item = list.array[midPoint];
				found = true;
				return midPoint;
			}
	}
}
