#include<iostream>
#include<stdlib.h>
#include<iomanip>
using namespace std;

int main() {
    int p[20], rem_bt[20];
    float bt[20], wt[20], tat[20];
    int i, n, time = 0, count, quantum;
    float wtavg = 0, tatavg = 0;
    
    system("clear");
    
    cout << "\nEnter the number of processes -- ";
    cin >> n;
    
    cout << "Enter the time quantum -- ";
    cin >> quantum;
    
    for(i = 0; i < n; i++) {
        p[i] = i;
        cout << "Enter Burst Time for Process " << i << " -- ";
        cin >> bt[i];
        rem_bt[i] = (int)bt[i];  
        wt[i] = 0.0f;         
    }
    
    count = n;  
    while(count > 0) {
        for(i = 0; i < n; i++) {
            if(rem_bt[i] > 0) {
                if(rem_bt[i] > quantum) {
                    
                    time += quantum;
                    rem_bt[i] -= quantum;
                } else {
                
                    time += rem_bt[i];
                    wt[i] = (float)time - bt[i];  
                    rem_bt[i] = 0;
                    count--;
                }
            }
        }
    }
   
    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];  
        wtavg += (float)wt[i];
        tatavg += (float)tat[i];
    }

    cout << "\n\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n";
    for(i = 0; i < n; i++) {
        cout << "\n\tP" << p[i] << "\t\t" << fixed << setprecision(2) << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i];
    }
    
    cout << "\nAverage Waiting Time -- " << fixed << setprecision(6) << wtavg / (float)n;
    cout << "\nAverage Turnaround Time -- " << fixed << setprecision(6) << tatavg / (float)n;
    
    cin.get();
    return 0;
}
