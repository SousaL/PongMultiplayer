#include "struct.h"
#include <math.h>
#ifndef COLLISION_H
#define COLLISION_H

#define PI 3.14159265
#define to_rad(x) (x * (PI / 180.0))
#define SEGMENTS 8

int bounding_box_collision(int b1_x, int b1_y, int b1_w, int b1_h,
   int b2_x, int b2_y, int b2_w, int b2_h);

int collision(Object obj1, Object obj2);

void collide_ground(Components *cp);

void collide_roof(Components *cp);

void collide_pallets(Components *cp);

int collide_goal(Components *cp);

void move_components(Components *cp);

void move_object(Object *obj);
#endif /* COLLISION_H */
