#ifndef CONNECTION_H
#define CONNECTION_H

#include "struct.h"
#include <allegro5/allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

void start_server_sock(Config * config);

void start_client_sock(Config * config);

void send_server_keyboard(Config * config, Components * cp);

void send_client_components(Config * config, Components *cp);

void receive_keyboard(Config * config, Components * cp);

void receive_components(Config * config, Components * cp);

#endif /* CONNECTION_H */
