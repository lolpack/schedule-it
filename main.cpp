#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "job.h"

using namespace std;

void insertProcesses(vector<Job>& processes, vector<int>& ids, vector<int>& bursts, int size);

int main()
{
  string text;
  ifstream infile("jobs.txt");
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

  // for(int j = 0; j < size; j++)
  // 	{
  // 	  cout << processes[j].getID() << "||" << processes[j].getBurst() << endl;
  // 	}
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
