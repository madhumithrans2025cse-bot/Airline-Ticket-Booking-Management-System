
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

