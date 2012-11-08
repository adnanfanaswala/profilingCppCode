/*
#-------------------------------------------------------------------------------
# Author: Adnan Fanaswala
# Created: 15th August 2012
# Simple profiling C++ code example using a timer (QueryPerformanceFrequency)
#-------------------------------------------------------------------------------
*/

#include <windows.h>
#include <iostream>
using namespace std;

//=============================================================================
// Timer Variables
//=============================================================================
double PCFreq = 0.0;
__int64 CounterStart = 0;

//=============================================================================
// Function Definitions
//=============================================================================
//Start Counter
void StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
        cout << "QueryPerformanceFrequency failed!\n";

	//This gives us a value in milli seconds
    //PCFreq = double(li.QuadPart)/1000.0;

	//This gives us a value in seconds
    PCFreq = double(li.QuadPart);

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

//Get Counter
double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}

//=============================================================================
// INT MAIN
//=============================================================================
int main()
{

	StartCounter(); // This re-starts the timer
	//First For Loop
	for (int i=0; i<500; i++){
	}
	cout << "First FOR loop took these many " << GetCounter() << " seconds." << endl;
	

	StartCounter(); // This re-starts the timer
	//Second For Loop
	for (int j=0; j<5000; j++){
	}
	cout << "Second FOR loop took these many " << GetCounter() << " seconds." << endl;
	cout << endl;

	
    system("PAUSE");
    return(0);
}