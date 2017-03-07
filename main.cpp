#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include <iomanip>
#include "job.h"


#include "firstComeFirstServe.cpp"
#include "shortestJobFirst.cpp"

using namespace std;

void insertProcesses(vector<Job>& processes, vector<int>& ids, vector<int>& bursts, int size);
void roundRobin(vector<Job>& original, int size);

int main()
{
  string filename;

  cout << "Please Enter the name of the file you wish to read: ";
  cin >> filename;


  string text;
  ifstream infile(filename);
  vector<int> ids;
  vector<int> bursts;
  vector<Job> processes;

  if(infile.is_open())
	{
	while(infile.good())
	  {
		while(getline(infile, text))
		  {
		  ids.push_back(stoi(text.substr(0,text.find(","))));
		  bursts.push_back(stoi(text.substr(text.find(",") +1)));
		  }
	  }
	int size = ids.size();

  insertProcesses(processes, ids, bursts, size);

  // First come First Server


  //FCFS(processes, size);

  //Round Robin
  roundRobin(processes, size);


  FCFS(processes, size);

  //Shortest Job First
  SJF(processes, size);

  // //copy test
  // Job arr[size];
  // for(int v = 0; v < size; v++)
  // 	{
  // 	  arr[v] = processes[v];
  // 	}
  // cout << "TEST " << arr[19].getID() << endl;

	}
	else
	  {
		cerr << "Error Opening File" << endl;
	  }
  infile.close();
  return 0;
}

void insertProcesses(vector<Job>& processes, vector<int>& ids, vector<int>& bursts, int size)
{
  for(int i = 0; i < size; i++)
	{
	  Job newJob(ids[i],bursts[i]);
	  processes.push_back(newJob);
	}
}

void roundRobin(vector<Job>& original, int size)
{
  Job *RRProcesses = new Job[size];
  queue<Job> jobQ;
  int timeQuantum = 1; //By default it's 1 from the assignment, but it can  be changed
  Job* ptr;  //Queue Pointer
  int n = 0; //Process Counter (Can also be considere total burst time).
  int m = 0; //Time Quantum Counter
  int remainingBurst; //round robin subtracts bursts
  int started[size + 1];//+1 because the job IDs start at 1 (if it starts at 0, we just have an extra box
  int totalTurnAround = 0; //Should count all the turnArounds for average and other uses.
  

  cout << "Enter a Time Quantum: ";
  cin >> timeQuantum;

  //Copy original vector so it doesn't get modified
  for(int i = 0; i < size; i++)
	{
	  RRProcesses[i] = original[i];
	}

  //hash table for flagging
  for(int i = 0; i < size+1; i++) //fill hash table with 0s
	{
	  started[i] = 0;
	}
  //Queue up
  for(int i = 0; i < size; i++)
	{
	  jobQ.push(RRProcesses[i]);
	}
  while(!jobQ.empty())
	{
	  m = 0; //reset
	  ptr = &jobQ.front();
	  cout << "P" << ptr->getID() << " started at " << n << " seconds." << endl;

	  if(started[ptr->getID()] == 0)//hash table flagger
		{
		  ptr->setStartTime(n);
		  started[ptr->getID()]++; // FLAGGED can no longer change start time.
		}

	  while(m <= timeQuantum && ptr->getBurst() > 0)
		{
		  remainingBurst = ptr->getBurst();
		  //cout << "P" << ptr->getID() << " Processing... " << n << "seconds." << endl;
		  ptr->setBurst(remainingBurst - 1);
		  m++;
		  n++;
		}

	  //if there's still burst time left
	  if(ptr->getBurst() > 0)
	  	{
	  	  jobQ.pop();
	  	  jobQ.push(*ptr);
	  	  cout <<"P" << jobQ.back().getID() << " put to back of queue/Time remaining: "
			   << jobQ.back().getBurst() << "s" << endl;
	  	}
	  //when process hits 0 burst time
	  else
	  	{
	  	  cout <<"P" << ptr->getID() << " ended on time " << n << endl;
		  ptr->setEndTime(n);
		  int turnA = ptr->getEndTime() - ptr->getStartTime();
		  ptr->setTurnAround(turnA);
		  totalTurnAround += ptr->getTurnAround();
	  	  jobQ.pop();
	  	}

	}

  cout << setw(30) << right << "ROUND ROBIN" << endl;
  cout << "Average TurnAround Time: " << totalTurnAround/size << endl;
  cout << "Average Wait Time: " << (totalTurnAround - n)/size << endl;
  

}
