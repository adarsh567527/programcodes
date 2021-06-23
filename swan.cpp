/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

bool isValid(int age)
{
    return (age > 0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v;

    int num,inp;
    cin>>num;

    if(num< 0)
    {
        cout<<"\nError";
        exit(1);
    }

    while(num--)
    {
        cin>>inp;
        v.push_back(inp);
    }

    int no_of_eggs = 0;
    for(int i : v)
    {
        if( !isValid(i) )
        {
            cout<<"\nError";
            exit(1);
        }

        if(i >= 52)
        {
            no_of_eggs = no_of_eggs + 16;
        }
        else
        {
            int rem_weeks = 4 - (52-i);
            if(rem_weeks >= 0)
                no_of_eggs = no_of_eggs + (rem_weeks * 4);
        }        
    }

    cout<<no_of_eggs;

    return 0;
}