/*
 *
 *
 * ██╗    ██╗ ██████╗ ██╗████████╗███████╗██╗  ██╗
 * ██║    ██║██╔═══██╗██║╚══██╔══╝██╔════╝██║ ██╔╝
 * ██║ █╗ ██║██║   ██║██║   ██║   █████╗  █████╔╝
 * ██║███╗██║██║   ██║██║   ██║   ██╔══╝  ██╔═██╗
 * ╚███╔███╔╝╚██████╔╝██║   ██║   ███████╗██║  ██╗
 *  ╚══╝╚══╝  ╚═════╝ ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝
 *
 *
 *
 *  ______
 * /\  ___\
 * \ \ \____
 *  \ \_____\
 *   \/_____/
 *
 *
 *
 * Program for performing simple operations involving dates.
 *
 *
 */

#include <stdio.h>

/* Definition of the "month" data type. */
typedef enum month
{
    JAN = 1,
    FEB = 2,
    MAR = 3,
    APR = 4,
    MAY = 5,
    JUN = 6,
    JUL = 7,
    AUG = 8,
    SEP = 9,
    OCT = 10,
    NOV = 11,
    DEC = 12
}
month;

/* Definition of the "date" data type. */
typedef struct date
{
    month m;
    unsigned short int d;
}
date;

/* Function that receives a "month" variable, and returns a string containing the
   name of the corresponding month. */
const char* month_name(month m)
{
    switch (m) {
        case JAN:
            return "January";
        case FEB:
            return "February";
        case MAR:
            return "March";
        case APR:
            return "April";
        case MAY:
            return "May";
        case JUN:
            return "June";
        case JUL:
            return "July";
        case AUG:
            return "August";
        case SEP:
            return "September";
        case OCT:
            return "October";
        case NOV:
            return "November";
        case DEC:
            return "December";
    }
}

/* Function that receives a "month" variable, and returns the number of days in
   the corresponding month. */
unsigned short int num_days(month m)
{
    switch (m) {
        case JAN:
            return 31;
        case FEB:
            return 28;
        case MAR:
            return 31;
        case APR:
            return 30;
        case MAY:
            return 31;
        case JUN:
            return 30;
        case JUL:
            return 31;
        case AUG:
            return 31;
        case SEP:
            return 30;
        case OCT:
            return 31;
        case NOV:
            return 30;
        case DEC:
            return 31;
    }
}

/* Function that receives a "date" variable, and returns another "date"
   variable. The output "date" corresponds to the day that follows the one
   associated with the input "date". */
date next_day(date dt)
{
    unsigned short int ndays;
    date nxt_dt;
    month temp1;
    unsigned short int temp2;

    temp1 = dt.m;
    temp2 = dt.d;
    ndays = num_days(temp1);
    if (temp2 < ndays) {
        nxt_dt.m = temp1;
        nxt_dt.d = temp2 + 1;
    } else {
        nxt_dt.m = (temp1 + 1) % 12;
        nxt_dt.d = 1;
    }
    return nxt_dt;
}

/* Function that receives a "date" variable, and prints the corresponding date. */
void print_date(date dt)
{
    printf("%s %hu\n", month_name(dt.m), dt.d);
    return;
}

int main()
{

    date dt1, dt2;

    /* Prints the dates mentioned in the instructions for this assignment. */

    dt1.m = JAN;
    dt1.d = 1;
    print_date(dt1);
    dt2 = next_day(dt1);
    print_date(dt2);
    printf("\n");

    dt1.m = FEB;
    dt1.d = 28;
    print_date(dt1);
    dt2 = next_day(dt1);
    print_date(dt2);
    printf("\n");

    dt1.m = MAR;
    dt1.d = 14;
    print_date(dt1);
    dt2 = next_day(dt1);
    print_date(dt2);
    printf("\n");

    dt1.m = OCT;
    dt1.d = 31;
    print_date(dt1);
    dt2 = next_day(dt1);
    print_date(dt2);
    printf("\n");

    dt1.m = DEC;
    dt1.d = 31;
    print_date(dt1);
    dt2 = next_day(dt1);
    print_date(dt2);

    return 0;

}
