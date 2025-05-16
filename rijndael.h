/*
 * This header file defines the interface for the AES-128 implementation.
 * It declares the main encryption and decryption functions that allow
 * external programs to use the AES algorithm to process 128-bit data blocks.
 * Supporting constants such as BLOCK_SIZE and the BLOCK_ACCESS macro are also defined here.
 */

#ifndef RIJNDAEL_H
#define RIJNDAEL_H

#define BLOCK_ACCESS(block, row, col) (block[(col * 4) + row])
#define BLOCK_SIZE 16

/*
 * These should be the main encrypt/decrypt functions (i.e. the main
 * entry point to the library for programmes hoping to use it to
 * encrypt or decrypt data)
 */

unsigned char *aes_encrypt_block(unsigned char *plaintext, unsigned char *key);
unsigned char *aes_decrypt_block(unsigned char *ciphertext, unsigned char *key);

#endif
