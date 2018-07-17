#include "core.h"


void create_pallets(Components *cp){
  /* first pallet */
  cp->p1.x = 100;
  cp->p1.y = DISPLAY_H/2-(PALLET_SIZE_H/2);
  cp->p1.w = PALLET_SIZE_W;
  cp->p1.h = PALLET_SIZE_H;
  cp->p1.angle = 0;
  cp->p1.velocity = PALLET_VELOCITY;
  cp->point_p1 = 0;

  /* second pallet */
  cp->p2.x = DISPLAY_W-100;
  cp->p2.y = DISPLAY_H/2-(PALLET_SIZE_H/2);
  cp->p2.w = PALLET_SIZE_W;
  cp->p2.h = PALLET_SIZE_H;
  cp->point_p2 = 0;
  cp->p2.angle = 0;
  cp->p2.velocity = PALLET_VELOCITY;

}

void create_ball(Components *cp, int direction){
  /* create the ball */
  cp->ball.x = DISPLAY_W/2;
  cp->ball.y = DISPLAY_H/2;
  cp->ball.w = BALL_SIZE;
  cp->ball.h = BALL_SIZE;
  cp->ball.angle = direction;
  cp->ball.velocity = INIT_VELOCITY;
}

void create_map(Components *cp){
  /* Create ground */
  cp->map.ground.x = 0;
  cp->map.ground.y = DISPLAY_H;
  cp->map.ground.w = DISPLAY_W;
  cp->map.ground.h = 100;

  /* Create roof */
  cp->map.roof.x = 0;
  cp->map.roof.y = -100;
  cp->map.roof.w = DISPLAY_W;
  cp->map.roof.h = 100;

  /* Create background p1 */
  cp->map.bkg_p1.x = -100;
  cp->map.bkg_p1.y = 0;
  cp->map.bkg_p1.w = 100;
  cp->map.bkg_p1.h = DISPLAY_H;

  /* Create background p2 */
  cp->map.bkg_p2.x = DISPLAY_W;
  cp->map.bkg_p2.y = 0;
  cp->map.bkg_p2.w = 100;
  cp->map.bkg_p2.h = DISPLAY_H;
}


void start(Components *cp, Config * config){
  /* define initial position of the ball */
  /* set the points */

  printf("          ______      _____      ___    _     ______    \n");
  printf("        /|  __  |   /|  _  |   /|   \\  | |   /|  ___|   \n");
  printf("       | | |__| |  /|  | |  | | |    \\ | |  /|  |  __\n");
  printf("       | |  ____| | |  | |  | | |  |\\ \\| | | |  | |  | \n");
  printf("       | |  |__/  | |  |_|  | | |  | \\   | | |  |__| |  \n");
  printf("       | |__|      |/|_____|  | |__|\\ \\__|  |/|_____|  \n");
  printf("       |/__/        |/____/   |/__/  \\/__/   |/____/  \n\n\n");
  printf("Servidor ou Cliente? (s/c) ");

  switch(getchar()){
    case 'c': config->machine = client; break;
    case 's': config->machine = server; break;
  }
  fflush(stdin);
  printf("Defina a porta: ");
  scanf("%d", &config->port_server);
  if(config->machine == client){
    printf("Ip conexao: ");
    scanf("%s", config->ip_server);
  }

  if(config->machine == server)
    start_server_sock(config);
  else if(config->machine == client)
    start_client_sock(config);


  create_pallets(cp);
  create_ball(cp, DIRECTION_RIGHT);
  create_map(cp);

}

void add_point(Components *cp, Point player_point){ /* Increase the pontuation*/
  if(player_point == p1){
    cp->point_p1++;
  }
  else if(player_point == p2){
    cp->point_p2++;
  }
}

void restart(Components *cp, Point player_point){
  if(player_point == p1){
    create_ball(cp, DIRECTION_LEFT);
  }
  else if(player_point == p2){
    create_ball(cp, DIRECTION_RIGHT);
  }
}


void update(Components *cp){
  Point result;
  /* check if the game over */


  collide_ground(cp);
  collide_roof(cp);
  collide_pallets(cp);
  move_components(cp);

  result = collide_goal(cp);

  if(result != none){ /* Test if No one make a point*/
    add_point(cp, result);
    restart(cp, result);
  }
}

int winner(Components *cp){
  if(cp->point_p1 == 10)
    return p1;
  else if(cp->point_p2 == 10)
    return p2;
  return 0;
}
