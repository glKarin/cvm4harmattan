#include "zip_util.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "minizip/unzip.h"

char * unzip_file(const char *file, const char *file_path, int *file_size)
{
#define DIR_DELIMTER '/'
#define MAX_FILENAME 512
#define READ_SIZE 8192
	char *ret;
	uLong i;
	int res;
	char *ptr;
	int size;

	res = UNZ_OK;
	ret = NULL;
	unzFile zipfile = unzOpen(file);
	if(zipfile == NULL)
	{
		fprintf(stderr, "%s: not found\n", file);
		return NULL;
	}

	// Get info about the zip file
	unz_global_info global_info;
	if(unzGetGlobalInfo(zipfile, &global_info) != UNZ_OK)
	{
		fprintf(stderr, "could not read file global info\n");
		goto _Exit;
	}

	// Buffer to hold data read from the zip file.

	// Loop to extract all files
	char filename[MAX_FILENAME];
	for (i = 0; i < global_info.number_entry; ++i)
	{
		// Get info about current file.
		unz_file_info file_info;
		if (unzGetCurrentFileInfo(
					zipfile,
					&file_info,
					filename,
					MAX_FILENAME,
					NULL, 0, NULL, 0 ) != UNZ_OK)
		{
			fprintf(stderr, "could not read file info\n");
			goto _Exit;
		}

		// Check if this entry is a directory or file.
		const size_t filename_length = strlen(filename);
		if(filename[filename_length - 1] == DIR_DELIMTER)
		{
			//printf("dir:%s\n", filename);
		}
		else
		{
			//printf("file:%s\n", filename);
			if(strcmp(filename, file_path) == 0) // found
			{
				if(unzOpenCurrentFile(zipfile) != UNZ_OK)
				{
					fprintf(stderr, "could not open file\n");
					goto _Exit;
				}

				if(!file_info.uncompressed_size)
				{
					goto _Exit;
				}
				size = file_info.uncompressed_size;
				ret = (char *)malloc(size);
				ptr = ret;
				char read_buffer[READ_SIZE];
				do    
				{
					res = unzReadCurrentFile(zipfile, read_buffer, READ_SIZE);
					if ( res < 0 )
					{
						fprintf(stderr, "error %d\n", res);
						unzCloseCurrentFile(zipfile);
						free(ret);
						ret = NULL;
						goto _Exit;
					}
					else if (res > 0)
					{
						memcpy(ptr, read_buffer, res);
						ptr += res;
					}
				} while (res > 0);

				unzCloseCurrentFile(zipfile);
				goto _Suc;
			}
		}

		// Go the the next entry listed in the zip file.
		if((i + 1) < global_info.number_entry)
		{
			if(unzGoToNextFile(zipfile) != UNZ_OK)
			{
				fprintf(stderr, "cound not read next file\n");
				goto _Exit;
			}
		}
	}

_Suc:
	if(file_size)
		*file_size = size;

_Exit:
	unzClose(zipfile);
	return ret;
#undef DIR_DELIMTER
#undef MAX_FILENAME
#undef READ_SIZE
}

