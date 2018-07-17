#ifndef STRUCT_H
#define STRUCT_H
#define DISPLAY_W 800
#define DISPLAY_H 600

enum machine{   /*represet if is a server or clinet  */
  server = 0,
  client
};

typedef enum machine Machine;




struct config{
  Machine machine;      /*represet if is a server or clinet  */
  int port_server;      /*the port_number*/
  int sock_server;
  int sock_client;
  char ip_server[30];     /*the ip to connect*/
};
typedef struct config Config;

enum point{
  p1 = 1,
  p2 = -1,
  none = 0
};
typedef enum point Point;

struct object{
  float x;
  float y;
  float w;
  float h;
  float angle;
  float velocity;
};
typedef struct object Object;


struct map{
  Object ground;  /* represent the ground          */
  Object roof;    /* represent the the roof        */
  Object bkg_p1;  /* represent the background p1   */
  Object bkg_p2;  /* represent the background p2   */
};
typedef struct map Map;

struct components{
  Object ball;    /* represent the ball's game     */
  Object p1;      /* represent the palete player 1 */
  Object p2;      /* represent the palete player 2 */
  Map map;        /* represent the map with objects*/
  int point_p1;
  int point_p2;
};
typedef struct components Components;
#endif /* STRUCT_H */
