#ifndef HTTP_RESPONSE_H
#define HTTP_RESPONSE_H

#include <stdio.h>

void send_http_response(int client_fd, int status_code,
                        const char* content_type, const void* body,
                        size_t content_length);

void send_http_error(int client_fd, int status_code, const char* message);

#endif
