#include <stdio.h>
#include <string.h>
#include "CalendarAppWithC.h"
#include "CreateDesign.h"
#include "DayOfDateCalculator.h"

char Months[12][10] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", 
                        "MAY", "JUNE", "JULY", "AUGUST", 
                        "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};

void CreateDesign() {
    int monthCount = 0;
    int minSpace;
    int charCount;
    for(int i=0;i<4;i++, printf("\n")) {
            PrintMonthName(&monthCount);
    }
}

int PrintMonthName(int *monthCount) {
    int monthLength;
    int charCount;
    int minSpace;
    for(int j=0;j<3;j++, printf("   "), (*monthCount)++) {
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