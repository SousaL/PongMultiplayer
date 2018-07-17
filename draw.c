#include "draw.h"


void draw_object(Object obj){
  al_draw_filled_rectangle(obj.x, obj.y, obj.x+obj.w, obj.y+obj.h, COLOR_WHITE);
}


void draw(Components *cp, ALLEGRO_FONT *font){
  /* draw the ball */
  draw_object(cp->ball);

  /* draw the pallets */
  draw_object(cp->p1);
  draw_object(cp->p2);

  float i = 0;
  for(i = 0; i < DISPLAY_H; i+= DISPLAY_H/10 )
  al_draw_filled_rectangle(DISPLAY_W/2 - 5, i, DISPLAY_W/2 - 5 + (10), i+ ((DISPLAY_H/10)/2), COLOR_WHITE);

  /* draw the points */
  al_draw_textf(font, COLOR_WHITE, DISPLAY_W/2 - 100, 10, 0, "%d", cp->point_p1);
  al_draw_textf(font, COLOR_WHITE, DISPLAY_W/2 + 100, 10, 0, "%d",cp->point_p2);
}
