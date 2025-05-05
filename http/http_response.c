#include "http_response.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void send_http_response(int client_fd, int status_code,
                        const char* content_type, const void* body,
                        size_t content_length) {
    // personal note:
    // Header is a string that contains the HTTP response header, which
    // includes the HTTP version, status code, status message, content type,
    // content length, and connection status. The header is sent to the client
    // before the body of the response.
    char header[1024];
    char* status_message = "OK";  // Default, change when error occurs

    // found these on internet for HTTP 1.1 status codes for errors, picked the
    // ones i see most often
    if (status_code == 400)
        status_message = "Bad Request";
    if (status_code == 404)
        status_message = "Not Found";
    if (status_code == 500)
        status_message = "Internal Server Error";

    // use snprintf to format the header, sprintf is unsafe due to buffer
    // overflow from looking back at professor's notes

    // got logic GPT, but i think this should work for this purpose, double
    // check with professor and remove comment this if its cleared, fix if not
    // cleared
    int header_length =
        snprintf(header, sizeof(header),
                 "HTTP/1.1 %d %s\r\n"
                 "Content-Type: %s\r\n"
                 "Content-Length: %zu\r\n"
                 "Connection: close\r\n"
                 "\r\n",
                 status_code, status_message, content_type, content_length);

    write(client_fd, header, header_length);

    if (body != NULL && content_length > 0) {
        write(client_fd, body, content_length);
    }
}

void send_http_error(int client_fd, int status_code, const char* message) {
    char buffer[1024];
    int buffer_length = snprintf(buffer, sizeof(buffer), 
                                 "<html><body><h1>%d %s</h1></body></html>",
                                 status_code, message);

    send_http_response(client_fd, status_code, "text/html", buffer,
                        buffer_length);
    
}
