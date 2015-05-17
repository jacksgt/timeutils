/*
* 'runtime' should monitor and manage the total runtime of the system
* That is all the uptime combined
*/

#include "fileio.h"
#include <signal.h>
#include <unistd.h>

/* this function saves the current value of runtime to RUNTIME */
/* it will be called when the program exists, ideally when the system shuts down */
void saveRuntime(int sigInt) {
    /* read from UPTIME */
    long int uptime = readUptime();
    if ( uptime == -1 )
        uptime = 0;

    /* read from RUNTIME */
    long int oldRuntime = readRuntime();
    if ( oldRuntime == -1 )
        oldRuntime = 0;

    /* combine values of uptime and old runtime */
    long int runtime = uptime + oldRuntime;

    /* write new value to RUNTIME */
     if( writeRuntime( runtime ) != 0 ) {
         fprintf( stderr, "Could not write to %s\n", RUNTIME );
     }

     exit(0);
}

int main() {
  /* read from UPTIME */
  long int uptime = readUptime();
  if ( uptime == -1 ) {
    fprintf( stderr, "Could not open %s\n", UPTIME );
    uptime = 0;
  }

  /* read from RUNTIME */
  long int oldRuntime = readRuntime();
  if ( oldRuntime == -1 ) {
    fprintf( stderr, "Could not open %s\n", RUNTIME );
    oldRuntime = 0;
  }

  /* combine values of uptime and old runtime */
  long int runtime = uptime + oldRuntime;

  /* debug: */
  printf( "uptime: %ld, oldRuntime: %ld, runtime: %ld\n", uptime, oldRuntime, runtime );

  signal( SIGTERM, saveRuntime );
  signal( SIGINT, saveRuntime );
  signal( SIGQUIT, saveRuntime );

  /* halt the program */
  while(1) {
      pause();
  }

  exit( 0 );
}