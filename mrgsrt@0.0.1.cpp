#include <iostream>
#include <sstream>
using namespace std;

bool input(int * &elements, int num)
{
	string str;
	int excess_el;

	getline(cin, str);

	int *tmp_elements = new int[num];

	for (string str; getline(cin, str); ) {
		istringstream stream(str);
		for (int j = 0; j < num; ++j) {
			if (!(stream >> tmp_elements[j])) {
				return false;
			}
		}
		if (stream >> excess_el) return false;
		break;
	}
	elements = tmp_elements;
	return true;
}

void merge(int *elements, int first, int last)
{
	int middle, start, final;
	int *tmp = new int[last+1];
	middle = (first + last) / 2;
	start = first;
	final = middle + 1;

	for (int j = first; j <= last; j++) {
		if ((start <= middle) && ((final > last) || (elements[start] < elements[final]))) 
		{
			tmp[j] = elements[start];
			start++;
		}
		else 
		{
			tmp[j] = elements[final];
			final++;
		}
	}

	for (int j = first; j <= last; j++) elements[j] = tmp[j];
	delete[] tmp;
}

void merge_sort(int *elements, int first, int last)
{
	if (first<last) 
	{
		merge_sort(elements, first, (first + last) / 2);
		merge_sort(elements, (first + last) / 2 + 1, last);
		merge(elements, first, last);
	}
}

int main()
{
	int *elements;
	int num;

	if (!(cin >> num) || (num <= 0))
	{
		cout << "An error has occured while reading input data.\n";
		return 0;
	}

	if (!(input(elements, num)))
	{
		cout << "An error has occured while reading input data.\n";
		return 0;
	}

	merge_sort(elements, 0, num-1);

	for (int i = 0; i < num; i++) cout << elements[i] << ' ';

	delete[] elements;
	return 0;
}
