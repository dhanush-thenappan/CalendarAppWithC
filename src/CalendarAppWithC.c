// Standard includes
#include <stdio.h>
#include <time.h>

// User-defined includes
#include "CalendarAppWithC.h"
#include "DayOfDateCalculator.h"
#include "CreateDesign.h"

// Main function
int main(void) {
    int year = 0;
    char choice;
    struct tm today; 
    // Array with Birth Dates which will be printed with MAGENTA on the calendar
    struct tm birthDates[2] = { {.tm_mday = 29, .tm_mon = 4, .tm_year = 2003},
                        {.tm_mday = 18, .tm_mon = 5, .tm_year = 2003}};
    int sizeOfbirthDates = sizeof(birthDates) / sizeof(birthDates[0]); // Find size of the birthDates array
    TodayDate(&today); // Find and store today's date
    do {
        printf("\e[1;1H\e[2J");
        GetYearInput:
        printf("Enter a year (1900-2100) to find its calendar (yyyy) : ");
        scanf("%d", &year); // Get year input from the user
        // If input is less than 1900 or greater than 2100, prompt the user again to give input in range
        if (year <= 1899 || year >= 2101) {
            printf("\e[1;1H\e[2J");
            printf(RED "Enter a valid year between 1900-2100!" RESET);
            goto GetYearInput;
        }
        // Check if the year entered is leap year. If yes, then number of days in February becomes 29
        if (CheckLeap(year)) {
            DaysInMonth[1] = 29;
        }
        // Call the CreateDesign() function to print the calendar
        CreateDesign(year, today, birthDates, sizeOfbirthDates);
        getchar();
    } while (printf("Do you wish to continue(Y\\N)? ") && scanf("%c", &choice) && (choice == 'Y' || choice == 'y')); // Ask choice from user whether to continue
    printf("\e[1;1H\e[2J");
    // Print a message at the end
    PrintThanksMessage();
    return 0;
}

/*
Function name: CheckLeap()
Return type: int
Parameters: int year
Process: Returns 1 when the year given is a leap and 0 if not.
*/
int CheckLeap(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1; // Leap year
            }
            return 0; // Not a leap year
        }
        return 1; // Leap year
    }
    return 0; // Not a leap year
}

/*
Function name: TodayDate()
Return type: void
Parameters: struct tm *today
Process: Find the date of today using the time() function from time.h and update the day, month and year values.
*/
void TodayDate(struct tm *today) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    // Extract day, month, and year
    today -> tm_mday = tm.tm_mday;
    today -> tm_mon = tm.tm_mon;  // Months are 0-based in tm struct
    today -> tm_year = tm.tm_year + 1900;  // Years since 1900

}

/*
Function name: PrintThanksMessage()
Return type: void
Parameters: Nil
Process: Print a "HAVE A GREAT DAY" message inside a box in the end.
*/
void PrintThanksMessage() {
    printf(GREEN "|----------------------------------------------------------------------------------------|\n" RESET);
    printf(GREEN "|                                   " RED " HAVE A GREAT DAY " GREEN "                                   |\n" RESET);
    printf(GREEN "|----------------------------------------------------------------------------------------|\n" RESET);
}