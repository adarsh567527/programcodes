/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Date
{
    public:
        int dd,mm,yyyy;
        Date(int dd,int mm,int yyyy)
        {
            this->dd = dd;
            this->mm = mm;
            this->yyyy = yyyy;
        }
};


const int month_days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };



int countLeapYears(Date d)
{
    int y = d.yyyy;
 
      if (d.mm <= 2)
        y--;
      return (y / 4) - (y / 100) + (y / 400);

}


int daysBetweenTwoDates(Date dt1, Date dt2)
{
    
    long int n1 = (dt1.yyyy * 365) + dt1.dd;
 
    
    for (int i = 0; i < dt1.mm - 1; i++)
        n1 += month_days[i];
 
    n1 += countLeapYears(dt1);

    long int n2 = (dt2.yyyy * 365) + dt2.dd;
   
    for (int i = 0; i < dt2.mm - 1; i++)
        n2 += month_days[i];
 
    n2 += countLeapYears(dt2);    
 
    return (n2 - n1);
}

bool isPrime(int n)
{
    int i;

    if(n == 1)
        return false;

    for(i=2;i*i<=n;i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int range=2;
    int mm1, dd1, yyyy1;
    int mm2, dd2, yyyy2;

    cin>>dd1>>mm1>>yyyy1;
    cin>>dd2>>mm2>>yyyy2;

    Date birth_date(dd1, mm1, yyyy1);
    Date curr_date(dd2, mm2, yyyy2);

    int num_of_days = daysBetweenTwoDates(birth_date, curr_date);
    int num_of_weeks = num_of_days / 7;
	
	cout<<"\nNumber of days between Current Date and Birth Date = "<<num_of_days;
    cout<<"\nNumber of weeks between Current Date and Birth Date = "<<num_of_weeks;


    int prime_factor_sum = 0, non_prime_factor_sum = 0;
    int a,b;
    vector<int> prime_factors;
    vector<int> non_prime_factors;
    
    for(int i=2;i*i<=num_of_weeks;i++)
    {

        if(num_of_weeks%i == 0)
        {
            if(num_of_weeks/i == i)
            {
                a = i;
                isPrime(a) ? prime_factors.push_back(a) : non_prime_factors.push_back(a);
            }
            else
            {
                a = i;
                b = num_of_weeks/i;

                isPrime(a) ? prime_factors.push_back(a) : non_prime_factors.push_back(a);
                isPrime(b) ? prime_factors.push_back(b) : non_prime_factors.push_back(b);

            }
        }
    }
	
    cout<<"\nPrime Factors of "<<num_of_weeks<<" = ";
    for(int s : prime_factors)
    {
        prime_factor_sum = prime_factor_sum + s;
        cout<<s<<",";
    }
    	
    

    cout<<"\nNon Prime Factors of "<<num_of_weeks<<" = ";
    for(int s : non_prime_factors)
    {
        non_prime_factor_sum = non_prime_factor_sum + s;
        cout<<s<<",";
    }
    	
    	
    cout<<"\nPrime Factor sum = "<<prime_factor_sum;
    cout<<"\nNon Prime Factor sum = "<<non_prime_factor_sum;

    if(prime_factor_sum > non_prime_factor_sum)
        cout<<"\nGrant"<<endl;
    else
        cout<<"\nNotGrant"<<endl;

    return 0;
}