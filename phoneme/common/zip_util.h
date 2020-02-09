#ifndef _KARIN_ZIP_UTIL_H
#define _KARIN_ZIP_UTIL_H

#ifdef __cplusplus
extern "C" {
#endif

	char * unzip_file(const char *file, const char *file_path, int *file_size);

#ifdef __cplusplus
}
#endif

#endif
