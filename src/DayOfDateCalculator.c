#include "DayOfDateCalculator.h"
/*
Function name: dayOfYear()
Return type: int
Parameters: int day, int month, int year
Process: Calculates the day of the date specified by the user using Zeller's congruence.
Zeller's congruence: h = (d + (13(m+1)/5) + k + k/4 + j/4 + 5j) % 7
Where,
    h = Day of the week (0-> Saturday, 1-> Sunday, 2-> Monday, 3-> Tuesday, 4-> Wednesday, 5-> Thursday, 6-> Friday)
    d = date of the month
    m = month (3 -> March, 4 -> April, 5 -> May, ... 13 -> January, 14 -> February)
    k = Last 2 digits of the year (Eg. If year is 1896, k = 96)
    j = First 2 digits of the year (Eg. If year is 1896, k = 18)
If month is January or February, then day is calculated by subtracting the year by 1.
This function returns the value of h.
*/
int dayOfDate(int day, int month,int year) {
    int dayOfdate = 0;
    int K;
    int J;
    if (year / 1000 == 0) {
        year += 2000;
    }
    if (month == 1 || month == 2) {
        month += 12;
        year -= 1;
    }
    K = year % 100;
    J = year / 100;
    dayOfdate = (day + (13 * (month + 1) / 5) + K + (K / 4) + (J / 4) + (5 * J)) % 7; // Calculate day using Zeller's congruence
    return dayOfdate;
}