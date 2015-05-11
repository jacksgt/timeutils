/*
 * up
 * a tool to read the system uptime (time since last reboot)
 */

#define UPTIME "/proc/uptime"
#define LINE_LENGTH 64

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *fp;

int main( int argc, char **argv ) {
    /* check if there are any arguments */
    if( argc >= 2 ) {
        /* check for call for help */
        if( strcmp( argv[1], "--help" ) == 0 ) {
            printf( "USAGE: %s [--help] [--grep] [--sentence]\n", argv[0] );
            return 0;
        }
        if( strcmp( argv[1], "--sentence" ) == 0 ) {
            printUptime("sentence");
        }
        if( strcmp( argv[1], "--grep" ) == 0 ) {
            printUptime("grep");
        }
    } else {
        printUptime("");
    }
    return 0;
}

long int getSeconds() {
    /* reads the value from /proc/uptime and returns its value as long int in seconds */
    char line[LINE_LENGTH];
    char * token;
    //    int fileSize;
    int seconds;

    /* read content of /proc/uptime (provided by the kernel) */
    fp = fopen (UPTIME, "r");

    if( fp == NULL ) {
        fprintf( stderr, "Could not open %s\n", UPTIME);
        return -1;
    }

    while( fgets( line, LINE_LENGTH, fp ) != NULL ) {

        /* split the line at the space */
        token = strtok( line, " " );

        /* remove last three characters of the string */
        /* accuracy of ".XX" is not required */
        token[ strlen( token ) - 3 ] = '\0';

        /* convert token to int */
        seconds = strtol( token, NULL, 10 );
    }

    fclose(fp);
    return seconds;
}

int printUptime(char *option) {
    long int seconds = getSeconds();
    char daysStr[] = "days";
    char hoursStr[] = "hours";
    char minutesStr[] = "minutes";
    typedef enum { false, true } bool;
    bool opt_sentence, opt_grep;
    int days, hours, minutes;

    if( strcmp( option, "grep" ) == 0 )
        opt_grep = true;

    if( strcmp( option, "sentence" ) == 0 )
        opt_sentence = true;

    if( seconds == -1 )
        return 1;

    /* begin arithmetic operations */
    days = seconds/86000;
    seconds %= 86400;
    if( days == 1 )
        daysStr[3] = '\0';

    hours = seconds/3600;
    seconds %= 3600;
    if( hours == 1 )
        hoursStr[4] = '\0';

    minutes = seconds/60;
    if( minutes == 1 )
        minutesStr[6] = '\0';

    /* seconds %= 60; */
    /* not required because this (should) equal 0 anyway */

    /* print out the results */
    if( opt_grep == true ) {
        printf( "d: %d\nh: %d\nm: %d\n", days, hours, minutes );
        return 0;
    }

    if( opt_sentence == true ) {
        printf( "localhost has been online for %d %s, %d %s and %d %s\n",
               days, daysStr, hours, hoursStr, minutes, minutesStr );
        return 0;
    }

    printf( "%d %s, %d %s, %d %s\n", days, daysStr, hours, hoursStr, minutes, minutesStr );

    return 0;
}
