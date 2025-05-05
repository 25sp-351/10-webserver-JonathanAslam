#ifndef HANDLER_H
#define HANDLER_H

#include "http_request.h"

void handle_static_request(int client_fd, const char* path);

void handle_calc_request(int client_fd, const char* path);

#endif // HANDLER_H