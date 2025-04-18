# Secure Systems Development - Assignment 2
**AES-128 Implementation in C**
Author: Diwen Xiao (D24128462)

---

## 🔐 Overview

This project implements the 128-bit AES encryption and decryption algorithm in C, without relying on any third-party libraries or hardware-accelerated instructions. It strictly follows the Rijndael specification and is tested against NIST official test vectors.

---

## 💻 Platform

- ✅ Works on **Linux/macOS** (including ARM-based chips like Apple Silicon)
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
└── .github/workflows/ # GitHub Actions CI
```

---

## 🚀 How to Build & Run

```bash
make clean     # Remove previous builds
make           # Compile the shared library and test executable
./main         # Run the encryption and decryption test
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