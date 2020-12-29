// SupportFunctions.c Contains All the Supporting functions for other Functions.


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#include"main.h"
void ClearPlane(Plane* P)          // Function for Dismissing Assigned Plane and Clear File
{
    for (int i = 0; i < PLANES; i++)
        P[i].selected = 0;
}
void Assign(Plane* P, int n)     // Function Used for Assigning Flights and Empty Seats
{
    P[0].plane_num = 102;         // Assigining Flights
    P[1].plane_num = 311;
    P[2].plane_num = 444;
    P[3].plane_num = 519;
    for (int i = 0; i < n; i++)
    {
        P[i].selected = 0;
        for (int j = 0; j < NUM; j++)
        {
            P[i].Seat[j].Seatnum = j + 1;
            P[i].Seat[j].status = 0;
            strcpy(P[i].Seat[j].lname, "");
            strcpy(P[i].Seat[j].fname, "");
        }
    }
}
int CheckInput(int min, int max)    // Function For Checking if Inputs are correct and are in between the Range of seats
{
    int ok = 1;
    int n, status;
    while (ok)
    {
        status = scanf("%d", &n);
        if (status != 1 || getchar() != '\n' || n<min || n>max)
        {
            printf("Please enter a value between %d & %d :\n", min, max);
            noNULL();
            continue;
        }
        else
            return n;
    }
}
char* NameInput(char* st, int n)        // Function For Taking Correct Name Input From Users
{
    char* Entry, * find;
    Entry = fgets(st, n, stdin);
    if (Entry)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            noNULL();
    }
    return Entry;
}

void noNULL(void)                   //  Function acts both as an Invalid Enter Entry Killer and Return 0.
{
    while (getchar() != '\n')
        continue;
}

char LetterInput(char* s)           // Function For Taking Correct Option Select Input Letters(Lowercase)
{
    char c;
    int ok = 1;
    while (ok)
    {
        c = getchar();
        c = tolower(c);
        if (getchar() != '\n' || strchr(s, c) == NULL)
        {
            printf("Invaid Entry! Please enter again: ");
            noNULL();
            continue;
        }
        else
            return c;
    }
}

// SupportFunctions.c ENds here...