//-----------------------------------------------------------------------------
// Course: 91.102 Computing II
// Author: Krishnan Seetharaman
// Utility functions
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"

//-----------------------------------------------------------------------------
int die(const char* msg)
// exit routine;
//-----------------------------------------------------------------------------
{
    printf("ERROR: %s\n", msg);
    exit(1);
}

