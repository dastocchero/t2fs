#ifndef BLOCKMANAGEMENT_H_INCLUDED
#define BLOCKMANAGEMENT_H_INCLUDED

#include "../include/t2fs.h"
#include "../include/bitmap2.h"
#include "../include/apidisk.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>






int read_block(int sector);
int write_block(int sector);


#endif // BLOCKMANAGEMENT_H_INCLUDED
