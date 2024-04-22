#include <bits/stdc++.h>
using namespace std;

float sjf(int n, vector<int> &arrivalTime, vector<int> &burstTime)
{
    vector<int> completionTime(n);
    vector<int> waitingTime(n);
    vector<int> completed(n, 0); // initiallly all jobs are marked undone

    int systemTime = 0;
    int totalProcesses = 0;
    float avgwaitingTime = 0;

    // Till all the processes are done.
    while (totalProcesses != n)
    {
        int check = n; // initially no process is eligible for execution
        int min = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            // If the process arrival time is less than system time and it is not completed
            // and burstTime is smallest of this process this process will be executed first.
            if ((arrivalTime[i] <= systemTime) and (completed[i] == 0) and (burstTime[i] < min))
            {
                min = burstTime[i];
                check = i;
            }
        }
        // No process in the queue.
        if (check == n)
        {
            systemTime++;
        }
        else
        {
            completionTime[check] = systemTime + burstTime[check];
            systemTime += burstTime[check];
            waitingTime[check] = completionTime[check] - (arrivalTime[check] + burstTime[check]);
            completed[check] = 1;
            totalProcesses++;
        }
    }
    // Sum for calculating averages.
    for (int i = 0; i < n; i++)
    {
        avgwaitingTime += waitingTime[i];
    }
    float ans;
    ans = (float)(avgwaitingTime / n);
    return ans;
}
