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
using std::tr1::shared_ptr;
typedef std::vector<ClutterActor*>::iterator ActorIterator;

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
}

Gui::~Gui()
{
    std::cout << "~Gui" << std::endl;
}
