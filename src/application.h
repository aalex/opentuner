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
#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <boost/program_options.hpp>
#include <boost/scoped_ptr.hpp>
#include <tr1/unordered_map>

class Clip;
class Configuration;
class Controller;
class Gui;

/** The Application class.
 */
class Application 
{
    public:
        Application();
        ~Application();
        void run(int argc, char *argv[]);
        void quit();
        /** Returns the GUI */
        Gui *get_gui();
        /** Returns the Controller for actions and events */
        Controller *get_controller();
        /** Returns the Configuration for the application */
        Configuration *get_configuration();

    private:
        boost::scoped_ptr<Controller> controller_;
        boost::scoped_ptr<Gui> gui_;
        boost::scoped_ptr<Configuration> config_;
};

#endif // __APPLICATION_H__
