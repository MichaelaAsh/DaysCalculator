#include <stdio.h>
#include <stdlib.h>
 /* The user inputs the start date and end date on the command line
 and the program outputs the number of days excluding the end date */

int main ( int argc, char *argv[] ) {

  int monthLength[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  char *month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September","October", "November", "December" };
  int Dayyear[12] = {1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 };

  int dd1 = 0;
  int mm1 = 0;
  int yyyy1 = 0;

  int dd2 = 0;
  int mm2 = 0;
  int yyyy2 = 0;

  int num;

  if (argc < 7) {

      printf ( "Usage: ./StageA dd1 mm1 yyyy1  dd2 mm2 yyyy2 \n" );
       exit ( 1 );
    } else {
       dd1 = atoi ( argv[1] );
       mm1 = atoi ( argv[2] );
       yyyy1 = atoi ( argv[3] );
       dd2 = atoi (argv[4]);
       mm2 = atoi (argv[5]);
       yyyy2 = atoi (argv[6]);

}

  num = ((Dayyear[mm2-1]+ (dd2-1)) - (Dayyear[mm1-1]+(dd1-1)));

 /* Range restriction for month and days*/
  if ( dd1  < 0 || dd1 > monthLength[mm1-1]  ) {

     printf ("Error - you entered %02d for the day and that is not in the range (1-%02d)\n", dd1, monthLength[mm1-1]);

     return(-1);
  }
    if ( dd2 < 0 || dd2  > monthLength[mm2-1] ) {

       printf ("Error - you entered %02d for the day and that is not in the range (1-%02d) \n", dd2, monthLength[mm2-1]);

       return(-1);
    }

  if ( mm1 < 0 || mm1 > 12) {

      printf ("Error - the month entered %02d is not in the proper range (1-12)\n", mm1);

      return ( -1);
   }


 /* Check to see if the end date that user puts in appears before the start date */
 if (num < 0) {

     printf("Error, the date %02d %02d %04d comes before %02d %02d %04d \n", dd2, mm2, yyyy2, dd1, mm1, yyyy1);
     return (-1);

   } else {

      num = ((Dayyear[mm2-1]+ (dd2-1)) - (Dayyear[mm1-1]+(dd1-1)));
      printf ("%d\n", num);

}

 if (num == 0) {
    printf("Your end date %02d %02d %04d is the same date as your start date %02d %02d %04d \n", dd2, mm2, yyyy2, dd1, mm1, yyyy1);

}

  return(0);

}
