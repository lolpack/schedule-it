#ifndef JOB_H
#define JOB_H

#include <iostream>
using namespace std;

class Job
{
 public:
  Job();
  Job(int id, int burst);
  void setID(int id);
  void setBurst(int burst);
  void setTurnAround(int turnAround);
  int getID();
  int getBurst();
  int getTurnAround();
  int getWait();

 private:
  int jobID;
  int jobBurst;
  int turnAroundTime;
};
