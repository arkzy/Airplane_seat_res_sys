// ViewDetails.c Contains Only one function that shows The Seats detailed List
#include<stdio.h>
#include<stdlib.h>


#include"main.h"

void ViewDetails(Plane* ps, int n)      // Function for Detailed Seat View
{
    printf("The Ascending Ordered List of Seats with details are :\n");
    printf("|||Seat Number || status || last name ,first name |||\n\n");
    printf("---------------------------------------------------\n");


    for (int i = 0; i < NUM; i++)
    {
        printf("\n||| %d || %d || %s,%s ||", ps[n].Seat[i].Seatnum, ps[n].Seat[i].status, ps[n].Seat[i].lname, ps[n].Seat[i].fname);
        if (ps[n].Seat[i].Confirm == CONFIRMED)
        {
            puts(" confirmed |||\n");
        }
        else
        {
            puts(" unconfirmed |||\n");
        }
        printf("---------------------------------------------------\n");


    }
    printf("PS:For status: 0 means empty, 1 means assigned.\n\n");

}
// ViewDetails ENds Here