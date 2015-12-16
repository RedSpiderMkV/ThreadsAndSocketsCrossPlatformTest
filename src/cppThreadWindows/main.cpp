/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 16 December 2015, 22:07
 */

/*#include <windows.h>
#include <iostream>

DWORD WINAPI myThread(LPVOID lpParameter)
{
	unsigned int& myCounter = *((unsigned int*)lpParameter);
	while(myCounter < 0xFFFFFFFF) ++myCounter;
	return 0;
}

int main(int argc, char* argv[])
{
	using namespace std;

	unsigned int myCounter = 0;
	DWORD myThreadID;
	HANDLE myHandle = CreateThread(0, 0, myThread, &myCounter, 0, &myThreadID);
	char myChar = ' ';
	while(myChar != 'q') {
		cout << myCounter << endl;
		cin >> myChar;
	}
	
	CloseHandle(myHandle);
	return 0;
}*/

#include<iostream>
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include "mingw.thread.h"
#else
#include<thread>
#endif

using namespace std;
 
void thread_function1()
{
    char quit = ' ';
    while(quit != 'q')
    {
        cout << "thread_function1" << endl;
        cin >> quit;
    }
    
    cout << "thread_function1 quitting" << endl;
}

void thread_function2()
{
    char quit = ' ';
    while(quit != 'q')
    {
        cout << "thread_function2" << endl;
        cin >> quit;
    }
    
    cout << "thread_function2 quitting" << endl;
}
 
int main()  
{
    
    thread threadObj(thread_function1);
    thread threadObj2(thread_function2);
    
    cout << "Display From MainThread" << endl;
    
    threadObj.join();
    threadObj2.join();
    
    cout << "Exit of Main function" << endl;
    
    return 0;
}
