/* Author: Leonardo P. S. Sousa */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "struct.h"
#include "core.h"
#include "draw.h"
#include "collision.h"


const float FPS = 30;

int main(int argc, char **argv){

  al_init();
  al_init_primitives_addon();
  al_init_font_addon();
  al_init_ttf_addon();
  al_install_keyboard();


  ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
  ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
  ALLEGRO_FONT *font = al_load_font("digital.ttf", 48, 0);



  if(!font){
    printf("Error to load a font\n");
    return -1;
  }


  ALLEGRO_DISPLAY *display = al_create_display(DISPLAY_W,DISPLAY_H);

  //REGISTRO DE EVENTOS - EVENTS REGISTER
  al_register_event_source(event_queue, al_get_display_event_source(display));
  al_register_event_source(event_queue, al_get_timer_event_source(timer));
  al_register_event_source(event_queue, al_get_keyboard_event_source());
  al_clear_to_color(COLOR_BLACK);

  al_start_timer(timer);

  Components cp;
  start(&cp);

  Machine machine = server;

  while(1){
    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);
    if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
      break;
    }
    if(machine == server){
      //cp.p1.angle = 0;
    }
    else if(machine == client){
      cp.p2.angle = 0;
    }

    if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
      if(ev.keyboard.keycode == ALLEGRO_KEY_UP){
        if(machine == server){
          cp.p1.angle = 270;
        }
        else if(machine == client){
          cp.p2.angle = 270;
        }
      }
      else if(ev.keyboard.keycode == ALLEGRO_KEY_DOWN){
        if(machine == server){
          cp.p1.angle = 90;
        }
        else if(machine == client){
          cp.p2.angle = 90;
        }
      }
    }
    if(ev.type == ALLEGRO_EVENT_KEY_UP){
      if(ev.keyboard.keycode == ALLEGRO_KEY_UP){
        if(machine == server){
          cp.p1.angle = 0;
        }
        else if(machine == client){
          cp.p2.angle = 0;
        }
      }
      else if(ev.keyboard.keycode == ALLEGRO_KEY_DOWN){
        if(machine == server){
          cp.p1.angle = 0;
        }
        else if(machine == client){
          cp.p2.angle = 0;
        }
      }
    }

    if(ev.type == ALLEGRO_EVENT_TIMER && al_is_event_queue_empty(event_queue)) {
      clean_display();
      update(&cp);
      draw(&cp, font);
      al_flip_display();
      printf("x: %f y: %f ang: %f\n", cp.ball.x, cp.ball.y, cp.ball.angle);
    }
    
   }

   al_destroy_timer(timer);
   al_destroy_display(display);
   al_destroy_event_queue(event_queue);

   return 0;
}
