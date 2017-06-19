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

struct char_count {
  /* Scoped definition of the incomplete type defined
   * in entropy.h. Aren't I sneaky? */
  char c;		
  int count;
} *pStruct;

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

static int count_char(char * string, struct char_count ** count)
{

  char chars[strlen(string)];
  char * c = string;

  /* Create an array with the scope of the characters in the string. */
  while (*c != '\0') {

    int i;
    for (i = 0; i < strlen(chars); i++)
      if (*c == chars[i])
	goto _continue;

    chars[++i] = *c;

    _continue:
	c++;
    }
  /* ...Done. */

  *count = (struct char_count *)calloc(strlen(chars) - 1,
				       sizeof(struct char_count));

  for (int i = 0; i < strlen(chars) - 1; i++) {
    /* We use strlen(chars) - 1 because we don't care about '\0.' */

    (*count)[i].c = chars[i];
    (*count)[i].count = 0;

    for (int j = 0; j < strlen(chars); j++)
      if (chars[j] == (*count)[i].c)
	(*count)[i].count++;

  }

  return 0;
}

static double entropy_of_char(struct char_count * victim, int len_of_str)
{
  double ret = 0.0F;
  double buff = 0.0F;

  buff = (double)(victim->count / len_of_str);
  ret = log2(buff);
  ret *= -1.0 * victim->count;
  return ret;
}

/******************************************************************************/
