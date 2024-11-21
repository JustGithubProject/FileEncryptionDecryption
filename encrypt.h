#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <stdlib.h>

#include "data_block.h"


unsigned char* getBytesOfFile(const char* filename);


void encryptFileAES(const unsigned char* key, const char* inputFile, const char* outputFile);

#endif // ENCRYPT_H