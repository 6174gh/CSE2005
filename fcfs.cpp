// C++ program to Calculate Waiting Time for given Processes
// FCFS
#include <iostream>
using namespace std;

int * CalculateWaitingTime(int at[], int bt[],int wt[], int N)
{
    // Calculating waiting time for first process
    wt[0] = 0;
	cout << "P.No.\tArrival Time\t"<< "Burst Time\tWaiting Time\n";
	cout << "1"<< "\t\t" << at[0] << "\t\t"<< bt[0] << "\t\t" << wt[0] << endl;

	// Calculating waiting time for each process from the given formula
	for (int i = 1; i < N; i++) {
		wt[i] = (at[i - 1] + bt[i - 1] + wt[i - 1]) - at[i];

		// Print the waiting time for each process
		cout << i + 1 << "\t\t" << at[i]<< "\t\t" << bt[i] << "\t\t"<< wt[i] << endl;
	}

	return wt;
}

void CalculateAverageWaitingTime(int at[], int bt[],int wt[], int N){

    // Declare variable to calculate average
	float average;
	float sum = 0;

	// Loop to calculate sum of all waiting time
	for (int i = 0; i < N; i++) {
		sum = sum + wt[i];
	}

	// Find average waiting time by dividing it by no. of process
	average = sum / N;

	// Print Average Waiting Time
	cout << "Average waiting time = "<< average;
}

void CalculateAverageTurnroundTime(int bt[], int wt[], int N){
    int sum=0;
    for(int i=0; i<N; i++){
        sum += bt[i] + wt[i];
    }
    cout<<"Average Trunaround time is "<<sum/N;
}

// Driver code
int main()
{
	// Number of process
	int N = 5;

	// Array for Arrival time
	int at[] = { 0, 1, 2, 3, 4 };

	// Array for Burst Time
	int bt[] = { 4, 3, 1, 2, 5 };

    int *wt;
	// Function call to find waiting time
	wt = CalculateWaitingTime(at, bt, wt, N);
    CalculateAverageWaitingTime(at, bt, wt, N);
    CalculateAverageTurnroundTime(bt, wt, N);
	return 0;
}
