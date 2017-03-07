#include <algorithm>

bool sortJobs(Job job1, Job job2) {
    return (job1.getBurst() < job2.getBurst());
}

void SJF(vector<Job> Jobs, int size) {
    Job *RRProcesses = new Job[size];
    queue<Job> jobQ;

    RRProcesses[0] = Jobs[0]; // First process will always run first in SJF regardless of burst

    std::vector<Job> newJobsVector(Jobs);
    std::sort(newJobsVector.begin()+1, newJobsVector.end(), sortJobs); // Assume all jobs come in at the same time

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
   int waitTime = 0;
   int totalWait;
   while(!jobQ.empty()) {
       curJob = &jobQ.front(); //Always pull from front of queue with FCFS
       totalTime += curJob->getBurst();
       curJob->setTurnAround(totalTime);
       totalWait += curJob->getWait();
       jobQ.pop();
   }
   cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
   cout << "Total processing time: " << totalTime << " seconds." << endl;
   cout << "Average turn around time for Jobs: " << totalTime / size << endl;
   cout << "Overall throughput: " << totalTime / size << endl;
   cout << "Average wait time: " << totalWait / size << endl;
}
