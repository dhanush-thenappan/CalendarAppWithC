// Header guard
#ifndef CREATEDESIGN_H

// Define CREATEDESIGN_H
#define CREATEDESIGN_H

// Preprocessor definitions
#define MAX_MONTH_CHAR_LIMIT 29 // Maximum limit (width) of characters for each month in the calendar
#define MAX_MONTH_LIMIT_PER_ROW 6 // Maximum months in a single row of the calendar
#define TOTAL_MONTHS 12 // Total months in a year
#define MAX_DAYS_IN_A_WEEK 7 // Total days in a week
#define TRUE 1 // TRUE means 1
#define FALSE 0 // False means 0

// ANSI escape codes for colors
#define RESET   "\x1B[0m"  // Reset color
#define RED     "\x1B[31m" // Red color (for today)
#define GREEN   "\x1B[32m" // Green (for day names)
#define YELLOW  "\x1B[33m" // Yellow (for week names)
#define CYAN    "\x1B[36m" // Cyan (for box lines)
#define BLUE    "\x1B[34m" // Blue (for month names)
#define MAGENTA "\x1B[35m" // Magenta (for birth dates)

// Function declarations
void CreateDesign(int year, struct tm Today, const struct tm birthDatesArray[], int sizeOfbirthDates);
void PrintMonthName(int *monthCount);
void PrintWeekRow();
void PrintSeparator();
void PrintDates(int year, int startMonth, struct tm Today, const struct tm birthDatesArray[], int sizeOfbirthDates);
void PrintRowEnd();
int CheckValidBirthDate(const struct tm birthDatesArray[], int sizeOfbirthDates, struct tm checkDate);

// Global variable declarations
extern char Months[12][10];
extern char Days[7];
extern int DaysInMonth[12];

#endif