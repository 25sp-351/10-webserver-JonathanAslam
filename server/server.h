//pasted from 09-echo


#ifndef SERVER_H
#define SERVER_H

extern int print_to_terminal;

void incoming_client_connection(int* sock_fd_ptr);


#endif // SERVER_H