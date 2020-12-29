#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

#include"main.h"            // Including HeaderFile "main.h"

int main(void)
{
    FILE* Airline_Details;      // File For Storing Customer Details
    Plane airline[PLANES];      //  Initialising Struct Plane as airline
    int size = sizeof(Plane);

    char Inp1, Inp2;
    int Flight_ID;

    if ((Airline_Details = fopen("airline.dat", "rb")) == NULL)     //  Opening File For Storage
    {
        Assign(airline, PLANES);        // Function For Assigning the Number of Empty Flights and Seats
    }
    else
    {
        for (int i = 0; i < PLANES; i++)
        {
            fread(&airline[i], size, 1, Airline_Details);
        }
        fclose(Airline_Details);
    }

    printWelcomeMenu();                 //  Function For Printing Welcome Menu
    FlightMenu();                       //  Function for Printing Flight Menu

    bool FlightSelected = true;         // Loop Variable for Flight Selection
    bool ContinueProgram = true;        // Loop Variable for Seat Selection
    while (FlightSelected)
    {
        Inp1 = LetterInput("12340");    //  Taking Input For Flight Selection Using LetterInput Function
        if (Inp1 != '0')
        {
            puts("Confirm Changes? <y/n>");   // Confirming the Entry using LetterInput Function
            char c = LetterInput("yn");
            if (c == 'y')
            {
                Flight_ID = SelectFlight(Inp1, airline);      // Assigning the Flight Number For Contonuing Seat Functions.
                SeatOptions();                      // Printing Seat Options using SeatOption Function
            }
            else if (c == 'n')
            {
                FlightSelected = false;     //  Loop Break Condition
            }

            while (ContinueProgram)         // Loop For Seat Selection
            {
                Inp2 = LetterInput("abcdefg");      //  Taking User Option Input
                if (Inp2 != 'g')
                {
                    showplane(Flight_ID);                       //  Function for Printing Selected Flight in Every Display
                    SelectOptions(Inp2, airline, Flight_ID);    //  Switch Function For Selecting Seat Options
                    SeatOptions();                              //  Printing Seat Options using SeatOption Function

                }
                else
                    ContinueProgram = false;
            }
            FlightMenu();           // Return To Flight MEnu If User Chooses to Quit
        }
        else
            FlightSelected = false;
    }

    ClearPlane(airline);
    if ((Airline_Details = fopen("airline.dat", "wb")) == NULL)
    {
        fprintf(stderr, "Can't open file %s.\n", "airline.dat");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < PLANES; i++)
    {
        fwrite(&airline[i], size, 1, Airline_Details);
    }
    fclose(Airline_Details);
    puts("Program Terminated. Have a Nice Day");
    return 0;
}

// main.c Ends Here...

