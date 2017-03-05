#include "job.h"

Job::Job()
{
  jobID = 0;
  jobBurst = 0;
  turnAroundTime = 0;
}

Job::Job(int id, int burst)
{
  jobID = id;
  jobBurst = burst;
}

void Job::setID(int id)
{
  jobID = id;
}

void Job::setBurst(int burst)
{
  jobBurst = burst;
}

void Job::setTurnAround(int turnAround)
{
  turnAroundTime = turnAround;
}

int Job::getID()
{
  return jobID;
}

int Job::getBurst()
{
  return jobBurst;
}

int Job::getTurnAround()
{
  return turnAroundTime;
}

int Job::getWait()
{
  return turnAroundTime - jobID; //
}
