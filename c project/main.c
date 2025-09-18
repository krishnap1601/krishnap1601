#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRAINS 5
#define MAX_SEATS 50
#define MAX_PASSENGERS 100

// Structure for train details
struct Train {
    int train_no;
    char name[50];
    char source[30];
    char destination[30];
    int seats_available;
};
// Structure for passenger details
struct Passenger {
    int pnr;
    char name[50];
    int age;
    int train_no;
    int seat_no;
};
// Global arrays
struct Train trains[MAX_TRAINS];
struct Passenger passengers[MAX_PASSENGERS];
int passenger_count = 0;
int pnr_counter = 1000;

// Function prototypes
void initializeTrains();
void displayTrains();
void bookTicket();
void viewPassengers();
void cancelTicket();

int main() {
    int choice;
    initializeTrains();

    while (1) {
        printf("\n===== Railway Reservation System =====\n");
        printf("1. Display Train Details\n");
        printf("2. Book Ticket\n");
        printf("3. View Passengers\n");
        printf("4. Cancel Ticket\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayTrains();
                break;
            case 2:
                bookTicket();
                break;
            case 3:
                viewPassengers();
                break;
            case 4:
                cancelTicket();
                break;
            case 5:
                printf("Thank you for using Railway Reservation System!\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Initialize train details
void initializeTrains() {
    trains[0] = (struct Train){101, "Deccan Express", "Mumbai", "Pune", MAX_SEATS};
    trains[1] = (struct Train){102, "Shatabdi Express", "Mumbai", "Delhi", MAX_SEATS};
    trains[2] = (struct Train){103, "Konkan Express", "Mumbai", "Goa", MAX_SEATS};
    trains[3] = (struct Train){104, "Rajdhani Express", "Delhi", "Kolkata", MAX_SEATS};
    trains[4] = (struct Train){105, "Duronto Express", "Pune", "Nagpur", MAX_SEATS};
}

// Display train details
void displayTrains() {
    printf("\nAvailable Trains:\n");
    printf("Train No\tName\t\t\tSource\t\tDestination\tSeats Available\n");
    for (int i = 0; i < MAX_TRAINS; i++) {
        printf("%d\t\t%-20s%-15s%-15s%d\n",
               trains[i].train_no,
               trains[i].name,
               trains[i].source,
               trains[i].destination,
               trains[i].seats_available);
    }
}

// Book ticket
void bookTicket() {
    int tno;
    printf("\nEnter Train Number to book ticket: ");
    scanf("%d", &tno);

    // Search for train
    int found = -1;
    for (int i = 0; i < MAX_TRAINS; i++) {
        if (trains[i].train_no == tno) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Train not found!\n");
        return;
    }

    if (trains[found].seats_available <= 0) {
        printf("No seats available on this train!\n");
        return;
    }

    // Passenger details
    struct Passenger p;
    p.pnr = pnr_counter++;
    p.train_no = tno;
    p.seat_no = MAX_SEATS - trains[found].seats_available + 1;

    printf("Enter passenger name: ");
    scanf(" %[^\n]", p.name);
    printf("Enter age: ");
    scanf("%d", &p.age);

    passengers[passenger_count++] = p;
    trains[found].seats_available--;

    printf("Ticket booked successfully! PNR: %d, Seat No: %d\n", p.pnr, p.seat_no);
}

// View passenger details
void viewPassengers() {
    if (passenger_count == 0) {
        printf("\nNo passengers booked yet.\n");
        return;
    }
    printf("\nPassenger List:\n");
    printf("PNR\tName\t\tAge\tTrain No\tSeat No\n");
    for (int i = 0; i < passenger_count; i++) {
        printf("%d\t%-15s%d\t%d\t\t%d\n",
               passengers[i].pnr,
               passengers[i].name,
               passengers[i].age,
               passengers[i].train_no,
               passengers[i].seat_no);
    }
}

// Cancel ticket
void cancelTicket() {
    int pnr;
    printf("\nEnter PNR to cancel ticket: ");
    scanf("%d", &pnr);

    int found = -1;
    for (int i = 0; i < passenger_count; i++) {
        if (passengers[i].pnr == pnr) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Ticket with PNR %d not found!\n", pnr);
        return;
    }

    // Update train seat availability
    for (int i = 0; i < MAX_TRAINS; i++) {
        if (trains[i].train_no == passengers[found].train_no) {
            trains[i].seats_available++;
            break;
        }
    }

    printf("Ticket for %s (PNR: %d) cancelled successfully.\n",
           passengers[found].name, passengers[found].pnr);

    // Remove passenger
    for (int i = found; i < passenger_count - 1; i++) {
        passengers[i] = passengers[i + 1];
    }
    passenger_count--;
}
