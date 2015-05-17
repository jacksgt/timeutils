/* functions for reading and writing to and from files */

#ifndef FILEIO_H
#define FILEIO_H

#define RUNTIME "./runtime-data"
#define UPTIME "/proc/uptime"
#define MAX_LINE_LENGTH 64

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fp;

/* reads uptime from UPTIME */
/* returns uptime in seconds as integer */
/* returns -1 on failure */
long int readUptime();

/* reads runtime from RUNTIME */
/* returns runtime in seconds as integer */
/* returns -1 on failure*/
long int readRuntime();

/* writes given long int runtime into RUNTIME */
/* returns 0 on success */
/* returns -1 on failure */
long int writeRuntime( long int runtime );

#endif
