// Standard includes
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

// User defined includes
#include "CalendarAppWithC.h"
#include "CreateDesign.h"
#include "DayOfDateCalculator.h"

// Global variable definitions

// Name of all months
char Months[12][10] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", 
                       "MAY", "JUNE", "JULY", "AUGUST", 
                       "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};

// First letter of all days of the week, starting from Sunday 
char Days[7] = {'S', 'M', 'T', 'W', 'T', 'F', 'S'};

// Number of days in each month of the year. If leap year, February's number of days becomes 29 from main function.
int DaysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Functions

/*
Function name: CreateDesign()
Return type: void
Parameters: int year, struct tm Today, const struct tm birthDatesArray[], int sizeOfbirthDates
Process: Creates the calendar design. 
         Based on the MAX_MONTH_LIMIT_PER_ROW set by the user in CreateDesign.h, this function calls
         1. PrintMonthName() to print month names
         2. PrintWeekRow() to print the week names
         3. PrintSeparator() to print the separator line
         4. PrintDates() to print all the dates in the months in that respective row. 
*/
void CreateDesign(int year, struct tm Today, const struct tm birthDatesArray[], int sizeOfbirthDates) {
    int monthCount = 0; // Track of month name that was last printed
    for(int i = 0; i < TOTAL_MONTHS / MAX_MONTH_LIMIT_PER_ROW; i++, printf("\n")) {
            PrintMonthName(&monthCount);
            printf("\n");
            PrintWeekRow();
            printf("\n");
            PrintSeparator();
            printf("\n");
            PrintDates(year, i, Today, birthDatesArray, sizeOfbirthDates);
            printf("\n");
    }
}

/*
Function name: PrintMonthName()
Return type: void
Parameters: int *monthCount
Process: Prints the first line in each month calendar which is the month name. Gets the name from the global variable Months[][]
         Uses the monthCount passed from the caller to keep track of current printing month
*/
void PrintMonthName(int *monthCount) {
    int monthLength;
    int charCount;
    int minSpace;
    // Print the month names based on the limit per row set in CreateDesign.h
    for(int j = 0; j < MAX_MONTH_LIMIT_PER_ROW; j++, printf("   "), (*monthCount)++) {
        monthLength = strlen(Months[*monthCount]);
        charCount = 0;
        minSpace = (MAX_MONTH_CHAR_LIMIT / 2) - (strlen(Months[*monthCount])/2);
        while(charCount < MAX_MONTH_CHAR_LIMIT) {
            if (charCount < minSpace) {
                printf(CYAN "_" RESET);
                charCount++;
            }
            else if (charCount == minSpace) {
                printf(BLUE "%s" RESET, Months[*monthCount]);
                charCount += strlen(Months[*monthCount]);
            }
            else {
                printf(CYAN "_" RESET);
                charCount++;
            }
        }
    }
}

/*
Function name: PrintWeekRow() 
Return type: void
Parameters: Nil
Process: Prints the week names by their first letter starting from Sunday. The data is got from the Global variable Days[].
*/
void PrintWeekRow() {
    for(int i = 0; i < MAX_MONTH_LIMIT_PER_ROW; i++, printf("   ")) {
        printf(CYAN "|" RESET);
        for(int j = 0; j < MAX_DAYS_IN_A_WEEK; j++, printf(CYAN "|" RESET)) {
            printf(YELLOW " %c " RESET, Days[j]);
        }
    }
}

/*
Function name: PrintSeparator() 
Return type: void
Parameters: Nil
Process: Prints the separator line which is '---' to make a table look.
*/
void PrintSeparator() {
    for(int i = 0; i < MAX_MONTH_LIMIT_PER_ROW; i++, printf("   ")) {
        printf(CYAN "|" RESET);
        for(int j = 0; j < MAX_DAYS_IN_A_WEEK; j++, printf(CYAN "|" RESET)) {
            printf(CYAN "---" RESET);
        }
    }
}

/*
Function name: PrintRowEnd()
Return type: void
Parameters: Nil
Process: Prints a separator line to at the end of each month to make it look seamless.
*/
void PrintRowEnd() {
    for(int i = 0; i < MAX_MONTH_LIMIT_PER_ROW; i++, printf("   ")) {
        printf(CYAN "-" RESET);
        for(int j = 0; j < MAX_DAYS_IN_A_WEEK; j++, printf(CYAN "-" RESET)) {
            printf(CYAN "---" RESET);
        }
    }
}

/*
Function name: PrintDates()
Return type: void
Parameters: int year, int startMonth, struct tm Today, const struct tm birthDatesArray[], int sizeOfbirthDates
Process: This function prints the dates of each month in each row. This function updates all the months row by row, not month by month.
         It also checks whether the year entered by the user is the current year. If yes, it prints Today's date in RED.
         It also takes the BirthDates array from main function and checks whether any birth date is available in the current year. If found, it prints them in MAGENTA.
*/
void PrintDates(int year, int startMonth, struct tm Today, const struct tm birthDatesArray[], int sizeOfbirthDates) {
    int DayCount[MAX_MONTH_LIMIT_PER_ROW]; // Current printing date of each month in the row
    int over = 0; // To check if all months have been printed
    int startDays[MAX_MONTH_LIMIT_PER_ROW]; // Finds the starting day of the month. That is the corrosponding day for the 1st of month.
    int currentMonth = 0; 
    struct tm currentWorkingDate;
    for(int i = 0; i < MAX_MONTH_LIMIT_PER_ROW; DayCount[i++] = 1); // Initialize all the start dates to 1
    for(int i = 0; i < MAX_MONTH_LIMIT_PER_ROW; i++)
        // startMonth * MAX_MONTH_LIMIT_PER_ROW)+1+i -> Gets the current working month
        startDays[i] = dayOfDate(1,(startMonth * MAX_MONTH_LIMIT_PER_ROW)+1+i,year); // Find starting days of all months
    // Since 0 in dayOfDate() is Saturday, changing it to 6 in the calendar.
    for (int i = 0; i < MAX_MONTH_LIMIT_PER_ROW; i++) {
        if(startDays[i] == 0) {
            startDays[i] = 6;
        }
        else {
            startDays[i] = startDays[i] - 1;
        }
    }
    // Loop to print all the dates in the number of months specified in MAX_MONTH_LIMIT_PER_ROW.
    // over != (int)(pow(2, MAX_MONTH_LIMIT_PER_ROW) - 1) -> Uses bits in the integer over to mark end of month. 
    // For example, if MAX_MONTH_LIMIT_PER_ROW is set to 4, over should be 15 to make the loop stop.
    // 15 in binary is 1111. When each month prints all its dates, it toggles the respective bit to one marking its completion.
    while (over != (int)(pow(2, MAX_MONTH_LIMIT_PER_ROW) - 1)) {
        printf(CYAN "|" RESET);
        // Print for all the months in the row which is equal to MAX_MONTH_LIMIT_PER_ROW.
        for(int i = 0; i < MAX_MONTH_LIMIT_PER_ROW; i++) {
            // Set the current month
            currentMonth = startMonth*MAX_MONTH_LIMIT_PER_ROW+i;
            // Print dates in the respective days
            for(int j = 0; j < MAX_DAYS_IN_A_WEEK; j++, printf(CYAN "|" RESET)) {
                // Update the currentWorkingDate with the day, month, year.
                currentWorkingDate.tm_mday = DayCount[i];
                currentWorkingDate.tm_mon = currentMonth;
                currentWorkingDate.tm_year = year;
                // If Day count in a particular month is completed, its bit position in "over" is toggled to 1. 
                if (DayCount[i] > DaysInMonth[currentMonth]) {
                    over |= (int)pow(2, i);
                    printf("   ");
                }
                // If Day Count is not matching with end date of the month, else case is executed
                else {
                    // Finds the first day of the month using the startDays[] array and the loop counter.
                    if(j == startDays[i]) {
                        // If the first day is the start of the month, then change the date color to RED. 
                        if(DayCount[i] == Today.tm_mday && currentMonth == Today.tm_mon && year == Today.tm_year)
                            printf(RED " %-2d" RESET, (DayCount[i])++);
                        // If first day is not today, then check if it is a birth date. If yes, then change the date color to MAGENTA
                        else if (CheckValidBirthDate(birthDatesArray, sizeOfbirthDates, currentWorkingDate))
                            printf(MAGENTA " %-2d" RESET, (DayCount[i])++);
                        // Else print the date in GREEN color.
                        else
                            printf(GREEN " %-2d" RESET, (DayCount[i])++);
                    }
                    // If not the first day, and the first day is already printed, then enter this case
                    else if(DayCount[i] > 1) {
                        // If the current day is the start of the month, then change the date color to RED. 
                        if(DayCount[i] == Today.tm_mday && currentMonth == Today.tm_mon && year == Today.tm_year)
                            printf(RED " %-2d" RESET, (DayCount[i])++);
                        // If current day is not today, then check if it is a birth date. If yes, then change the date color to MAGENTA
                        else if (CheckValidBirthDate(birthDatesArray, sizeOfbirthDates, currentWorkingDate))
                            printf(MAGENTA " %-2d" RESET, (DayCount[i])++);
                        // Else print the date in GREEN color.
                        else
                            printf(GREEN " %-2d" RESET, (DayCount[i])++);
                    }
                    // If not the valid day, then print empty spaces
                    else printf("   ");
                }
            }
            // Print space and | when the current month is not the last in the row.
            if (i != MAX_MONTH_LIMIT_PER_ROW - 1) {
                printf("   ");
                printf(CYAN "|" RESET);    
            }
        }
        printf("\n");
        // If the month is not over print the separator by calling PrintSeparator().
        if(over != (int)(pow(2, MAX_MONTH_LIMIT_PER_ROW) - 1))
            PrintSeparator();
        // If month is over, then call the PrintRowEnd() to print a end line.
        else
            PrintRowEnd();
        printf("\n");
    }
}

/*
Function name: CheckValidBirthDate()
Return type: int
Parameters: const struct tm birthDatesArray[], int sizeOfbirthDates, struct tm checkDate
Process: Loops through the birthDatesArray[] and checks whether it matches the checkDate. If mathces, the function returns 1.
*/
int CheckValidBirthDate(const struct tm birthDatesArray[], int sizeOfbirthDates, struct tm checkDate) {
    for (int i = 0; i < sizeOfbirthDates; i++) {
        // Check the year, month and date. If all 3 matches, return 1.
        if( birthDatesArray[i].tm_year == checkDate.tm_year &&
            (birthDatesArray[i].tm_mon - 1) == checkDate.tm_mon &&
            birthDatesArray[i].tm_mday == checkDate.tm_mday) {
                return 1;
        }
    }
    return 0;
}