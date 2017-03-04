#include "job.h"

Job::Job()
{
  jobID = 0;
  jobBurst = 0;
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

int Job::getID()
{
  return jobID;
}

int Job::getBurst()
{
  return jobBurst;
}
