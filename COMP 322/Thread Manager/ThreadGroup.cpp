/**
 * Author      : Oliver Spryn
 * Course      : COMP 322, Advanced Programming 
 * Date        : 17 August 2013
 * Description : This file defines the complete functionality for the 
 *               the class which will manage the application threads for 
 *               this assignment.
*/

#include "ThreadGroup.h"

ThreadGroup::ThreadGroup() {
	std::vector<HANDLE> hBoss;
	std::vector<unsigned int> threadBoss;
}

//Free system resources which were used to manage the threads
ThreadGroup::~ThreadGroup() {
	this->clear();
}

//Add a function, and its list of parameters, while will be run in an individual thread
void ThreadGroup::add(TFP function, void *params) {
	HANDLE h;
	unsigned int threadID;

	h = (HANDLE)_beginthreadex(static_cast<void *>(0), 0, function, params, CREATE_SUSPENDED, &threadID);
	this->threadBoss.push_back(h);
}

//Free system resources which were used to manage the threads
void ThreadGroup::clear() {
	for (int i = 0; i < this->threadBoss.size(); ++i) {
		CloseHandle(this->threadBoss[i]);
	}

	this->threadBoss.clear();
	this->exeTime = 0;
}

//Start each of the threads and wait until they have completed
bool ThreadGroup::execAndWait() {
	if (this->threadBoss.size() == 0)
		return false;

//Starting and monitoring threads requires a C-Style array of HANDLEs
	HANDLE *tempHandles = new HANDLE[this->threadBoss.size()];

	for (int i = 0; i < this->threadBoss.size(); ++i) {
		tempHandles[i] = this->threadBoss[i];
		ResumeThread(tempHandles[i]);
	}

//Wait for all threads to terminate
	const clock_t START_TIME = clock();
	WaitForMultipleObjects(this->threadBoss.size(), tempHandles, true, INFINITE);
	this->exeTime = static_cast<int>(clock() - START_TIME);

	delete [] tempHandles;
	return true;
}

//Obtain the amount of time which was required to run a series of threaded processes to completion
int ThreadGroup::getElapsedTime() const {
	return this->exeTime;
}

//Obtain the number of threads this class is managing
int ThreadGroup::size() const {
	return this->threadBoss.size();
}