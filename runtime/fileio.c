#include "fileio.h"

long int readUptime() {
  char line[MAX_LINE_LENGTH];
  char *token;
  int seconds;

  /* read content of /proc/uptime (provided by the kernel) */
  fp = fopen ( UPTIME, "r" );

  if( fp == NULL ) {

    return -1;
  }

  while( fgets( line, MAX_LINE_LENGTH, fp ) != NULL ) {

    /* split the line at the space */
    token = strtok( line, " " );

    /* remove last three characters of the string */
    /* accuracy of ".XX" is not required */
    token[ strlen(token) - 3 ] = '\0';

    /* convert token to int */
    seconds = strtol( token,NULL,10 );
  }

  fclose(fp);
  return seconds;
}

long int readRuntime() {
  char line[MAX_LINE_LENGTH];
  int seconds;

  fp = fopen( RUNTIME, "r" );

  if( fp == NULL )
    return -1;

  while( fgets( line, MAX_LINE_LENGTH, fp ) != NULL ) {
    seconds = strtol( line,NULL,10 );
  }

  fclose( fp );
  return seconds;
}

long int writeRuntime( long int runtime ) {
  // convert long int to char array
  char line[MAX_LINE_LENGTH];
  sprintf( line, "%ld\n", runtime );

  /* open RUNTIME and check for errors */
  fp = fopen( RUNTIME, "w" );
  if( fp == NULL )
    return -1;

  /* write string to RUNTIME */
  fputs( line, fp );
  fclose( fp );

  return 0;
}
