#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <stdlib.h>
#include <stdio.h>

unsigned char* getBytesOfFile(const char* filename, int* fileSize);

void writeBytesToFile(unsigned char* buffer, const char* outputFile, int size);

void encryptFileXOR(const char* inputFile);

#endif // ENCRYPT_H