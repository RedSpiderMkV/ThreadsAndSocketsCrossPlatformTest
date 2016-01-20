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

#include <chrono>

using namespace std;

void thread_function(int id)
{
    int count = 0;
    while(count < 10)
    {
        cout << this_thread::get_id() << "\t";
        cout << "thread_function callcount" << "\t" << count << "\t";
        cout << "threadId\t" << id << endl;
        
        count++;
        int timeout = rand() % 1000;
        this_thread::sleep_for(std::chrono::milliseconds(timeout));
    }
    
    cout << "thread_function quitting" << "\t" << id << endl;
}
 
int main()  
{
    //thread threadObj(thread_function, 1);
    //thread threadObj2(thread_function, 2);
    
    cout << "Display From MainThread" << endl;
    
    //threadObj.join();
    //threadObj2.join();
    void (*threadFuncPtr)(int) = thread_function;
    
    thread threadArr[5];
    
    for(int i = 0; i < 5; i++)
    {
        threadArr[i] = thread(threadFuncPtr, i);
        threadArr[i].detach();
    }
    
    //for(int i = 0; i < 5; i++)
    //{
        //threadArr[i].join();
    //}
    
    char quit = 'n';
    while(quit != 'y')
    {
        this_thread::sleep_for(std::chrono::milliseconds(1000));
        
        cout << "Quit?" << endl;
        cin >> quit;
    }
    
    cout << "Exit of Main function" << endl;
    
    return 0;
}
