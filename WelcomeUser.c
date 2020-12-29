#include<stdio.h>
#include"main.h"    // Including Header File

void printWelcomeMenu()		// Function For printing Welcome Menu
{
    printf("########################################################################################\n");
    printf("********\t\tWELCOME TO UserPlane BOOKING SYSTEM\t\t        *******\n");
    printf("********\tPLEASE SELECT THE OPTIONS BELOW AND EXPLORE OUR SERVICES\t*******\n");
    printf("########################################################################################\n\n");

}

void FlightMenu(void)       // Function For printing Flight Menu
{
    puts("Choose your flight:");
    puts("1) 102\n2) 311\n3) 444\n4) 519\n0) quit");
}

void SeatOptions(void)      // Function For Seat Options
{
    printf("****************************************************************");
    printf("\n(SELECT THE OPTIONS BY ENTERING THE INDEX LETTERS)\n");
    printf("a. SHOW NUMBER OF AVAILABLE SEATS.\n");
    printf("b. SHOW LIST OF EMPTY SEATS\n");
    printf("c. SHOW ALPHABETICAL LIST OF SEATS\n");
    printf("d. BOOK A SEAT\n");
    printf("e. Confirm Booked Seat\n");
    printf("f. CANCEL A BOOKED SEAT\n");
    printf("g. ABORT/EXIT PROGRAM\n\n");
    printf("****************************************************************\n");
}

int SelectFlight(char c, Plane* ps)             // Switch Function For Selecting Flight
{
    int FlightID;
    switch (c)
    {
    case '1': FlightID = 0;
        ps[0].selected = 1;
        puts("Flight 102 is being handled.");
        break;
    case '2': FlightID = 1;
        ps[1].selected = 1;
        puts("Flight 311 is being handled.");
        break;
    case '3': FlightID = 2;
        ps[2].selected = 1;
        puts("Flight 444 is being handled.");
        break;
    case '4': FlightID = 3;
        ps[3].selected = 1;
        puts("Flight 519 is being handled.");
        break;
    }
    return FlightID;
}

void SelectOptions(char c, Plane* ps, int n)    // switch Function For Selecting Seat Options
{
    switch (c)
    {
    case 'a':
        AvailableSeats(ps, n);
        break;
    case 'b':
        AvailableSeatsList(ps, n);
        break;
    case 'c':
        ViewDetails(ps, n);
        break;
    case 'd':
        BookSeat(ps, n);
        break;
    case 'e':
        ConfirmSeat(ps, n);
        break;
    case 'f':
        CancelSeat(ps, n);
        break;
    }
}

void showplane(int n)               // Function For Repeated Display of Flight
{
    switch (n)
    {
    case 0:

        puts("## Flight 102 is being handled.  ##\n");

        break;
    case 1:
        puts("## Flight 311 is being handled.  ##\n");
        break;
    case 2:
        puts("## Flight 444 is being handled.  ##\n");
        break;
    case 4:
        puts("## Flight 519 is being handled.  ##\n");
        break;
    }
}

//  WelcomeUser.c  Ends here...