#include <stdio.h>
#include <time.h>
#include "CalendarAppWithC.h"
#include "DayOfDateCalculator.h"
#include "CreateDesign.h"

int main(void) {
    int year = 0;
    struct tm today;
    TodayDate(&today);
    printf("\e[1;1H\e[2J");
    printf("Enter a year to find its calendar (yyyy) : ");
    scanf("%d", &year);
    if (CheckLeap(year)) {
        DaysInMonth[1] = 29;
    }
    CreateDesign(year, today);
    return 0;
}

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

void TodayDate(struct tm *today) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    // Extract day, month, and year
    today -> tm_mday = tm.tm_mday;
    today -> tm_mon = tm.tm_mon;  // Months are 0-based in tm struct
    today -> tm_year = tm.tm_year + 1900;  // Years since 1900

}