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
  long double lvalue;
  
} direction_t;

typedef struct _entropy_vector_ {

  unsigned int length;
  direction_t direction;

} entropy_vector_t;

/*******************************************************************************
 * API FUNCTION PROTOTYPES
 ***/

extern double entropy_get_entropy(char *);
extern direction_t entropy_get_direction(double);

#endif /* __ET_ENTROPY_H__ */

/******************************************************************************/
