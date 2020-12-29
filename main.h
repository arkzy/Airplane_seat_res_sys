// main.h file for the whole Project 

//Contains all the Functions and Wanted Structures including Static Variables & Libraries

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#pragma warning(disable : 4996)
#define MAXLEN 30       // Static Variable for Name Length
#define NUM 12          // Static Variable for Seat Strength
#define PLANES 4        // Static Vaiable to Store Number of Planes
#define CONFIRMED 1     
// Strucute For Seat Assignment
typedef struct
{
    int Seatnum;        // Variable for storing Seatnumber
    int status;         // Status variable for Booked or not
    int Confirm;
    char lname[MAXLEN];
    char fname[MAXLEN];
} seat;
// Structure For Plane nested Seat
typedef struct
{
    int plane_num;
    seat Seat[NUM];
    int selected;
} Plane;
//    Functions                                                  Use

void Assign(Plane* ps, int n);                      // To Assign Empty Flights

void printWelcomeMenu();                            // Welcome Message Printer
void FlightMenu(void);                              // Flight Menu Printer
int SelectFlight(char c, Plane* ps);                // Function For Selecting Flight For providing it to Seat Assignment
void showplane(int n);                              // For Repeated Printing of Flight Being Handled at Every Display
void SeatOptions(void);                             // Seat options Printer
void SelectOptions(char c, Plane* ps, int n);       // Switch Function For Selecting Options

char* NameInput(char* st, int n);                   // For Taking Name Inputs
char LetterInput(char* s);                          // Letter Input Taker for Option Selection
int CheckInput(int min, int max);                   // For checking Inputs are correct
void noNULL(void);                                  // For Terminating Null  values and accidental entries

int AvailableSeats(Plane* ps, int n);               // For Printing Number of Empty Seats
int AvailableSeatsList(Plane* ps, int n);           // For printing List of empty Seats
void ViewDetails(Plane* ps, int n);                 // Detailed view of Seats 
void BookSeat(Plane* ps, int n);                    // Function to book a seat
void ConfirmSeat(Plane* ps, int);                   // Function to Confirm a seat
void CancelSeat(Plane* ps, int n);                  // Function to Cancel a Seat

void ClearPlane(Plane* ps);                         // Function for Clearing the Plane and File