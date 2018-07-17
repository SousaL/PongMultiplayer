#ifndef CORE_H
#define CORE_H

#include "struct.h"
#include "collision.h"
#include "connection.h"

#include <stdlib.h>
#include <stdio.h>

#define PALLET_SIZE_W 10      /* +---------------------+ */
#define PALLET_SIZE_H 80    /* +---------------------+ */
#define BALL_SIZE 5
#define INIT_ANGLE 0
#define INIT_VELOCITY 10
#define PALLET_VELOCITY 15
#define DIRECTION_RIGHT 0
#define DIRECTION_LEFT 180


void create_pallets(Components *cp);   /* Create the pallets */

int winner(Components *cp);

void create_ball(Components *cp, int direction);      /* Create the ball */

void start(Components *cp, Config * config);           /* Start the Componets, create them */

void restart(Components *cp, int player_point); /* Restart after of a point */

void add_point(Components *cp, Point player_point); /* Increase pontuation */

void update(Components *cp);          /* Update the Components */
#endif  /* CORE_H */
