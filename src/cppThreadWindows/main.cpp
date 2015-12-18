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

#include <iostream>
#include <functional>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include "mingw.thread.h"
#else
#include<thread>
#endif

using namespace std;

void thread_function(int id, function<void(char)> callback)
{
    char quit = ' ';
    while(quit != 'q')
    {
        cout << "thread_function" << "\t" << id << endl;
        cin >> quit;
    }
    
    cout << "thread_function quitting:" << "\t" << id << endl;
    callback(quit);
}

void callbackFunc(char inputChar)
{
    if(inputChar == 'q')
    {
        cout << "Quit Input!" << endl << endl;
    }
}

int main()
{
    thread threadObj(thread_function, 1, callbackFunc);
    thread threadObj2(thread_function, 2, callbackFunc);
    
    cout << "Display From MainThread" << endl;
    
    threadObj.join();
    threadObj2.join();
    
    cout << "Exit of Main function" << endl;
    
    return 0;
}
