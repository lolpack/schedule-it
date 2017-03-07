#include "job.h"

// Job class
Job::Job()
{
  jobID = 0;
  jobBurst = 0;
  turnAroundTime = 0;
  startTime = 0;
  endTime = 0;
}

// Overloaded constructor
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

void Job::setStartTime(int start)
{
  startTime = start;
}

void Job::setEndTime(int end)
{
  endTime = end;
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
  return getTurnAround() - getBurst();
}

int Job::getStartTime()
{
  return startTime;
}

int Job::getEndTime()
{
  return endTime;
}
