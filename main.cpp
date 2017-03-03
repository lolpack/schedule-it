#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include "job.h"

using namespace std;

int main()
{
  string text;
  ifstream infile("jobs.txt");
  vector<int> ids;
  vector<int> bursts;
  vector<string> records;
  char numbers[20];
  char buffer[10];
  vector<job> processes;
  int i = 0;

  if(infile.is_open()) {
	while(infile.good())
	  {
		infile.getline(numbers, 256);
		cout << "Scan #" << i <<": " << endl;
		cout << numbers << endl;
		i++;
		while(getline(numbers, buffer, ',')
		  {
			ids.pushback(atoi(buffer));
		  }
	  }
	infile.close();
  }
  
  else
	{
	  cerr << "Error opening file" << endl;
	}

  return 0;
}
