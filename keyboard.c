#include "keyboard.h"

void read_keyboard(ALLEGRO_EVENT *ev, Components *cp, Config * config){
  if(ev->type == ALLEGRO_EVENT_KEY_DOWN){
    if(ev->keyboard.keycode == ALLEGRO_KEY_UP){
      if(config->machine == server)
        cp->p1.angle = 270;
      else if(config->machine == client)
        cp->p2.angle = 270;
    }
    else if(ev->keyboard.keycode == ALLEGRO_KEY_DOWN){
      if(config->machine == server)
        cp->p1.angle = 90;
      else if(config->machine == client)
        cp->p2.angle = 90;
    }
  }
  if(ev->type == ALLEGRO_EVENT_KEY_UP){
    if(ev->keyboard.keycode == ALLEGRO_KEY_UP){
      if(config->machine == server)
        cp->p1.angle = 0;
      else if(config->machine == client)
        cp->p2.angle = 0;
    }
    else if(ev->keyboard.keycode == ALLEGRO_KEY_DOWN){
      if(config->machine == server)
        cp->p1.angle = 0;
      else if(config->machine == client)
        cp->p2.angle = 0;
    }
  }
}
