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

/** This graphical user interface uses Clutter.
 */
class Gui
{
    public:
        Gui(Application* owner); 
        ~Gui();
        
    private:
        // TODO: static void on_delete_event(GtkWidget* widget, GdkEvent* event, gpointer user_data);
        // TODO: static gboolean key_press_event(GtkWidget *widget, GdkEventKey *event, gpointer user_data);
        static const int WINWIDTH = 640;
        static const int WINHEIGHT = 480;
        Application* owner_;
        ClutterActor *stage_;
        ClutterActor *pitch_text_;
        ClutterActor *lines_group_;
        std::vector< ClutterActor* > lines_;
        static gboolean on_stage_button_press(ClutterStage *stage, ClutterEvent *event, gpointer data);
};

#endif // __GUI_H__

