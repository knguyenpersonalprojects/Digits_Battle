#include <iostream>
#include<vector>
#include <cmath>
using namespace std;
//written by Kevin Nguyen
//finished on 6/17/2021
//Starting from the left side of an integer, adjacent digits pair up in "battle" and the larger digit wins.
//If two digits are the same, they both lose.A lone digit automatically wins.


void battleOutcome(vector<int> &a, int size)
{
	//have a loop that check the index and index +1 and compare them.
	// increment by 2 once the comparison is done
	for (int i = 0; i < size; i+=2)
	{
		if (i + 1 < size)
		{
			cout << "[" << a[i] << a[i + 1] << "]" << endl;
			if (a[i] > a[i + 1])
			{
				cout << a[i] << " wins" << endl;
			}
			else if ((a[i] < a[i + 1]))
			{
				cout << a[i + 1] << " wins" << endl;

			}
			else
			{
				cout << a[i] << " and " << a[i + 1] << " tie " << endl;
			}
		}
		else
			cout << a[i] << " automatically wins" << endl;
	}
}
void addtoVector(int numInput, vector<int>& input, int size)
{
	int remainder;
	int exp =size-1;
	while (numInput != 0)
	{
		//subtract num with the highest base 10 then assign that to variable
		//example 321(userinput) / 10^2 = remainder

		remainder = numInput / pow(10, exp);
		numInput = numInput - (remainder * pow(10, exp));
		//push it to stack
		input.push_back(floor(remainder));
		
		exp--;
	}
}

int main()
{
	vector<int> a;
	int numInput, numDigits,size;
	
	cout << "Please enter your number ";
	cin >> numInput;
	//function that finds size of digits in user input
	size = trunc(log10(numInput)) + 1;
	addtoVector(numInput,a,size);
	battleOutcome(a, size);
}