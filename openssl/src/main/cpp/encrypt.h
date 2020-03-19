//
// Created by Devilsen on 2020/3/19.
//
#include <string>
#include <string.h>
#include <iostream>
#include "include/openssl/md5.h"
#include "include/openssl/evp.h"
#include "include/openssl/bio.h"
#include "include/openssl/buffer.h"

#ifndef OPENSSL_ENCRYPT_H
#define OPENSSL_ENCRYPT_H


class Encrypt {

public:

    char *MD5(const char *str);

    char *Base64Encode(const char *input, int length, bool with_new_line);

    char *Base64Decode(const char *input, size_t length, bool with_new_line);
};


#endif //OPENSSL_ENCRYPT_H
