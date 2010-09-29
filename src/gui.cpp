/*
 * Toonloop
 *
 * Copyright 2010 Alexandre Quessy
 * <alexandre@quessy.net>
 * http://www.toonloop.com
 *
 * Toonloop is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Toonloop is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the gnu general public license
 * along with Toonloop.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * Graphical user interface made with Clutter 
 */
#include <boost/filesystem.hpp>
#include <clutter/clutter.h>
#include <iostream>

#include "application.h"
#include "config.h"
#include "controller.h"
#include "gui.h"

namespace fs = boost::filesystem;
typedef std::vector<ClutterActor*>::iterator ActorIterator;

gboolean Gui::on_stage_button_press(ClutterStage * /* stage */, ClutterEvent *event, gpointer /* data */)
{
    gfloat x = 0;
    gfloat y = 0;
    clutter_event_get_coords(event, &x, &y);
    // g_print("Stage clicked at (%f, %f)\n", x, y);
    return TRUE; /* Stop further handling of this event. */
}

/**
 * Graphical user interface for the application. 
 *
 * Here we create the window and a Clutter stage with actors.
 *
 * Exits the application if OpenGL needs are not met.
 */
Gui::Gui(Application* owner) :
    owner_(owner)
{
    // TODO: connect to the controller's signal
    // pass
    ClutterColor stage_color = { 0x00, 0x00, 0x00, 0xff }; /* Black */
  
    /* Get the stage and set its size and color: */
    stage_ = clutter_stage_get_default();
    clutter_actor_set_size(stage_, WINWIDTH, WINHEIGHT);
    clutter_stage_set_color(CLUTTER_STAGE(stage_), &stage_color);
    clutter_actor_show(stage_);

    // The text actor for the pitch
    pitch_text_ = clutter_text_new_full("", "Sans 16px", clutter_color_new(255, 255, 255, 255));
    clutter_text_set_text(CLUTTER_TEXT(pitch_text_), "A");
    clutter_actor_set_position(pitch_text_, 20, 150);
    clutter_container_add_actor(CLUTTER_CONTAINER(stage_), pitch_text_);
  
    /* Connect a signal handler to handle mouse clicks and key presses on the stage: */ 
    g_signal_connect(stage_, "button-press-event", G_CALLBACK(on_stage_button_press), this);

}

Gui::~Gui()
{
    std::cout << "~Gui" << std::endl;
}
