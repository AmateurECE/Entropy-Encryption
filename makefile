################################################################################
# NAME:		    makefile
#
# AUTHOR:	    Ethan D. Twardy
#
# DESCRIPTION:	    Makefile for entropy API and test harness.
#
# CREATED:	    06/19/2017
#
# LAST EDITED:	    06/19/2017
###


OBJS = entropy.c entropy_test.c
CFLAGS = -g -Wall -O0
LDLIBS=

entropy: $(OBJS)

.PHONY: clean

clean:
	rm -rf *.c~
	rm -rf *.h~
	rm -rf makefile~

################################################################################
