// Airline Management System (Ticket Booking System)

#include <stdio.h>
#include <stdlib.h>

int n = 120;                // Global variable (No. of available Seats)
char flightTime[7];
char date[10];

struct passangerdetails     // Structure for passenger details
{
    char name[50];
    char gender[10];
    char email[50];
    char dob[20];
    char contact_No[20];
    char adhaar_no[20];
    int age;

};

struct passangerdetails pd[120];
int booked_count = 0;


void availableSeats()       // Ticket Availability Function
{
    printf("\nAvailable seats: %d\n\n", n);
}


void CancelSeat()           // Ticket Cancellation Function
{
    int cancel_ticket_no;
    printf("\n--- Cancel Seat ---\n");
    printf("Enter the ticket number to cancel (1 to %d): ", booked_count);
    scanf("%d", &cancel_ticket_no);

    if (cancel_ticket_no > 0 && cancel_ticket_no <= booked_count)
    {
        n++;
        booked_count--;

        printf("\nTicket No. %d cancelled successfully.\n", cancel_ticket_no);
        printf("Available seats are now: %d\n", n);
    }
    else
    {
        printf("\nError: Invalid ticket number.\n");
    }
}


int BookSeat()              // Ticket Booking Function
{
    char fromLocation[50], toLocation[50];
    int nseats;

    printf("\n--- Book Seat ---\n");
    printf("Enter From Location : ");
    scanf("%s", fromLocation);
    printf("Enter To Location : ");
    scanf("%s", toLocation);
    printf("Enter Flight Timing 08:30AM | 12:00AM | 06:25PM : ");
    scanf("%s", flightTime);
    printf("Enter Date (e.g., DD/MM/YYYY) : ");
    scanf("%s", date);

    printf("Enter the No. of Seats to book : ");
    scanf("%d", &nseats);

    if (nseats <= 0)                            // Validation
    {
        printf("Invalid number of seats.\n");
        return 0;
    }

    if (n < nseats)
    {
        if (n == 1)
        {
            printf("Sorry! Only %d seat is available.\n", n);
        }
        else
        {
            printf("Sorry! Only %d seats are available.\n", n);
        }
        return 0;
    }

    int ticket_no[nseats];

    for (int i = 0; i < nseats; i++)                    // Get Passanger details
    {
        printf("\n--- Passanger %d Details ---\n", i + 1);

        printf("Enter Passanger Name: ");
        scanf("%s", pd[i].name);

        printf("Enter Passanger Age: ");
        scanf("%d", &pd[i].age);

        printf("Enter Passanger Gender: ");
        scanf("%s", pd[i].gender);

        printf("Enter Passanger DOB (DD/MM/YYYY): ");
        scanf("%s", pd[i].dob);

        printf("Enter Passanger Contact No. : ");
        scanf("%s", pd[i].contact_No);

        printf("Enter Passanger E-mail: ");
        scanf("%s", pd[i].email);

        printf("Enter Passanger Adhaar No. : ");
        scanf("%s", pd[i].adhaar_no);

        ticket_no[i] = booked_count + i + 1;

        pd[booked_count + i] = pd[i];
    }


    n -= nseats;
    booked_count += nseats;

    printf("\nBooking is successfully completed!");
    printf("\n\n*--------------------------------- TICKET SUMMARY ----------------------------------*\n");

    for (int i = 0; i < nseats; i++)            // Display Ticket Summary

    {
        printf("\n*-----------------------------------------------------------------------------*\n");
        printf("TICKET NO: %d\n", ticket_no[i]);
        printf("Passenger: %s (Age: %d, Gender: %s)\n", pd[i].name, pd[i].age, pd[i].gender);
        printf("Contact: %s | Email: %s\n", pd[i].contact_No, pd[i].email);
        printf("Route: %s to %s\n", fromLocation, toLocation);
        printf("FlightTime: %s | Date: %s\n", flightTime, date);
        printf("*-----------------------------------------------------------------------------*\n");
    }
    return 0;
}


int main()                                       // Main function
{
    int choice;
    printf("\n\n*************************************\t");
    printf(" Welcome to Indian Airlines\t");
    printf("*************************************\n\n");

    while (1)
    {
        printf("*************************************\n");
        printf("1. Check Available Seats\n");
        printf("2. Book Seats");
        printf("\n3. Cancel Seat");
        printf("\n4. Exit");
        printf("\n*************************************\n\n");
        printf("Enter the Choice : ");
        scanf("%d", &choice);


        if (choice == 1)
        {
            availableSeats();        //  Calling fn - availableSeats()
        }
        else if (choice == 2)
        {
            BookSeat();              //  Calling fn - BookSeat()
        }
        else if (choice == 3)
        {
            CancelSeat();              //  Calling fn - CancelSeat()
        }
        else if (choice == 4)
        {
            printf("\nThank You! Come again!\n");
            break;
        }
        else
        {
            printf("\nInvalid choice. Please enter a number between 1 and 4.\n");
        }
    }
    return 0;
}
