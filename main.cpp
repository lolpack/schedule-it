#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include "job.h"

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
	  }
	else
	  {
		cerr << "Error opening file" << endl;
	  }
  infile.close();

  int size = ids.size();

  insertProcesses(processes, ids, bursts, size);

  //Round Robin
  roundRobin(processes, size);

  // //copy test
  // Job arr[size];
  // for(int v = 0; v < size; v++)
  // 	{
  // 	  arr[v] = processes[v];
  // 	}
  // cout << "TEST " << arr[19].getID() << endl;

  
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
  Job RRProcesses[size];
  queue<Job> jobQ;
  int timeQuantum = 1;
  Job* ptr;
  int n = 0;
  int m = 1;
  int remainingBurst;

  cout << "Enter a Time Quantum: ";
  cin >> timeQuantum;

  //Copy original vector so it doesn't get modified
  for(int i = 0; i < size; i++)
	{
	  // Job newJob(original[i].getID(), original[i].getBurst());
	  // RRProcesses.push_back(newJob);
	  RRProcesses[i] = original[i];
	}
  //Queue up
  for(int i = 0; i < size; i++)
	{
	  jobQ.push(RRProcesses[i]);
	} 
  while(!jobQ.empty())
	{
	  m = 1; //reset
	  ptr = &jobQ.front();
	  cout << "P" << ptr->getID() << " started at " << n << " seconds." << endl;

	  while(m <= timeQuantum && ptr->getBurst() != 0)
		{
		  remainingBurst = ptr->getBurst();
		  cout << "P" << ptr->getID() << " Processing... " << n << "seconds." << endl;
		  ptr->setBurst(remainingBurst - 1);
		  m++;
		  n++;
		}

	  if(ptr->getBurst() > 0)
	  	{
	  	  jobQ.pop();
	  	  jobQ.push(*ptr);
	  	  cout <<"P" << jobQ.back().getID() << " put to back of queue/Time remaining: " << jobQ.back().getBurst() << "s" << endl;
	  	}
	  else
	  	{
	  	  cout <<"P" << ptr->getID() << " ended on time " << n << endl;
	  	  jobQ.pop();
	  	}
	  
	  
	}
  

  //cout << ptr->getID() << endl;;
  
}
