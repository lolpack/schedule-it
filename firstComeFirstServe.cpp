#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

void FCFS(vector<Job> Jobs, int size) {
    Job *RRProcesses = new Job[size];
    queue<Job> jobQ;
    for(int i = 0; i < size; i++)
    {
      // Job newJob(original[i].getID(), original[i].getBurst());
      // RRProcesses.push_back(newJob);
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
        totalWait += curJob->getWait();
        jobQ.pop();
    }

    cout << "Total processing time: " << totalTime << " seconds." << endl;
    cout << "Average turn around time for Jobs: " << totalTime / size << endl;
    cout << "Overall throughput: " << totalTime / size << endl;
    cout << "Average wait time: " << totalWait / size << endl;
}
