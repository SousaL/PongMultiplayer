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

  /* draw the points */
  al_draw_textf(font, COLOR_WHITE, 100, 10, 0, "%d", cp->point_p1);
  al_draw_textf(font, COLOR_WHITE, 150, 10, 0, "%d",cp->point_p2);
}
