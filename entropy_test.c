/*******************************************************************************
 * NAME:	    entropy_test.c
 *
 * AUTHOR:	    Ethan D. Twardy
 *
 * DESCRIPTION:	    Test harness for the entropy API.
 *
 * CREATED:	    06/19/2017
 *
 * LAST EDITED:	    06/19/2017
 ***/

/*******************************************************************************
 * INCLUDES
 ***/

#include <stdio.h>

#include "entropy.h"

/*******************************************************************************
 * MAIN
 ***/

int main(int argc, char * argv[])
{

  printf("%f\n", 
	 entropy_get_entropy("The quick brown fox jumped over the lazy dog"));
  
  return 0;
}
