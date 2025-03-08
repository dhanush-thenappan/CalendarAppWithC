#include <stdio.h>
#include "CalendarAppWithC.h"
#include "DayOfDateCalculator.h"
#include "CreateDesign.h"

int main(void) {
    int year = 0;
    printf("\e[1;1H\e[2J");
    printf("Enter a year to find its calendar (yyyy) : ");
    scanf("%d", &year);
    if (CheckLeap(year)) {
        DaysInMonth[1] = 29;
    }
    CreateDesign(year);
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
