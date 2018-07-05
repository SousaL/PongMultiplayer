#include "struct.h"
#ifndef CORE_H
#define CORE_H

#define PALLET_SIZE_W 20      /* +---------------------+ */
#define PALLET_SIZE_H 150    /* +---------------------+ */
#define BALL_SIZE 10
#define INIT_ANGLE 10
#define INIT_VELOCITY 20
#define PALLET_VELOCITY 20
#define DIRECTION_RIGHT 1
#define DIRECTION_LEFT -1


void create_pallets(Components *cp);   /* Create the pallets */

void create_ball(Components *cp, int direction);      /* Create the ball */

void start(Components *cp);           /* Start the Componets, create them */

void restart(Components *cp, int player_point); /* Restart after of a point */

void add_point(Components *cp, Point player_point); /* Increase pontuation */

void update(Components *cp);          /* Update the Components */
#endif  /* CORE_H */
