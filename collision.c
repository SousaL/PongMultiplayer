#include "collision.h"
#include <stdlib.h>

int bounding_box_collision(int b1_x, int b1_y, int b1_w, int b1_h,
   int b2_x, int b2_y, int b2_w, int b2_h)
{
    if (b1_x < b2_x + b2_w &&
        b1_x + b1_w > b2_x &&
        b1_y < b2_y + b2_h &&
        b1_h + b1_y > b2_y) {
          return 1;
      }
      return 0;
}

void add_angle(Object *obj, float angle){
  //obj->angle += 2*(90.0 - obj->angle) + (-obj->angle + (2*angle_normalize));
  obj->angle = angle;
}

int collision(Object obj1, Object obj2){
  return bounding_box_collision(obj1.x, obj1.y, obj1.w, obj1.h,
    obj2.x, obj2.y, obj2.w, obj2.h);

}


void collide_ground(Components *cp){
  if(collision(cp->ball, cp->map.ground)){
    add_angle(&cp->ball, -cp->ball.angle);
    cp->ball.y = cp->map.ground.y - cp->ball.h;
    printf("--x: %f y: %f ang: %f\n", cp->ball.x, cp->ball.y, cp->ball.angle);
    //getchar();
  }
}


void collide_roof(Components *cp){
  if(collision(cp->ball, cp->map.roof)){
    add_angle(&cp->ball, -cp->ball.angle);
    cp->ball.y = cp->map.roof.y + cp->map.roof.h;
  }
}

void collide_pallets(Components *cp){
  float ponto = cp->ball.y + cp->ball.h/2; /* middle point of the ball */
  float n = SEGMENTS;
  float i;
  int j;
  float angle;
  float increment = cp->p2.h/8;
  if(collision(cp->ball, cp->p1)){ /* if ball collide with first pallet */
    float base = cp->ball.y - cp->p1.y;
    for(i = 0.0, j = 0; i < cp->p2.h; i += increment, j++){
      if(base < i){
        switch(j){
          case 0: angle = -45; break;
          case 1: angle = -30; break;
          case 2: angle = -15; break;
          case 3:
          case 4: angle = 0; break;
          case 5: angle = 15; break;
          case 6: angle = 30; break;
          case 7: angle = 45; break;
        }
        break;
      }
    }
    add_angle(&cp->ball, angle);
  }
  else if(collision(cp->ball, cp->p2)){ /* if ball collide with second pallet */
    float base = cp->ball.y - cp->p2.y;
    for(i = 0.0, j = 0; i < cp->p2.h; i += increment, j++){
      if(base < i){
        switch(j){
          case 0: angle = 220; break;
          case 1: angle = 205; break;
          case 2: angle = 190; break;
          case 3:
          case 4: angle = 180; break;
          case 5: angle = 165; break;
          case 6: angle = 150; break;
          case 7:
          default:angle = 135; break;
        }
        break;
      }
    }
    add_angle(&cp->ball, angle);
  }
}

Point collide_goal(Components *cp){
  if(collision(cp->ball, cp->map.bkg_p2)){

    return p1; /* Return 1 if P1 make a point */
  }
  else if(collision(cp->ball, cp->map.bkg_p1)){

    return p2; /* Return -1 if P2 make a point */
  }
  return 0; /* Return 0 if no one make a point */

}

void move_components(Components *cp){
  /* move the ball */
  move_object(&cp->ball);
  if(cp->p1.angle != 0)
    move_object(&cp->p1);
  if(cp->p2.angle != 0)
    move_object(&cp->p2);

}

void move_object(Object *obj){ /* generic function to move object */
  obj->x += obj->velocity * (float)cos(to_rad(obj->angle));
  obj->y += obj->velocity * (float)sin(to_rad(obj->angle));
}
