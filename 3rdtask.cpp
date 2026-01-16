#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

class Process {
public:
    int id;
    double burstTime;
};

int main() {
    // Burst times
    double burstTime[] = {50.54, 10.11, 33.34, 2.5, 101.1};
    int numProcesses = sizeof(burstTime) / sizeof(burstTime[0]);

    double waitingTime[numProcesses];
    double turnaroundTime[numProcesses];
    double completionTime[numProcesses];

    // Create process list
    Process processes[numProcesses];
    for (int i = 0; i < numProcesses; i++) {
        processes[i].id = i + 1;
        processes[i].burstTime = burstTime[i];
    }

    // Sort processes by burst time (SJF)
    sort(processes, processes + numProcesses,
         [](const Process &a, const Process &b) {
             return a.burstTime < b.burstTime;
         });

    // Completion time calculation
    completionTime[0] = processes[0].burstTime;
    for (int i = 1; i < numProcesses; i++) {
        completionTime[i] = completionTime[i - 1] + processes[i].burstTime;
    }

    // Turnaround time and waiting time
    for (int i = 0; i < numProcesses; i++) {
        turnaroundTime[i] = completionTime[i];
        waitingTime[i] = turnaroundTime[i] - processes[i].burstTime;
    }

    // Output
    cout << fixed << setprecision(2);
    cout << "Process  Burst Time  Completion Time  Turnaround Time  Waiting Time\n";

    double totalWT = 0, totalTAT = 0;
    for (int i = 0; i < numProcesses; i++) {
        cout << setw(4) << processes[i].id << "        "
             << setw(8) << processes[i].burstTime << "       "
             << setw(10) << completionTime[i] << "  "
             << setw(10) << turnaroundTime[i] << "  "
             << setw(8) << waitingTime[i] << endl;

        totalWT += waitingTime[i];
        totalTAT += turnaroundTime[i];
    }

    // Averages
    double avgWT = totalWT / numProcesses;
    double avgTAT = totalTAT / numProcesses;

    cout << "\nAverage Waiting Time: " << avgWT << endl;
    cout << "Average Turnaround Time: " << avgTAT << endl;

    return 0;
}
