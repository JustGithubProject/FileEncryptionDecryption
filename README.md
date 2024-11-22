# XOR Encryption and Decryption Program

This program performs file encryption and decryption using XOR encryption. It requires the following files:

1. **key.txt** – Contains the key for XOR encryption/decryption.
2. **input.txt** – The file that will be encrypted or decrypted.

## Requirements

- **GCC Compiler**: Ensure that you have GCC installed to compile the program.

## Program Overview

The program uses XOR encryption to secure the contents of the `input.txt` file. It will read the key from `key.txt` and then either encrypt or decrypt the `input.txt` file based on your input.

## File Structure

- `key.txt` – This file contains the XOR key used for encryption.
- `input.txt` – The file to be encrypted or decrypted.
- `main.c` – Main program file.
- `encrypt_decrypt.c` – Contains encryption and decryption logic.

## Compilation Instructions

To compile the program, run the following command in your terminal:

```bash
gcc -o main main.c encrypt_decrypt.c
```

## Running the program (first time encrypt second time decrypt)
```bash
    ./main
```