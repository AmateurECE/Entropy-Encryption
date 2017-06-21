/*******************************************************************************
 * NAME:	    entropy.c
 *
 * AUTHOR:	    Ethan D. Twardy
 *
 * DESCRIPTION:	    Source code defining the functions declared in entropy.c.
 *		    These functions allow the user to get the entropy and
 *		    direction of a string in vector form.
 *
 * CREATED:	    06/15/2017
 *
 * LAST EDITED:	    06/15/2017
 ***/

/*******************************************************************************
 * INCLUDES
 ***/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "entropy.h"

/*******************************************************************************
 * LOCAL FUNCTION PROTOTYPES
 ***/

static int count_char(char *, struct char_count **);
static double entropy_of_char(struct char_count *, int);

/*******************************************************************************
 * GLOBAL VARIABLES
 ***/

static struct char_count {
  /* Incomplete type defined in entropy.h.
   * Aren't I sneaky? */
  char c;		
  int count;
} * pStruct = NULL; /* NOTE: This structure is now initialized to NULL. */

/*******************************************************************************
 * API FUNCTIONS
 ***/

/*******************************************************************************
 * FUNCTION:	    entropy_get_entropy
 *
 * DESCRIPTION:	    Returns the entropy of a string to the user.
 *
 * ARGUMENTS:	    string: (char *) -- the string whose entropy is in question.
 *
 * RETURN:	    double -- the entropy of the string.
 *
 * NOTES:	    Returns 0F if there is an error.
 ***/
double entropy_get_entropy(char * string)
{
  int numchars;
  double entropy = 0.0F;

  if (string == NULL || strlen(string) == 0)
    return 0.0F;

  count_char(string, &pStruct);
  numchars = sizeof(pStruct) / sizeof(struct char_count);

  for (int i = 0; i < numchars; i++)
    entropy += entropy_of_char(&(pStruct[i]), strlen(string));

  /* In the above function call, we can use strlen() because we are NOT looking
   * for a zero-indexed size. */

  return entropy;
}

/*******************************************************************************
 * FUNCTION:	    entropy_get_direction
 *
 * DESCRIPTION:	    Returns the direction of the entropy of the string in
 *		    question according to the ordering method. Direction is a
 *		    value between 0 and 2(pi).
 *
 * ARGUMENTS:	    entropy: (double) -- the entropy of the string in question.
 *
 * RETURN:	    direction_t -- the direction of the string in question.
 *
 * NOTES:	    Returns 0F if there is an error.
 ***/
direction_t entropy_get_direction(double entropy)
{
  return (direction_t)0.0L;
}

/*******************************************************************************
 * LOCAL FUNCTIONS
 ***/

/*******************************************************************************
 * FUNCTION:	    count_char
 *
 * DESCRIPTION:	    Static function that gets the scope of the string (An array
 *		    containing one copy of each of the letters found in the
 *		    string) and a count of how many times each letter appears.
 *
 * ARGUMENTS:	    string: (char *) -- the string in question.
 *		    count: (struct char_count **) -- array of char_count objects
 *			is placed here after function call.
 *
 * RETURN:	    int -- 0 on success, -1 otherwise.
 *
 * NOTES:	    This function has static linkage.
 ***/
static int count_char(char * string, struct char_count ** count)
{

  char scope[strlen(string)];
  char * c = string;

  /* Create an array with the scope of the characters in the string. */
  while (*c != '\0') {

    int i;
    for (i = 0; i < strlen(scope); i++)
      if (*c == scope[i])
	goto _continue;

    scope[strlen(scope)] = *c;

    _continue:
	c++;
    }
  /* ...Done. */

  *count = (struct char_count *)calloc(strlen(scope),
				       sizeof(struct char_count));

  for (int i = 0; i < strlen(scope); i++) {

    (*count)[i].c = scope[i];
    (*count)[i].count = 0;

    for (int j = 0; j < strlen(scope); j++)
      if (scope[j] == (*count)[i].c)
	(*count)[i].count++;

  }

  return 0;
}

/*******************************************************************************
 * FUNCTION:	    entropy_of_char
 *
 * DESCRIPTION:	    Returns the entropy of all instances of a given character
 *		    in a string.
 *
 * ARGUMENTS:	    scope: (struct char_count *) -- char_count object containing
 *			the char and number of times it appears.
 *		    len_of_str: (int) -- the length of the string up to, but not
 *			including, the null character.
 *
 * RETURN:	    double -- the entropy of all instances of the character in
 *			the string.
 *
 * NOTES:	    This function has static linkage.
 ***/
static double entropy_of_char(struct char_count * scope, int len_of_str)
{
  double ret = 0.0F;

  ret = log2((scope->count / (len_of_str + 0.0)));
  ret *= -1.0 * scope->count;
  return ret;
}

/******************************************************************************/
