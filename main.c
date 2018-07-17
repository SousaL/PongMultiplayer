/* Author: Leonardo P. S. Sousa */
#include "main.h"

const float FPS = 30;

int main(int argc, char **argv){


  Config config;
  Components cp;
  start(&cp, &config);


  al_init();
  al_init_primitives_addon();
  al_init_font_addon();
  al_init_ttf_addon();
  al_install_keyboard();

  ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
  ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
  ALLEGRO_FONT *font = al_load_font("digital.ttf", 78, 0);

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

  ALLEGRO_EVENT ev;
  while(1){     /* Game Loop */
    al_wait_for_event(event_queue, &ev);
    if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
      break;
    }

    read_keyboard(&ev, &cp, &config);

    if(ev.type == ALLEGRO_EVENT_TIMER && al_is_event_queue_empty(event_queue)) {


      if(config.machine == client)
        send_server_keyboard(&config, &cp);

      if(config.machine == server){
        receive_keyboard(&config, &cp);
        send_client_components(&config, &cp);
      }

      if(config.machine == client)
        receive_components(&config, &cp);

      if(config.machine ==server)
        update(&cp);

      clean_display();
      draw(&cp, font);
      al_flip_display();
      if(winner(&cp)){
        break;
      }
    }
   }
   clean_display();
   if(winner(&cp) == p1){
     if(config.machine == server)
      al_draw_textf(font, COLOR_WHITE, DISPLAY_W/2 - 100, 10, 0, "Voce Venceu!");
     else
      al_draw_textf(font, COLOR_WHITE, DISPLAY_W/2 - 100, 10, 0, "Game Over");
   }
   else if(winner(&cp) == p2){
     if(config.machine == client)
      al_draw_textf(font, COLOR_WHITE, DISPLAY_W/2 - 100, 10, 0, "Voce Venceu!");
     else
      al_draw_textf(font, COLOR_WHITE, DISPLAY_W/2 - 100, 10, 0, "Game Over");
   }
   al_flip_display();
   while(1){
     if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
       break;
     }
   }

   al_destroy_timer(timer);
   al_destroy_display(display);
   al_destroy_event_queue(event_queue);

   return 0;
}
