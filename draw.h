#include "struct.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_font.h>

#ifndef DRAW_H
#define DRAW_H

#define COLOR_WHITE al_map_rgb(255,255,255)
#define COLOR_BLACK al_map_rgb(0,0,0)
#define clean_display() al_clear_to_color(COLOR_BLACK);


void draw_object(Object obj);

void draw(Components *cp, ALLEGRO_FONT *font);
#endif /* DRAW_H */
