#include <stdio.h>

// A structure to represent a job
typedef struct Job
{
    char id;      
    int deadline;
    int profit;   
} Job;

// Function to sort jobs based on their profit in descending order using a simple sorting algorithm
void sortJobsByProfit(Job jobs[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (jobs[i].profit < jobs[j].profit)
            {
                Job temp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp;
            }
        }
    }
}

// Function to find the maximum deadline
int findMaxDeadline(Job jobs[], int n)
{
    int max = jobs[0].deadline;
    for (int i = 1; i < n; i++)
    {
        if (jobs[i].deadline > max)
        {
            max = jobs[i].deadline;
        }
    }
    return max;
}

// Function to perform job sequencing with deadlines
void jobSequencingWithDeadlines(Job jobs[], int n)
{
    // Step 1: Sort all jobs in descending order of profit
    sortJobsByProfit(jobs, n);

    // Find the maximum deadline to define the timeline array size
    int maxDeadline = findMaxDeadline(jobs, n);

    // Step 2: Initialize timeline slots
    int timeline[maxDeadline + 1];
    for (int i = 0; i <= maxDeadline; i++)
    {
        timeline[i] = -1; // -1 indicates the slot is free
    }

    // Step 3: Iterate through jobs and place each job in the latest possible time slot before its deadline
    int totalProfit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[i].deadline; j > 0; j--)
        {
            if (timeline[j] == -1)
            {
                timeline[j] = i;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Print the result
    printf("Scheduled jobs: ");
    for (int i = 1; i <= maxDeadline; i++)
    {
        if (timeline[i] != -1)
        {
            printf("%c ", jobs[timeline[i]].id);
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}

int main()
{
    Job jobs[] = {
        {'a', 2, 150},
        {'b', 1, 15},
        {'c', 2, 30},
        {'d', 1, 25},
        {'e', 3, 20}};
    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobSequencingWithDeadlines(jobs, n);

    return 0;
}
