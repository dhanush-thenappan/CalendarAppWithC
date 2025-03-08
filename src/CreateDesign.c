#include <stdio.h>
#include <string.h>
#include <math.h>
#include "CalendarAppWithC.h"
#include "CreateDesign.h"
#include "DayOfDateCalculator.h"

char Months[12][10] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", 
                       "MAY", "JUNE", "JULY", "AUGUST", 
                       "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};

char Days[7] = {'S', 'M', 'T', 'W', 'T', 'F', 'S'};

int DaysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void CreateDesign(int year) {
    int monthCount = 0;
    int minSpace;
    int charCount;
    for(int i = 0; i < TOTAL_MONTHS / MAX_MONTH_LIMIT_PER_ROW; i++, printf("\n\n")) {
            PrintMonthName(&monthCount);
            printf("\n");
            PrintWeekRow();
            printf("\n");
            PrintSeparator();
            printf("\n");
            PrintDates(year, i);
            printf("\n");
    }
}

void PrintMonthName(int *monthCount) {
    int monthLength;
    int charCount;
    int minSpace;
    for(int j = 0; j < MAX_MONTH_LIMIT_PER_ROW; j++, printf("   "), (*monthCount)++) {
        monthLength = strlen(Months[*monthCount]);
        charCount = 0;
        minSpace = (MAX_MONTH_CHAR_LIMIT / 2) - (strlen(Months[*monthCount])/2);
        while(charCount < MAX_MONTH_CHAR_LIMIT) {
            if (charCount < minSpace) {
                printf("_");
                charCount++;
            }
            else if (charCount == minSpace) {
                printf("%s", Months[*monthCount]);
                charCount += strlen(Months[*monthCount]);
            }
            else {
                printf("_");
                charCount++;
            }
        }
    }
}


void PrintWeekRow() {
    for(int i = 0; i < MAX_MONTH_LIMIT_PER_ROW; i++, printf("   ")) {
        printf("|");
        for(int j = 0; j < MAX_DAYS_IN_A_WEEK; j++, printf("|")) {
            printf(" %c ", Days[j]);
        }
    }
}

void PrintSeparator() {
    for(int i = 0; i < MAX_MONTH_LIMIT_PER_ROW; i++, printf("   ")) {
        printf("|");
        for(int j = 0; j < MAX_DAYS_IN_A_WEEK; j++, printf("|")) {
            printf("---");
        }
    }
}

void PrintRowEnd() {
    for(int i = 0; i < MAX_MONTH_LIMIT_PER_ROW; i++, printf("   ")) {
        printf("-");
        for(int j = 0; j < MAX_DAYS_IN_A_WEEK; j++, printf("-")) {
            printf("---");
        }
    }
}

void PrintDates(int year, int startMonth) { // 2025 3
    int DayCount[MAX_MONTH_LIMIT_PER_ROW];
    int over = 0;
    int startDays[MAX_MONTH_LIMIT_PER_ROW];
    for(int i = 0; i < MAX_MONTH_LIMIT_PER_ROW; DayCount[i++] = 1);
    for(int i = 0; i < MAX_MONTH_LIMIT_PER_ROW; i++)
        startDays[i] = dayOfDate(1,(startMonth * MAX_MONTH_LIMIT_PER_ROW)+1+i,year);
    for (int i = 0; i < MAX_MONTH_LIMIT_PER_ROW; i++) {
        if(startDays[i] == 0) {
            startDays[i] = 6;
        }
        else {
            startDays[i] = startDays[i] - 1;
        }
    }
    while (over != (int)(pow(2, MAX_MONTH_LIMIT_PER_ROW) - 1)) {
        printf("|");
        for(int i = 0; i < MAX_MONTH_LIMIT_PER_ROW; i++) {
            for(int j = 0; j < MAX_DAYS_IN_A_WEEK; j++, printf("|")) {
                if (DayCount[i] > DaysInMonth[startMonth*MAX_MONTH_LIMIT_PER_ROW+i]) {
                    over |= (int)pow(2, i);
                    printf("   ");
                }
                else {
                    if(j == startDays[i]) {
                        printf(" %-2d", (DayCount[i])++);
                    }
                    else if(DayCount[i] > 1) {
                        printf(" %-2d", (DayCount[i])++);
                    }
                    else printf("   ");
                }
            }
            if (i != MAX_MONTH_LIMIT_PER_ROW - 1) {
                printf("   ");
                printf("|");    
            }
        }
        printf("\n");
        if(over != (int)(pow(2, MAX_MONTH_LIMIT_PER_ROW) - 1))
            PrintSeparator();
        else
            PrintRowEnd();
        printf("\n");
    }   
}