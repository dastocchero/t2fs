#include "FilePath.h"

#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "t2fs.h"


int path_parser(char* path, char* pathfound)
{
  char* token;
  char aux[2048];
  strcpy(aux, path);

  // printf ("[path_parser] caminho: \"%s\"\n", path);

  int char_size = 1;
  token = strtok (aux, "/");
  while (token != NULL)
  {
    token = strtok (NULL, "/");
    ++char_size;
  }

  const char *paths[char_size];
  strcpy(aux, path);

  char_size = 0;
  token = strtok (aux, "/");
  while (token != NULL)
  {
    // printf("token: %s\n", token);
    paths[char_size] = token;
    ++char_size;
    token = strtok (NULL, "/");
  }

  strcpy(pathfound, paths);
  return char_size;
}


int path_exists(char* filename, int type)
{
  if(!filename)
  {
    return ERROR;
  }

  char *path[25];
  int dirs = path_parser(filename, &path);

  // printf("[path_exists] possiveis diretorios: %d  ", dirs);
  int i;
  for (i = 0; i < dirs; ++i)
  {
    // printf(">> %s  ", path[i]);
  }

  i = 0;
  int encontrou = 0;
  // printf("Comecando em %s\n", current_dir->name);

  DIR_t* found;

  char* searching_for1;
  char* searching_for1_father;
  char* searching_for2;

  int iterator;
  for (iterator = 0; iterator < dirs; ++iterator)
  {
    do
    {
      searching_for1 = path[i];
      searching_for1_father = current_dir->pai->name;
      searching_for2 = current_dir->name;
      found = current_dir->pai;
      // printf("\n[path_exists] procurando por: %s dentro de %s ...\n", searching_for1, searching_for1_father);
      if (strcmp(searching_for1, searching_for2) == 0)
      {
        encontrou = 1;
        break;
      }
      current_dir = current_dir->irmao;
      // printf("%s\n", current_dir->name);
    } while(current_dir);

    if (encontrou == 0)
    {
      // printf("[path_exists] %s nao e um diretorio\n", path[i]);
      if (!current_dir)
      {
        current_dir = found;
      }
      if (type == 1 || i+1 < dirs)
      {
        return ERROR;
      }

      int foundinode = get_file_inode(path[i]);
      return foundinode;

    } else if (iterator < dirs) // current_dir->filho == NULL &&
      {
        // printf("\n[path_exists] \"%s\" encontrado!\n", searching_for1);
        if (!current_dir->filho)
        {
            // printf("[path_exists] e nao tem subdiretorios\n");
          if (!current_dir)
          {
            current_dir = found;
          }
          if (i+1 == dirs)
          {
            return -2;
          } else if ((i+2) < dirs)
            {
              return -3;
            }
          if (type == 1)
          {
            return SUCCESS;
          }
          char* newpath = path[i+1];
          int foundinode = get_file_inode(newpath);
          return foundinode;
        }
      }

      if (strcmp(current_dir->name, searching_for1) == 0 && i+1 == dirs)
      {
        return SUCCESS;
      }

    encontrou = 0;
    i++;
    current_dir = current_dir->filho;
  }

  printf("\n\n");
  return ERROR;
}
