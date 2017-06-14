/*******************************************************************************
 * NAME:	    entropy.h
 *
 * AUTHOR:	    Ethan D. Twardy
 *
 * DESCRIPTION:	    Defines types for Source code in entropy.c
 *
 * CREATED:	    06/14/2017
 *
 * LAST EDITED:	    06/14/2017
 ***/

#ifndef __ET_ENTROPY_H__
#define __ET_ENTROPY_H__

/*******************************************************************************
 * TYPE DEFINITIONS
 ***/

typedef union _direction_t_ {

  double value;
  long double dvalue;
  
} direction_t;

/*******************************************************************************
 * API FUNCTION PROTOTYPES
 ***/

extern double entropy_get_entropy(char * string);
extern direction_t entropy_get_direction(double entropy);

#endif /* __ET_ENTROPY_H__ */

/******************************************************************************/
