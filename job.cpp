#include "job.h"

job::job()
{
  jobID = 0; // Synonymous with arrival time
  jobBurst = 0;
  turnAroundTime = 0;
}

job::job(int id, int burst)
{
  jobID = id;
  jobBurst = burst;
}

void job::setID(int id)
{
  jobID = id;
}

void job::setBurst(int burst)
{
  jobBurst = burst;
}

void job::setTurnAround(int turnAround)
{
  turnAroundTime = turnAround;
}

int job::getID()
{
  return jobID;
}

int job::getBurst()
{
  return jobBurst;
}

int job::getTurnAround()
{
  return turnAroundTime;
}

int job::getWait()
{
  return turnAroundTime - jobID; //
}
