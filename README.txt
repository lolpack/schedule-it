# Homework 3 - Scheduling Algorithms - Darsh Lin, Aaron Pollack

## THIS PROGRAM REQUIRES C++ 11

To run on CS1:

```
g++ -std=c++11 main.cpp job.h job.cpp
```

To run

```
./a
```

You will be prompted to enter the filename containing the jobs file and the time quantum for Round Robin:

```
Please Enter the name of the file you wish to read: jobs.txt
Enter a Time Quantum: 20
```

The output will be the following for each sorting algorithm

- Total processing time
- Average turn around time for Jobs
- Overall throughput
- Average wait time


Wait time comparison:
  The wait time is shortest (55) on Shortest Job First compared to (92) for First Come First Serve and (87) for Round Robin. It make sense that this is algorithm has the average shortest wait time since it is optimizing for more jobs getting done in a smaller time frame by doing the jobs with the shortest burst first. Since round robin is sharing time more evenly, it is also able to get some shorter processes through first. First Come First Serve does not optimize to get any jobs through and simple execute the job in the order that it arrived, so it makes sense that some jobs will wait a long time for jobs with longer burst to finish.
