# Rijndael C
**AES-128 Implementation in C with Python-based Testing**

---

## 🔐 Overview

This project implements the 128-bit AES encryption and decryption algorithm in C, 
without relying on any third-party libraries or hardware-accelerated instructions. 
It strictly follows the Rijndael specification and is tested against NIST official 
test vectors.

A Python-based test suite is also included (using `ctypes` and `pyaes`) to validate
the correctness of the C implementation by comparing encryption and decryption output.

---

## 💻 Platform

- ✅ Works on **Linux/macOS** (ARM-based chips like Apple Silicon)
- ❌ Not tested on Windows
- CI builds on GitHub using Ubuntu (see Actions tab)

---

## 📦 Project Structure

```
.
├── rijndael.c         # AES implementation
├── rijndael.h         # Public API
├── main.c             # Test using NIST AES-128 vector
├── Makefile           # Build commands
├── python_aes_ref/    # Python reference AES implementation submodule
├── tests/             # pytest suite comparing C vs Python reference
└── .github/workflows/  # GitHub Actions CI
```

---

## 🚀 How to Build & Run

```bash
# Clone the repo (including submodules)
git clone --recursive https://github.com/Shawshank01/Secure-Systems-Development-Assignment-2.git
cd Secure-Systems-Development-Assignment-2

# Build the shared library and test executable
make

# Run the NIST AES-128 vector test
./main

# Run the Python/C integration tests
pytest tests/
```

You should see:
```
✅ Encryption passed.
✅ Decryption passed.
```

---

## ✅ GitHub Actions

Every commit automatically:

- Builds the AES C implementation
- Runs Python‑based AES integration tests with pytest
- Runs the NIST test via `./main`
- Fails if encryption/decryption don't match expected output

---

## 🧪 Test Vector Used

NIST AES-128 Example:
- Key: `2b7e151628aed2a6abf7158809cf4f3c`
- Plaintext: `3243f6a8885a308d313198a2e0370734`
- Ciphertext: `3925841d02dc09fbdc118597196a0b32`

---

## 📚 Reference

- [NIST FIPS 197 — Advanced Encryption Standard (AES)](https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.197.pdf)  
  (See **Appendix C: Example Vectors** for the test key, plaintext, and expected ciphertext)
- [pyaes — pure‑Python AES reference implementation](https://github.com/ricmoo/pyaes)