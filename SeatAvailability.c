// SeatAvailability.c Contains Main 2 seat Functions for Display of empty seats.
#include<stdio.h>
#include<stdlib.h>
#include"main.h"

int AvailableSeats(Plane* ps, int n)        // Function for printing Count of Empty seats 
{
    int Empty = 0;
    for (int i = 0; i < NUM; i++)
    {
        if (ps[n].Seat[i].status == 0)
            Empty++;
    }

    printf("Number of Empty Seats on flight %d : %d\n", ps[n].plane_num, Empty);
    return Empty;
}
int AvailableSeatsList(Plane* ps, int n)        // Function for printing Empty seats 
{
    int num;
    int Empty = 0;

    printf("List of empty seats of Flight %d : ", ps[n].plane_num);
    for (int i = 0; i < NUM; i++)
    {

        if (ps[n].Seat[i].status == 0)
        {
            Empty++;
            printf("%d ", ps[n].Seat[i].Seatnum);

        }
    }
    if (Empty == 0)
    {
        printf("Flight %d has no empty seats.\n", ps[n].plane_num);
    }
    else
    {
        printf("\n");
    }
    return Empty;
}
