#include <stdio.h>

int is_run(int year) {
    if (year % 4 == 0)
        if (year % 100 == 0)
            if (year % 400 == 0) return 1;
            else return 0;
        else return 0;
    else return 0;
}

int how_many_day(int year, int month) {
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
            break;
        case 2:
            if (is_run(year)) return 29;
            else return 28;
            break;
        default:
            return -1;
    }

}


int
main(int argc, char **argv) {
    int year, month, day;
    int i;
    int sum = 0;
    while (scanf("%d", &year) == 1) {
        sum = 0;
        getchar();
        scanf("%d", &month);
        getchar();
        scanf("%d", &day);
        for (i = 1; i < month; ++ i) sum += how_many_day(year, i);
        sum += day;
        printf("%d\n", sum);
    }
    return 0;
}
