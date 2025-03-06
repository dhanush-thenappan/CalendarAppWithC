#include <string.h>
#include <stdio.h>
#include "UI.h"

  
void PrintMonths(int Month, int cc) {
    char MonthNames[3][9] = {"January", "February", "March"};  
    int MonLen = strlen(MonthNames[Month]);
    // printf("\n%d\n", MonLen);
    int startMon = (29/2) - (MonLen/2);
    for(int i=0;i<startMon;i++, printf("_"));
    printf("%s", MonthNames[Month]);
    for(int i=0;i<startMon;i++, printf("_"));
    if (cc<2)
        printf("___");
}
void PrintDays() {
    char Days[] = {'S', 'M', 'T', 'W', 'T', 'F', 'S'};
    for(int i=0;i<7;i++) {
        printf("%3c|", Days[i]);
    }
    printf("   ");
}
void PrintEmptyLine(int cc) {
    for (int j=0;j<7;j++) {
        printf("---+");
    }
    if(cc<2)
        printf("---+");
}
void PrintRows() {
    
}
void CreateCalendarDesign() {
    int count = 1;
    
    for(int i=0;i<3;i++) {
        PrintMonths(i, i);
    }
    printf("_\n");
    for(int i=0;i<3;i++) {
        printf("|");
        PrintDays();
    }
    printf("\n|");
    for(int i=0;i<3;i++) {
        PrintEmptyLine(i);
    }
    printf("|\n");
    printf("|");
    for (int i=0;i<4;i++, printf("\n|")) {
        for (int j=0;j<7;j++) {
            printf("%3d|", count++);
        }
        printf("\n+");

        for (int j=0;j<7;j++) {
            printf("---+");
        }
    }
}