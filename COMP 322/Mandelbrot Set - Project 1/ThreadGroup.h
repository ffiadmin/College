/**
 * Author      : Dorian P. Yeager & Oliver Spryn
 * Course      : COMP 322, Advanced Programming 
 * Date        : 17 August 2013
 * Description : This file declares the class which will manage the 
 *               application threads for this assignment.
*/

#include <iostream>
#include <process.h>
#include <time.h>
#include <vector>
#include <Windows.h>

class ThreadGroup {
private : 
	int exeTime;
	std::vector<HANDLE> threadBoss;

public : 
	typedef unsigned (__stdcall *TFP) (void *);
	
	ThreadGroup();
	~ThreadGroup();

	void add(TFP, void *);
	void clear();
	bool execAndWait();
	int getElapsedTime() const;
	int size() const;
};