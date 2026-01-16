using System;

class Program
{
    static void Main(string[] args)
    {
        int[] burstTimes = { 3, 5, 4, 3, 2, 1, 0, 7, 8, 1 };
        int n = burstTimes.Length;

        int[] completionTimes = new int[n];
        int[] turnaroundTimes = new int[n];
        int[] waitingTimes = new int[n];

        // Calculate completion times
        completionTimes[0] = burstTimes[0];
        for (int i = 1; i < n; i++)
        {
            completionTimes[i] = completionTimes[i - 1] + burstTimes[i];
        }

        // Calculate turnaround and waiting times
        double totalTurnaround = 0;
        double totalWaiting = 0;
        for (int i = 0; i < n; i++)
        {
            turnaroundTimes[i] = completionTimes[i]; // Assuming arrival time is 0
            waitingTimes[i] = turnaroundTimes[i] - burstTimes[i];

            totalTurnaround += turnaroundTimes[i];
            totalWaiting += waitingTimes[i];
        }

        double avgTurnaround = totalTurnaround / n;
        double avgWaiting = totalWaiting / n;

        Console.WriteLine($"Average Turnaround Time: {avgTurnaround:F2}");
        Console.WriteLine($"Average Waiting Time: {avgWaiting:F2}");
    }
}
