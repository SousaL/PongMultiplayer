#include "connection.h"

void error(char *msg)
{
    perror(msg);
    exit(1);
}

void start_server_sock(Config * config){
	int sockfd, clilen;
	struct sockaddr_in serv_addr, cli_addr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		error("ERROR opening socket");
	bzero((char *) &serv_addr, sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(config->port_server);

	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		error("ERROR on binding");

	listen(sockfd,5);

	clilen = sizeof(cli_addr);
	config->sock_server = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
	if (config->sock_server < 0)
		error("ERROR on accept");
}

void start_client_sock(Config * config){
	struct sockaddr_in serv_addr;
	struct hostent *server;

	config->sock_client = socket(AF_INET, SOCK_STREAM, 0);
	if (config->sock_client < 0)
		error("ERROR opening socket");

	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	inet_aton(config->ip_server, &serv_addr.sin_addr);
	serv_addr.sin_port = htons(config->port_server);
	if (connect(config->sock_client,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
		error("ERROR connecting");
}

void send_server_keyboard(Config * config, Components * cp){
	int angle = cp->p2.angle;
	write(config->sock_client,&angle,sizeof(angle));
}

void send_client_components(Config * config, Components *cp){
	write(config->sock_server, cp, sizeof(*cp));
}

void receive_keyboard(Config * config, Components * cp){
	int angle;
	read(config->sock_server,&angle,sizeof(angle));
	printf("-%d\n", angle);
	cp->p2.angle = angle;
}

void receive_components(Config * config, Components * cp){
	read(config->sock_client,cp,sizeof(*cp));
}
