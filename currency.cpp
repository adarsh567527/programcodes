/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

****************************************************************************/ // 

#include <bits/stdc++.h>
using namespace std;


void countCurrency(int amount)
{
	int notes[10] = { 2000, 500, 200, 100,
					50, 20, 10, 5, 2, 1 };
	int noteCounter[10] = { 0 };
	
	
	for (int i = 0; i < 10; i++) {
		if (amount >= notes[i]) {
			noteCounter[i] = amount / notes[i];
			amount = amount - noteCounter[i] * notes[i];
		}
	}
	
	
	cout << "Currency Count ->" << endl;
	for (int i = 0; i < 10; i++) {
		if (noteCounter[i] != 0) {
			cout << notes[i] << " : "
				<< noteCounter[i] << endl;
		}
	}
}


int main()
{
	int amount;
	std::cin >> amount;
	if(amount<0||amount>25000)
	{
	    cout<< "error"<<endl;
	}else
	{
	countCurrency(amount);
	return 0;
}
}

