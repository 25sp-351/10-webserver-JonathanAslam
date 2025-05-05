#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

/*
could not figure out how to implement the header that was in the slides, It looked like this:

typedef struct {
    char* method;
    char* path;
    char* version;
    Headers* headers; <<-- ???
    char* body;
    int body_length;

    void (*print)(struct hreq* req);
    void (*free)(struct hreq* req);
}   Request;
*/ 


// tried to implement my own version of the header, based off what i read about the HTTP needing for the request
// and the slides

typedef struct {
    char method[10];   // used for GET, POST, etc.
    char path[1024];   // example: /calc/add/5/3, etc.
    char version[10];  // professor said are using HTTP/1.1
    char host[1024];
    char content_type[256];
} HttpRequest;

int parse_http_request_from_buffer(const char* buffer, HttpRequest* request);

#endif
