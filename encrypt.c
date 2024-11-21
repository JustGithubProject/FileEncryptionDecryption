#include "encrypt.h"

unsigned char* getBytesOfFile(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    // Size of file
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    // TODO(JustGithubProject): Read bytes from a file and store them in an array.
}


void encryptFileAES(const unsigned char* key, const char* inputFile, const char* outputFile) {
    
}