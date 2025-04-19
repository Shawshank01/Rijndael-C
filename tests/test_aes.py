# tests/test_aes.py

import os
import sys
import ctypes
import pytest

# Ensure we can import the Python reference
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '..', 'python_aes_ref')))
import pyaes

# Load the C library
LIB_PATH = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', 'rijndael.so'))
rijndael = ctypes.CDLL(LIB_PATH)

# Configure ctypes prototypes
rijndael.aes_encrypt_block.argtypes = (
    ctypes.POINTER(ctypes.c_ubyte),
    ctypes.POINTER(ctypes.c_ubyte),
)
rijndael.aes_encrypt_block.restype = ctypes.POINTER(ctypes.c_ubyte)

rijndael.aes_decrypt_block.argtypes = (
    ctypes.POINTER(ctypes.c_ubyte),
    ctypes.POINTER(ctypes.c_ubyte),
)
rijndael.aes_decrypt_block.restype = ctypes.POINTER(ctypes.c_ubyte)

def c_encrypt_block(plaintext: bytes, key: bytes) -> bytes:
    pt_arr = (ctypes.c_ubyte * 16).from_buffer_copy(plaintext)
    key_arr = (ctypes.c_ubyte * 16).from_buffer_copy(key)
    res_ptr = rijndael.aes_encrypt_block(pt_arr, key_arr)
    return bytes(res_ptr[i] for i in range(16))

def c_decrypt_block(ciphertext: bytes, key: bytes) -> bytes:
    ct_arr = (ctypes.c_ubyte * 16).from_buffer_copy(ciphertext)
    key_arr = (ctypes.c_ubyte * 16).from_buffer_copy(key)
    res_ptr = rijndael.aes_decrypt_block(ct_arr, key_arr)
    return bytes(res_ptr[i] for i in range(16))

@pytest.mark.parametrize("plaintext,key", [
    (os.urandom(16), os.urandom(16)),
    (os.urandom(16), os.urandom(16)),
    (os.urandom(16), os.urandom(16)),
])
def test_encrypt_decrypt_roundtrip(plaintext, key):
    # Reference encryption/decryption using pyaes ECB mode
    aes_ref = pyaes.AESModeOfOperationECB(key)
    ref_cipher = aes_ref.encrypt(plaintext)
    ref_plain = aes_ref.decrypt(ref_cipher)

    # C implementation
    c_cipher = c_encrypt_block(plaintext, key)
    c_plain = c_decrypt_block(c_cipher, key)

    # Compare C ↔ Python
    assert c_cipher == ref_cipher
    assert c_plain == plaintext