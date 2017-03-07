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
  The wait time is shortest (55) on Shortest job first compared to 92 for FirstComeFirtServe and 87 for round robin. It make sense that this is the shortest since it is getting more jobs done in a smaller amount of time by optimizing for more short jobs first. Since round robin is sharing time more evenly, it is also able to get some shorter processes through first. FirstComeFirstServe does not optimize to get any jobs through, so it makes sense that some jobs will wait a long time for jobs with longer burst to finish.
