#include "encrypt_decrypt.h"

unsigned char* getBytesOfFile(const char* filename, int* fileSize) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Failed to open file");
        return NULL;
    }

    // Size of file
    fseek(file, 0, SEEK_END);
    *fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);


    // Allocating memory to store bytes of file
    unsigned char *buffer = (unsigned char*)malloc((*fileSize) * sizeof(unsigned char));
    if (buffer == NULL) {
        perror("Failed to allocate memory");
        fclose(file);
        return NULL;
    }


    // Reading file in array
    size_t bytesRead = fread(buffer, sizeof(unsigned char), (*fileSize), file);
    if (bytesRead != (*fileSize)) {
        perror("Failed to read file");
        free(buffer);
        fclose(file);
        return NULL;
    }

    fclose(file);

    return buffer;
}


void writeBytesToFile(unsigned char* buffer, const char* outputFile, int size) {
    FILE* file = fopen(outputFile, "w");
    if (file == NULL) {
        perror("Failed to open file");
        free(buffer);
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%c", buffer[i]);
    }

    fclose(file);
    free(buffer);
}


void encryptFileXOR(const char* inputFile) {
    int inputFileSize;
    int keyFileSize;
    /*
        Getting the bytes of the file you
        want to encrypt and the file with the key
    */ 
    unsigned char* inputFileBytes = getBytesOfFile(inputFile, &inputFileSize);
    unsigned char* keyFileBytes = getBytesOfFile("key.txt", &keyFileSize);

    for (int i = 0; i < inputFileSize; i++) {
        inputFileBytes[i] = inputFileBytes[i] ^ keyFileBytes[i % keyFileSize]; 
    }

    writeBytesToFile(inputFileBytes, inputFile, inputFileSize);
}