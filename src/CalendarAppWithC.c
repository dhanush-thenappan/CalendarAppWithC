#include <stdio.h>
#include "CalendarAppWithC.h"
#include "DayOfDateCalculator.h"


int main(void) {
    int day, month, year;
    char days[7][10] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    printf("Enter date to find day (dd-mm-yyyy) : ");
    scanf("%d-%d-%d", &day, &month, &year);
    printf("%s\n",days[dayOfYear(day, month, year)]);
    return 0;
}