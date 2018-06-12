#ifndef FILESYSTEM_H_INCLUDED
#define FILESYSTEM_H_INCLUDED

#include <"t2fs.h">
#include <"FilePath.h">


int populate_dir_struct_from_block(int block);
int update_open_files(int inode_number, BYTE type);
int check_open_file(int inode);
int create_inode_write_to_disk(int freeblock, int freeinode);
int create_record_write_to_disk(int freeblock, int freeinode, char* filename, BYTE type);
int find_record_in_blockbuffer(REC_t* auxrecord, BYTE type, char* filename);
int find_free_record_in_blockbuffer(REC_t* auxrecord);
int get_block_from_inode(INO_t* newinode, int inode);
int delete_record_from_buffer(char* filename);
int read_all_records_in_blockbuffer(int block, DIRENT2* dirent);




#endif // FILESYSTEM_H_INCLUDED
