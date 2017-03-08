#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>
#include "job.h"


using namespace std;

void insertProcesses(vector<Job>& processes, vector<int>& ids, vector<int>& bursts, int size);
void FCFS(vector<Job> Jobs, int size);
void roundRobin(vector<Job>& original, int size);
bool sortJobs(Job job1, Job job2); //needed to sort for SJF
void SJF(vector<Job> Jobs, int size);

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
			//Inserts before comma to ids vector and after to burst comma
			ids.push_back(stoi(text.substr(0,text.find(","))));
			bursts.push_back(stoi(text.substr(text.find(",") +1)));
		  }
	  }
	//total number of jobs
	int size = ids.size();

	//creates Job object vector to store information of both jobs and bursts
	insertProcesses(processes, ids, bursts, size);

	// First come First Server
	FCFS(processes, size);

	//Round Robin
	roundRobin(processes, size);

	//Shortest Job First
	SJF(processes, size);

	}
  //When a file can't be found
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

void FCFS(vector<Job> Jobs, int size) {
  Job *RRProcesses = new Job[size];
  queue<Job> jobQ;
  // copy jobs into a new array to not mutate existing array
  for(int i = 0; i < size; i++)
	{
	  RRProcesses[i] = Jobs[i];
	}
  //Queue up
  for(int i = 0; i < size; i++)
	{
	  jobQ.push(RRProcesses[i]);
	}
  Job* curJob;

  int totalTime = 0;
  int waitTime = 0;
  int totalWait;
  while(!jobQ.empty()) {
  	curJob = &jobQ.front(); //Always pull from front of queue with FCFS
  	totalTime += curJob->getBurst();
  	curJob->setTurnAround(totalTime);
  	totalWait += curJob->getWait(); // used for calculating average later
  	jobQ.pop();
  }

  cout << setprecision(3) << fixed << showpoint;
  double throughPut = 60/((double)totalTime/(double)size);
  double avgTurnAround = (double)totalTime/(double)size;
  double avgWait = (double)totalWait/(double)size;;
  cout << setw(30) << right << "FIRST COME FIRST SERVE" << endl;
  cout << "Total processing time: " << totalTime << " seconds." << endl;
  cout << "Average turn around time for Jobs: " << avgTurnAround << endl;
  cout << "Overall throughput: " <<  throughPut <<  " processes per minute" << endl;
  cout << "Average wait time: " << avgWait << endl;
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


  cout << setw(30) << right << "ROUND ROBIN" << endl;
  cout << "Enter a Time Quantum: ";
  cin >> timeQuantum;

  //Copy original vector so it doesn't get modified
  for(int i = 0; i < size; i++)
	{
	  RRProcesses[i] = original[i];
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

	  //Used to decrease burst until m=timeQuantum and increments n to track time passed
	  while(m <= timeQuantum && ptr->getBurst() > 0)
		{
		  remainingBurst = ptr->getBurst();
		  ptr->setBurst(remainingBurst - 1);
		  m++;
		  n++;
		}

	  //if there's still burst time left
	  if(ptr->getBurst() > 0)
	  	{
	  	  jobQ.pop();
	  	  jobQ.push(*ptr);
	  	}
	  //when process hits 0 burst time
	  else
	  	{
	  	  //cout <<"P" << ptr->getID() << " ended on time " << n << endl;
		  ptr->setEndTime(n);
		  int turnA = ptr->getEndTime();
		  ptr->setTurnAround(turnA);
		  totalTurnAround += ptr->getTurnAround();
	  	  jobQ.pop();
	  	}

	}

  //output
  cout << setprecision(3) << fixed << showpoint;
  double throughPut = 60/((double)n/(double)size);
  double avgTurnAround = (double)totalTurnAround/(double)size;
  double avgWait = ((double)totalTurnAround - (double)n)/(double)size;
  
  cout << "Total processing time: " << n << endl;
  cout << "Average turn around time for Jobs: " << avgTurnAround << endl;
  cout << "Overall throughput: "  << throughPut << endl;
  cout << "Average wait time: " << avgWait << endl;
}

bool sortJobs(Job job1, Job job2) {
  return (job1.getBurst() < job2.getBurst()); // Only swap if shorter, keeps sort stable.
}


void SJF(vector<Job> Jobs, int size) {
  Job *RRProcesses = new Job[size];
  queue<Job> jobQ;

  RRProcesses[0] = Jobs[0]; // First process will always run first in SJF rega \
  rdless of burst

	std::vector<Job> newJobsVector(Jobs);
  std::sort(newJobsVector.begin()+1, newJobsVector.end(), sortJobs); // Assume \
  all jobs come in at the same time

	for(int i = 1; i < size; i++)
	  {
		RRProcesses[i] = newJobsVector[i];
	  }
  //Queue up
  for(int i = 0; i < size; i++)
	{
	  jobQ.push(RRProcesses[i]);
	}

  Job* curJob;

  int totalTime = 0;
  int totalWait = 0;
  while(!jobQ.empty()) {
  	curJob = &jobQ.front(); // Now that the queue is sorted by length, we can do the shortest job first by pulling from the front of the queue.
  	totalTime += curJob->getBurst(); // Set time spent equal to the burst
  	curJob->setTurnAround(totalTime);
  	totalWait += curJob->getWait();
  	jobQ.pop();
  }

  cout << setprecision(3) << fixed << showpoint;
  double throughPut = 60/((double)totalTime/(double)size);
  double avgTurnAround =(double)totalTime/(double)size;
  double avgWait = (double)totalWait/(double)size;
  cout << setw(30) << right << "SHORTEST JOB FIRST" << endl;
  cout << "Total processing time: " << totalTime << " seconds." << endl;
  cout << "Average turn around time for Jobs: " << avgTurnAround << endl;
  cout << "Overall throughput: " <<  throughPut  <<  " processes per minute" <<  endl;
  cout << "Average wait time for Jobs: " << avgWait << endl;

