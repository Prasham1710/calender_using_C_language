#include <stdio.h>
#include <stdlib.h>
int dayNumber(int day, int month, int year)
{
    year -= month < 3;
    return (year + year / 4 - year / 100 + year / 400 + day) % 7;
}
char *getMonthName(int monthNumber)
{
    char *month;
    switch (monthNumber)
    {
    case 0:
        month = "January";
        break;
    case 1:
        month = "February";
        break;
    case 2:
        month = "March";
        break;
    case 3:
        month = "April";
        break;
    case 4:
        month = "May";
        break;
    case 5:
        month = "June";
        break;
    case 6:
        month = "July";
        break;
    case 7:
        month = "August";
        break;
    case 8:
        month = "September";
        break;
    case 9:
        month = "October";
        break;
    case 10:
        month = "November";
        break;
    case 11:
        month = "December";
        break;
    }
    return month;
}
int numberOfDays(int monthNumber, int year)
{
    if (monthNumber == 0 || monthNumber == 2 || monthNumber == 4 || monthNumber == 6 || monthNumber == 7 || monthNumber == 9 || monthNumber == 11)
    {
        return (31);
    }
    else if (monthNumber == 1)
    {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            return (29);
        else
            return (28);
    }
    else
    {
        return (30);
    }
}
void printCalendar(int year)
{
    printf("Calendar - %d\n\n", year);
    int days, i;
    int current = dayNumber(1, 1, year);
    for (i = 0; i < 12; i++)
    {
        days = numberOfDays(i, year);
        printf("\n ------------%s-------------\n",
               getMonthName(i));
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
        int k, j;
        for (k = 0; k < current; k++)
            printf("     ");
        for (j = 1; j <= days; j++)
        {
            printf("%5d", j);
            if (++k > 6)
            {
                k = 0;
                printf("\n");
            }
        }
        if (k)
            printf("\n");
        current = k;
    }
    return;
}
int main()
{
    int year;
    printf("\n        WELCOME        \n");
    printf("  This program helps you to view the Calendar of the whole year\n");
    while (1)
    {
        printf("    MENU\n");
        printf("    Press 1 to Enter the calendar year that you want to see\n");
        printf("    Press 2 to EXIT\n");
        printf("    Enter Selection: ");
        int selection;
        scanf("%d", &selection);
        switch (selection)
        {
        case 1:
            printf("\nselected 1\n");
            printf("\n  Enter the Year of the Calendar that you wish to see : ");
            scanf("%d", &year);
            printCalendar(year);
            break;
        case 2:
            printf("\nselcted 2\nExiting");
            exit(0);
            break;
        default:
            printf("Invalid Input\n");
            break;
        }
    }
    return 0;
}