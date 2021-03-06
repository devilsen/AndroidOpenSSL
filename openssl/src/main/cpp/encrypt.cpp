//
// Created by Devilsen on 2020/3/19.
//

#include "encrypt.h"

char *Encrypt::MD5(const char *str) {
    MD5_CTX ctx;
    unsigned char md5[MD5_DIGEST_LENGTH];

    MD5_Init(&ctx);
    MD5_Update(&ctx, str, strlen(str));
    MD5_Final(md5, &ctx);

    char tmp[1];
    char *buff = new char[MD5_DIGEST_LENGTH + 1];
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        sprintf(tmp, "%02x", md5[i]);
        strcat(buff, tmp);
    }
    return buff;
}

char *Encrypt::Base64Encode(const char *input, int length, bool with_new_line) {
    BIO *bmem = NULL;
    BIO *b64 = NULL;
    BUF_MEM *bptr = NULL;

    b64 = BIO_new(BIO_f_base64());
    if (!with_new_line) {
        BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
    }
    bmem = BIO_new(BIO_s_mem());
    b64 = BIO_push(b64, bmem);
    BIO_write(b64, input, length);
    BIO_flush(b64);
    BIO_get_mem_ptr(b64, &bptr);

    char *buff = (char *) malloc(bptr->length + 1);
    memcpy(buff, bptr->data, bptr->length);
    buff[bptr->length] = 0;

    BIO_free_all(b64);

    return buff;
}

char *Encrypt::Base64Decode(const char *input, size_t length, bool with_new_line) {

    BIO *b64 = NULL;
    BIO *bmem = NULL;
    char *buffer = (char *) malloc(length);
    memset(buffer, 0, length);

    b64 = BIO_new(BIO_f_base64());
    if (!with_new_line) {
        BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
    }
    bmem = BIO_new_mem_buf(input, length);
    bmem = BIO_push(b64, bmem);
    BIO_read(bmem, buffer, length);

    BIO_free_all(bmem);

    return buffer;
}
