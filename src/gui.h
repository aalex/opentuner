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

#ifndef __GUI_H__
#define __GUI_H__

#include <GL/glx.h>
#include <clutter/clutter.h>
#include <vector>

class Application;

/** 
 * This graphical user interface uses Clutter.
 */
class Gui
{
    public:
        Gui(Application* owner); 
        ~Gui();
        
    private:
        static const int WINWIDTH = 640;
        static const int WINHEIGHT = 480;
        Application* owner_;
        ClutterActor *stage_;
        ClutterActor *pitch_text_;
        ClutterActor *lines_group_;
        std::vector< ClutterActor* > lines_;
        // Called when a mouse button is pressed
        static gboolean on_stage_button_press(ClutterStage *stage, ClutterEvent *event, gpointer data);
        // Called when some keys are pressed
        static gboolean on_key_pressed(ClutterActor *actor, ClutterEvent *event, gpointer user_data);
        // Called when ctrl-q is pressed
        static void do_quit(GObject * instance, const gchar *action_name, guint key_val, ClutterModifierType modifiers, gpointer user_data);
};

#endif // __GUI_H__

