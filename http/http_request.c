#include "http_request.h"

#include <stdio.h>
#include <string.h>

int parse_http_request(const char* buffer, HttpRequest* request) {
    memset(request, 0, sizeof(HttpRequest));

    if (sscanf(buffer, "%s %s %s", request->method, request->path,
               request->version) != 3) {
        return -1;  // Failed to parse method, path, and version
    }

    // strstr() is used to find a substring in a string
    char* host_header = strstr(buffer, "Host: ");
    if (host_header != NULL)
        sscanf(host_header, "Host: %s", request->host);

    return 0;
}
