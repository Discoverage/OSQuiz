#include <iostream>
#include <iomanip>
using namespace std;

void FcfsScheduling(int burstTimes[], int n)
{
    int completionTimes[n];
    int turnaroundTimes[n];
    int waitingTimes[n];

    // Completion time for first process
    completionTimes[0] = burstTimes[0];

    // Calculate completion times
    for (int i = 1; i < n; i++)
    {
        completionTimes[i] = completionTimes[i - 1] + burstTimes[i];
    }

    int totalTurnaroundTime = 0;
    int totalWaitingTime = 0;

    // Calculate turnaround time and waiting time
    for (int i = 0; i < n; i++)
    {
        turnaroundTimes[i] = completionTimes[i];
        waitingTimes[i] = turnaroundTimes[i] - burstTimes[i];

        totalTurnaroundTime += turnaroundTimes[i];
        totalWaitingTime += waitingTimes[i];
    }

    double avgTurnaroundTime = (double)totalTurnaroundTime / n;
    double avgWaitingTime = (double)totalWaitingTime / n;

    // Output table
    cout << " Process  Burst Time  Completion Time  Turnaround Time  Waiting Time\n";

    for (int i = 0; i < n; i++)
    {
        cout << "   P" << i + 1 << "       "
             << setw(3) << burstTimes[i] << "            "
             << setw(3) << completionTimes[i] << "                "
             << setw(3) << turnaroundTimes[i] << "               "
             << setw(3) << waitingTimes[i] << endl;
    }

    cout << fixed << setprecision(1);
    cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;
    cout << "Average Waiting Time: " << avgWaitingTime << endl;
}

int main()
{
    int burstTimes[] = {3, 5, 4, 3, 2, 1, 0, 7, 8, 1};
    int n = sizeof(burstTimes) / sizeof(burstTimes[0]);

    FcfsScheduling(burstTimes, n);
    return 0;
}
