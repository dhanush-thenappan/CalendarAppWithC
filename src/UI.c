#include <string.h>
#include <stdio.h>
#include "UI.h"

void CreateCalendarDesign() {
    int count = 1;
    char Days[] = {'S', 'M', 'T', 'W', 'T', 'F', 'S'};
    char Month[] = "January";
    int MonLen = strlen(Month);
    int startMon = (29/2) - (MonLen/2);
    for(int i=0;i<startMon;i++, printf("-"));
    printf("%s", Month);
    for(int i=0;i<startMon;i++, printf("-"));
    printf("\n");
    printf("|");
    for(int i=0;i<7;i++) {
        printf("%3c|", Days[i]);
    }
    printf("\n+");
    for (int j=0;j<7;j++) {
        printf("---+");
    }
    printf("\n");
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