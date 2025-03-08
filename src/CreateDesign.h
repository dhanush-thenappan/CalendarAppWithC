// Header guard
#ifndef CREATEDESIGN_H

// Define CREATEDESIGN_H
#define CREATEDESIGN_H

// Preprocessor definitions
#define MAX_MONTH_CHAR_LIMIT 29
#define MAX_MONTH_LIMIT_PER_ROW 6
#define TOTAL_MONTHS 12
#define MAX_DAYS_IN_A_WEEK 7
#define TRUE 1
#define FALSE 0
#define RESET   "\x1B[0m"    // Reset color
#define RED     "\x1B[31m"   // Red color (for today)
#define GREEN   "\x1B[32m" // Green
#define YELLOW  "\x1B[33m" // Yellow
#define CYAN    "\x1B[36m" // Cyan (Light Blue)
#define BLUE    "\x1B[34m" // Blue
#define MAGENTA "\x1B[35m" // Magenta (Purple)
// Function declarations
void CreateDesign(int year, struct tm Today);
void PrintMonthName(int *monthCount);
void PrintWeekRow();
void PrintSeparator();
void PrintDates(int year, int startMonth, int currentYear, struct tm Today);
void PrintRowEnd();

// Global variable declarations
extern char Months[12][10];
extern char Days[7];
extern int DaysInMonth[12];

#endif