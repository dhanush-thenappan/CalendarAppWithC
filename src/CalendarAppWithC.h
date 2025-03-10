// Header guard
#ifndef CALENDARAPPWITHC_H

// Define CALENDARAPPWITHC_H
#define CALENDARAPPWITHC_H

// Preprocessor definitions
#define BDAY  .tm_mday
#define BMON  .tm_mon
#define BYEAR .tm_year

// Typedefinitions
typedef struct tm TIME;

// Function declarations
int CheckLeap(int year);
void TodayDate(struct tm* today);
void PrintThanksMessage();

#endif