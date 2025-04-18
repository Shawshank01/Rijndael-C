/*
 * Diwen Xiao
   D24128462
 * along with a brief description of this code.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h> // Added for printf and memcmp

#include "rijndael.h"

/*
 * Operations used when encrypting a block
 */
void sub_bytes(unsigned char *block) {
  // TODO: Implement me!
}

void shift_rows(unsigned char *block) {
  // TODO: Implement me!
}

void mix_columns(unsigned char *block) {
  // TODO: Implement me!
}

/*
 * Operations used when decrypting a block
 */
void invert_sub_bytes(unsigned char *block) {
  // TODO: Implement me!
}

void invert_shift_rows(unsigned char *block) {
  // TODO: Implement me!
}

void invert_mix_columns(unsigned char *block) {
  // TODO: Implement me!
}

/*
 * This operation is shared between encryption and decryption
 */
void add_round_key(unsigned char *block, unsigned char *round_key) {
  // TODO: Implement me!
}

/*
 * This function should expand the round key. Given an input,
 * which is a single 128-bit key, it should return a 176-byte
 * vector, containing the 11 round keys one after the other
 */
unsigned char *expand_key(unsigned char *cipher_key) {
  // TODO: Implement me!
  return 0;
}

/*
 * The implementations of the functions declared in the
 * header file should go here
 */
unsigned char *aes_encrypt_block(unsigned char *plaintext, unsigned char *key) {
  // TODO: Implement me!
  unsigned char *output =
      (unsigned char *)malloc(sizeof(unsigned char) * BLOCK_SIZE);
  return output;
}

unsigned char *aes_decrypt_block(unsigned char *ciphertext,
                                 unsigned char *key) {
  // TODO: Implement me!
  unsigned char *output =
      (unsigned char *)malloc(sizeof(unsigned char) * BLOCK_SIZE);
  return output;
}

int main() {
  // AES-128 test vector from NIST
  unsigned char plaintext[16] = {
    0x32, 0x43, 0xf6, 0xa8,
    0x88, 0x5a, 0x30, 0x8d,
    0x31, 0x31, 0x98, 0xa2,
    0xe0, 0x37, 0x07, 0x34
  };

  unsigned char key[16] = {
    0x2b, 0x7e, 0x15, 0x16,
    0x28, 0xae, 0xd2, 0xa6,
    0xab, 0xf7, 0x15, 0x88,
    0x09, 0xcf, 0x4f, 0x3c
  };

  unsigned char expected_cipher[16] = {
    0x39, 0x25, 0x84, 0x1d,
    0x02, 0xdc, 0x09, 0xfb,
    0xdc, 0x11, 0x85, 0x97,
    0x19, 0x6a, 0x0b, 0x32
  };

  unsigned char *ciphertext = aes_encrypt_block(plaintext, key);
  unsigned char *recovered_plaintext = aes_decrypt_block(ciphertext, key);

  printf("############ ORIGINAL PLAINTEXT ###########\n");
  print_128bit_block(plaintext);

  printf("\n\n################ CIPHERTEXT ###############\n");
  print_128bit_block(ciphertext);

  printf("\n\n########### EXPECTED CIPHERTEXT ###########\n");
  print_128bit_block(expected_cipher);

  printf("\n\n########### RECOVERED PLAINTEXT ###########\n");
  print_128bit_block(recovered_plaintext);

  if (memcmp(ciphertext, expected_cipher, 16) == 0) {
    printf("\n✅ Encryption passed.\n");
  } else {
    printf("\n❌ Encryption failed.\n");
  }

  if (memcmp(recovered_plaintext, plaintext, 16) == 0) {
    printf("✅ Decryption passed.\n");
  } else {
    printf("❌ Decryption failed.\n");
  }

  free(ciphertext);
  free(recovered_plaintext);

  return 0;
}
