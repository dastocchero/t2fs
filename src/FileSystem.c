#include "FileSystem.h"
#include <"t2fs.h">
#include <"FilePath.h">


#include <stdlib.h>
#include <string.h>
#include <assert.h>

FileSystem fileSystem;




int FS_initialize();
FILE2 FS_create(char *filename, int TypeVal){

    FilePath filePath;
    FP_FilePath(&filePath, filename);






}
int FS_delete(char *filename, int TypeVal);
