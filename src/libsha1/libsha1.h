/* ================ sha1.h ================ */
/*
  SHA-1 in C
  By Steve Reid <steve@edmweb.com>
  100% Public Domain
*/

#pragma once

#ifndef LIBSHA1_H
#define LIBSHA1_H

#if !defined(ESP8266) && !defined(ESP32)

typedef struct {
    uint32_t state[5];
    uint32_t count[2];
    unsigned char buffer[64];
} SHA1_CTX;

void SHA1Transform(uint32_t state[5], const unsigned char buffer[64]);
void SHA1Init(SHA1_CTX *context);
void SHA1Update(SHA1_CTX *context, const unsigned char *data, uint32_t len);
void SHA1Final(unsigned char digest[20], SHA1_CTX *context);

#endif

#endif // LIBSHA1_H
