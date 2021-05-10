/**
 * Author Abhinav Manocha
 * Referenced: https://www.geeksforgeeks.org/program-for-fcfs-cpu-scheduling-set-1/
 * */

//Include statement
#include <stdio.h>

//----------------------------------------------------------------//
//Main method
int main()
{
    //-------------------------- Initialize Variables --------------------------------------//
    int processes[] = {1, 2, 3, 4, 5, 6, 7};  //Process ID's
    int burst_time[] = {3, 3, 3, 3, 3, 3, 3}; //Burst times for testing

    int n = sizeof processes / sizeof processes[0]; //Size of
    int wait_time[n];                               //Wait time
    int turn_around_time[n];                        //Turn around time
    int total_waitTime = 0;                         //Total wait time
    int total_turn_around_time = 0;                 //Total turn around time

    wait_time[0] = 0; //Wait time was initialized to 0

    //-------------------------- Calculated wait time --------------------------------------//
    for (int i = 1; i < n; i++)
    {
        wait_time[i] = burst_time[i - 1] + wait_time[i - 1];
    }

    //-------------------------- Calculated turn around time --------------------------------------//

    for (int i = 0; i < n; i++)
    {
        turn_around_time[i] = burst_time[i] + wait_time[i]; //Burst time + wait time is turn around time
    }

    //-------------------------- Display formatting for FIFO/FCFS --------------------------------------//

    printf("==============================================================\n");
    printf("FIFO/FCFS:");
    printf("\nProcesses\tBurst time\tWaiting time\tTurn around time\n"); //Include spacing with tabs

    for (int i = 0; i < n; i++)
    {
        //Formater output
        total_waitTime = total_waitTime + wait_time[i];                        //Calculating total wait time
        total_turn_around_time = total_turn_around_time + turn_around_time[i]; //Calculating total turn around time
        printf("%d ", (i + 1));                                                //Listing all the process ID's starting from 1 and not from 0
        printf("\t	 %d ", burst_time[i]);                                     //Display burst time
        printf("\t	 %d", wait_time[i]);                                       //Display wait time
        printf("\t	 %d\n", turn_around_time[i]);                              //Display turn around time
    }
    int s = (float)total_waitTime / (float)n;
    int t = (float)total_turn_around_time / (float)n;
    printf("Average waiting time = %d", s);
    printf("\tAverage turn around time = %d \n", t);
    printf("-\n");
    printf("\n");

    //-------------------------- Display formatting for SJF --------------------------------------//

    printf("SJF:");
    //Display processes along with all details
    printf("\nProcesses\tBurst time\tWaiting time\tTurn around time\n");

    //-------------------------------------------------------------------------------------------------//

    total_waitTime = 0;         //Re-initializing the values to 0
    total_turn_around_time = 0; //Re-initializing the values to 0

    int sort;    //Placeholder variable
    int tempVar; //Temporary variable

    //-------------------------- Sorting burst time from lowest to highest --------------------------------------//

    for (int i = 0; i < n; i++) //for loop for comparision
    {
        sort = i;                       //Placeholder keep the value of i
        for (int j = i + 1; j < n; j++) //ANother loop to compare the burst time
        {
            if (burst_time[j] < burst_time[sort]) //If burst time j is smaller than burst time i (Placeholder sort) then set the placeholder = j
            {
                sort = j; //Placeholder keep the value of j
            }
        }

        tempVar = burst_time[i];          //The temp variablewill keep the value of burst i
        burst_time[i] = burst_time[sort]; //burst i = burst placeholder
        burst_time[sort] = tempVar;       //Burst sort = temp variable

        tempVar = processes[i];         //temp variable will be set to process i
        processes[i] = processes[sort]; //process i = process placeholder
        processes[sort] = tempVar;      //process placeholder = temp variable
    }

    wait_time[0] = 0; //This is mandatory or the program will break

    //-------------------------- For loop calculating wait time --------------------------------------//

    for (int i = 1; i < n; i++)
    {
        wait_time[i] = 0; //sets the wait time to 0, since we don't need to worry about arrival time
        for (int j = 0; j < i; j++)
        { //Calculates wait time
            wait_time[i] += burst_time[j];
        }

        total_waitTime += wait_time[i];
    }
    //-------------------------- Almost the same formatting as before --------------------------------------//
    for (int i = 0; i < n; i++)
    {
        turn_around_time[i] = burst_time[i] + wait_time[i]; //Minor adjustments in the ordering of these
        total_waitTime += turn_around_time[i];              //Calculating total wait time
        total_turn_around_time += turn_around_time[i];      //Calculating total turn around time

        printf("%d ", (i + 1));                   //Listing all the process ID's starting from 1 and not from 0
        printf("\t	 %d ", burst_time[i]);        //Display burst time
        printf("\t	 %d", wait_time[i]);          //Display wait time
        printf("\t	 %d\n", turn_around_time[i]); //Display turn around time
    }
    int j = (float)total_waitTime / (float)n;         //average wait time
    int k = (float)total_turn_around_time / (float)n; //average turn around time
    printf("Average waiting time = %d", j);
    printf("\tAverage turn around time = %d \n", k);
    printf("==============================================================\n"); //formatting

    return 0;
}
