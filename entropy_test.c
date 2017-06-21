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
#include <stdlib.h>

#include "entropy.h"

/*******************************************************************************
 * STATIC FUNCTION PROTOTYPES
 ***/

static inline _Noreturn void error_exit(char * msg);

/*******************************************************************************
 * MAIN
 ***/

int main(int argc, char * argv[])
{

  if (argc < 2)
    error_exit("Not enough arguments!");

  printf("Entropy of String \"%s\":\n%f\n",
	 argv[1],
	 entropy_get_entropy(argv[1]));
  
  return 0;
}

/*******************************************************************************
 * STATIC FUNTIONS
 ***/

static inline _Noreturn void error_exit(char * msg)
{
  fprintf(stderr, "%s\n", msg);
  exit(1);
}

/******************************************************************************/
