#include "Solutions.h"



Solutions::Solutions()
{
	cout<<"Solutions class constructor \n";
}

bool Solutions::odd_even(int number)  
{
	if(number%2==0)
	{
		return true;
	}
	return false;
}

void Solutions::array_sort(int * arr , int sizee)  
{
	bool vari = true;
	int count =0;
	while(vari)
	{
		for(int i=0;i<sizee;i++)
		{
			if(arr[i] >  arr[i+1])
			{
				int tmep   =  arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = tmep; 
				vari = true;
				count=0;
				break;
			}
			else
			{
				count++;
			}
		}
		if(count==sizee)
		{
			vari =  false;
		}
	}
	cout<<"After sort \n";
	for(int i=0;i<sizee;i++)
	{
		cout<<arr[i ] << "   " ;  
	}
}


string Solutions::remove_vowel(char * array) 
{
	string result ="";
	int sizee = strlen(array);
	for(int i=0;i<sizee;i++)
	{
		if(tolower(array[i])=='a' ||tolower(array[i])=='e' ||tolower(array[i])=='i' ||tolower(array[i])=='o' ||tolower(array[i])=='u')
		{

		}
		else
		{
			result=result+array[i];
		}
	}
	return result;
}

Solutions::~Solutions()
{
	cout<<"Solutions class destructor \n";
}