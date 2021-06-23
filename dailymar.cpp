/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

bool isValidYear(int year)
{
	if(year < 0)
		return false;
		
    int c=0;
	int num = year;
	while(num != 0)
	{
		int digit = num % 10;
		c = c + 1;
		num = num / 10;
	}
	
	if(c!= 4)
		return false;
	else
		return true;
}

bool isValidMonth(int month)
{
	return ( (month >= 1) && (month <= 12) );
}

bool isLeapYear(int year)
{
	return (  ( (year % 4 == 0) && (year % 100 != 0) ) ||
              (year % 400 == 0)   );
}

int daysOfMonth(int month, int year)
{
	int days;
	
	if( (month == 1) || (month == 3) || (month == 5) || 
	    (month == 7) || (month == 8) || (month == 10) || (month == 12) )
	{
	    days = 31;  	
	}
	
	if( (month == 4) || (month == 6) || (month == 9) || (month == 11) )
	{
	    days = 30;  	
	}
	
	if(month == 2)
	{
		if(isLeapYear(year))
			days = 29;
		else
			days = 28;
	}
	    
	 return days; 
	   
}


int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<float> v;
    int range = 7;
    float inp;
    while(range--)
    {
    	cin>>inp;
    	v.push_back(inp);
    }
    float x=v[0], y=v[1], z=v[2], t=v[3], w=v[4];
    float daily_expenses = x + y + z + t + w;
    
    int month = static_cast<int>(v[5]);
    int year = static_cast<int>(v[6]);
    
    cout<<"\nValid Year = "<<isValidYear(year);
    cout<<"\nValid Month = "<<isValidMonth(month);
    
    
    if( !isValidMonth(month) || !isValidYear(year) )
    {
    	cout<<"\nError";
    	exit(1);
    }
    
    
    if( (x==0) || (y==0) || (z==0) || (t==0) || (w==0) )
    {
        cout<<"\nError"<<endl;
        exit(1);
    }
    
    
    if( (y < x) || (y < z) || (y < t) || (y < w) )
    {
    	cout<<"\nError";
    	exit(1);
    }

    int no_of_days =  daysOfMonth(month, year);
    float monthly_expenses = daily_expenses * no_of_days;

    printf("\n%f  %f",daily_expenses,monthly_expenses);

    return 0;        
}
