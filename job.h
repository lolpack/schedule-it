#ifndef JOB_H
#define JOB_H

#include <iostream>
using namespace std;

class job
{
 public:
  job();
  job(int id, int burst);

  void setID(int id);
  void setBurst(int burst);
  int getID();
  int getBurst();

 private:
  int jobID;
  int jobBurst;
};

#endif
