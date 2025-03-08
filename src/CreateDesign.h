// Header guard
#ifndef CREATEDESIGN_H

// Define CREATEDESIGN_H
#define CREATEDESIGN_H

// Preprocessor definitions
#define MAX_MONTH_CHAR_LIMIT 29
#define MAX_ROW_CHAR_LIMIT 89
#define MAX_MONTH_LIMIT_PER_ROW 4
#define TOTAL_MONTHS 12
#define MAX_DAYS_IN_A_WEEK 7
#define FALSE 0
#define TRUE 1

// Function declarations
void CreateDesign(int year);
void PrintMonthName(int *monthCount);
void PrintWeekRow();
void PrintSeparator();
void PrintDates(int year, int startMonth);
void PrintRowEnd();

// Global variable declarations
extern char Months[12][10];
extern char Days[7];
extern int DaysInMonth[12];

#endif