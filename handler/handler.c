#include "handler.h"
#include "http_response.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

// assuming image files requested will end in .jpg based off example. 
void handle_static_request(int client_fd, const char* path) {


}

