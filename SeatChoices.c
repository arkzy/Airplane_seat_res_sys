// SeatChoices.c Contains the Main three funtions for Booking, Confirmation and Cancelling.

// SeatChoices.c starts here..

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

#include"main.h"

// Function For Booking Seats
void BookSeat(Plane* P, int n)
{
    char lname[MAXLEN];
    char fname[MAXLEN];
    int EmptySeats = AvailableSeatsList(P, n);  // Taking available seats list
    int num;
    bool continueprogram = true;
    if (EmptySeats == 0)            // Checking if seats are available
        printf("Sorry, flight %d has no empty seats to orded, choose another flight.\n", P[n].plane_num);
    else
    {
        printf("\nPlease select a seat from the empty seat numbers listed above.\n");
        while (continueprogram)
        {
            num = CheckInput(1, NUM);
            if (P[n].Seat[num - 1].status == 1)     // Loop for checking if the Seat is already booked
            {
                printf("Seat %d has been ordered, Please enter another one :\n", num);
                continue;
            }
            else
                continueprogram = false;
        }
        puts("Please enter your Last name:");       // Collecting names for Identification
        NameInput(lname, MAXLEN);
        puts("Please enter your First name:");
        NameInput(fname, MAXLEN);
        puts("Do you wish to save the change ?\nEnter y for YES and n for NO -->");
        char c = LetterInput("yn");
        if (c == 'y')
        {
            strcpy(P[n].Seat[num - 1].lname, lname);        // Assigning names to the specific seat slot
            strcpy(P[n].Seat[num - 1].fname, fname);
            P[n].Seat[num - 1].status = 1;
        }
    }
}
// Function For Cancelling Seats
void CancelSeat(Plane* P, int n)
{
    char lname[MAXLEN];     // Variables for Name Storing
    char fname[MAXLEN];
    char Inp;
    int Ordered = 0;
    int EmptySeats = 0;
    int delete;
    char assigned[NUM];
    int j;
    int ok;
    printf("Please enter your last name:\n");
    NameInput(lname, MAXLEN);                       //  Taking name input for identifiying seat
    printf("Please enter your first name:\n");
    NameInput(fname, MAXLEN);
    puts("List of ordered Seats :");
    for (int i = 0, j = 0; i < NUM; i++)                // Loop For Printing the Seat Numbers that have assigned to that user
    {
        if (strcmp(lname, P[n].Seat[i].lname) == 0      // Comparing Entered names for Confirmation
            && strcmp(fname, P[n].Seat[i].fname) == 0)
        {
            Ordered = 1;
            EmptySeats++;
            assigned[j++] = P[n].Seat[i].Seatnum;
            printf("%d ", P[n].Seat[i].Seatnum);
        }
    }
    if (Ordered == 0)
        puts("Sorry, you haven't ordered any seat.");
    else
    {
        ok = 1;
        Ordered = 0;
        puts("Input the number you want to delete:");
        while (ok)
        {
            delete = CheckInput(1, NUM);                        // Checking if etered value is in range or correct input
            for (int i = 0; i < EmptySeats, Ordered == 0; i++)
            {
                if (delete == assigned[i])
                {
                    Ordered = 1;
                }

            }

            if (Ordered == 0)
            {
                printf("Please select a number from your Ordered List :\n");
                continue;
            }
            else
                ok = 0;
        }
        puts("Do you wish to save the change ?\nEnter y for YES and n for NO -->");
        Inp = LetterInput("yn");
        if (Inp == 'y')
        {
            P[n].Seat[delete - 1].status = 0;           //  Clearing the entry form that specific array slot
            strcpy(P[n].Seat[delete - 1].lname, "");
            strcpy(P[n].Seat[delete - 1].fname, "");
        }
    }
}
// Function For Confirming Seats
void ConfirmSeat(Plane* P, int n)               // Function for confirming seat
{
    int seat, loop;



    if (AvailableSeats(P, n) == NUM)
        puts("All seats already are empty.");
    else
    {
        ViewDetails(P, n);          //  Using the Detailed List for Selection

        puts("Enter the number of the seat to be confirmed:");
        do
        {
            while (scanf("%d", &seat) != 1)     // Loop For taking Seat Number and checking if it is Booked
            {

                puts("Enter a number which is has been selected:");
                ViewDetails(P, n);
            }
            if (seat < 1 || seat > NUM || P[n].Seat[seat - 1].status == 0)  // Loop For checking if the Input is Incorret
            {
                puts("Enter a number from this list:");
                ViewDetails(P, n);
                loop = 1;
            }
            else
                loop = 0;
        } while (loop == 1);
        while (getchar() != '\n')
            continue;
        printf("%s %s to be confirmed for seat %d.\n", P[n].Seat[seat - 1].fname, P[n].Seat[seat - 1].lname, seat);
        puts("Enter 1 to confirm assignment, 0 to abort.");
        if (LetterInput("10") == '1')
        {
            P[n].Seat[seat - 1].Confirm = CONFIRMED;        // Changing Status of seat to confirmed
            puts("Passenger confirmed to seat.");
        }
        else
            puts("Passenger not confirmed.");
    }
}

// End of Seatchoices.c