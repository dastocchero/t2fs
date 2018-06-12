#include "../include/t2fs.h"
#include "../include/bitmap2.h"
#include "../include/apidisk.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <BlockManagement.h>

int read_block(int sector)
{
  int i;
  int x = 0;
  for (i = 0; i < 16; ++i)
  {
    if(read_sector(sector + i, buffer) != 0)
        return ERROR;
    memcpy((blockbuffer + x), buffer, sizeof(buffer));
    x = x + 256;
  }

  return SUCCESS;
}

int write_block(int sector)
{
  int i;
  int x = 0;
  for (i = 0; i < 16; ++i)
  {
    memcpy(buffer, (blockbuffer + x), sizeof(buffer));
    if(write_sector(sector + i, buffer) != 0)
        return ERROR;
    x = x + 256;
  }

  return SUCCESS;
}
