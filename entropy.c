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

#include "entropy.h"

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
  return 0.0F;
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

/******************************************************************************/
