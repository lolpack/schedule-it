#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

#include "job.cpp"

using namespace std;

void FCFS(vector<job> jobs) {
    int totalTime = 0;
    int waitTime = 0;
    int totalWait;
    for (int i = 0; i < jobs.size(); i ++) {
        job curJob = jobs.at(i);
        totalTime += curJob.getBurst();
        curJob.setTurnAround(totalTime);
        totalWait += curJob.getWait();
    }

    cout << "Average turn around time for jobs: " << totalTime / jobs.size() << endl;
    cout << "Overall throughput: " << totalTime / jobs.size() << endl;
    cout << "Average wait time: " << totalWait / jobs.size() << endl;
}



int main()
{
    job job1 = job(1,18);
    job job2 = job(2,5);
    job job3 = job(3,14);
    job job4 = job(4,1);
    job job5 = job(5,17);
    job job6 = job(6,2);
    job job7 = job(7,6);
    job job8 = job(8,15);
    job job9 = job(9,20);
    job job10 = job(10,6);
    job job11 = job(11,18);
    job job12 = job(12,2);
    job job13 = job(13,3);
    job job14 = job(14,2);
    job job15 = job(15,2);
    job job16 = job(16,7);
    job job17 = job(17,20);
    job job18 = job(18,4);
    job job19 = job(19,17);
    job job20 = job(20,1);

    vector<job> jobs;

    jobs.push_back(job1);
    jobs.push_back(job2);
    jobs.push_back(job3);
    jobs.push_back(job4);
    jobs.push_back(job5);
    jobs.push_back(job6);
    jobs.push_back(job7);
    jobs.push_back(job8);
    jobs.push_back(job9);
    jobs.push_back(job10);
    jobs.push_back(job11);
    jobs.push_back(job12);
    jobs.push_back(job13);
    jobs.push_back(job14);
    jobs.push_back(job15);
    jobs.push_back(job16);
    jobs.push_back(job17);
    jobs.push_back(job18);
    jobs.push_back(job19);
    jobs.push_back(job20);

    cout << jobs.at(0).getID();

    FCFS(jobs);


}