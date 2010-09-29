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
#include <boost/bind.hpp>
#include <boost/program_options.hpp>
#include <clutter/clutter.h>
#include <iostream>
#include <string>

#include "application.h"
#include "controller.h"
#include "config.h"
#include "configuration.h"
#include "gui.h"

namespace po = boost::program_options;

Application::Application()
{
    // pass
}

/**
 * Parses the command line and runs the application.
 */
void Application::run(int argc, char *argv[])
{
    po::options_description desc("Opentuner musical tuner");
    // std::cout << "adding options" << std::endl;
    desc.add_options()
        ("help,h", "Show this help message and exit")
        ("version", "Show program's version number and exit")
        ("verbose,v", po::bool_switch(), "Enables a verbose output")
        ; // <-- important semi-colon
    po::variables_map options;
    
    po::store(po::parse_command_line(argc, argv, desc), options);
    po::notify(options);
    // Options that makes the program exit:
    if (options.count("help"))
    {
        std::cout << desc << std::endl;
        return;
    }
    if (options.count("version"))
    {
        std::cout << PACKAGE << " " << PACKAGE_VERSION << std::endl;
        return; 
    }
    
    // Stores the options in the Configuration class.
    // A lot of options parsing is done in the constructor of Configuration:
    config_.reset(new Configuration(options));
    controller_.reset(new Controller(this));
    // It's very important to call set_project_home and set_video_source here:

    // Init Clutter:
    GError *error;
    error = NULL;
    clutter_init(&argc, &argv);
    if (error)
        g_error("Unable to initialize Clutter: %s", error->message);
    // start GUI
    std::cout << "Starting GUI." << std::endl;
    gui_.reset(new Gui(this));
    std::cout << "Running the application" << std::endl;
    clutter_main();
}
/**
 * Destructor of a the app.
 */
Application::~Application()
{
    // pass
}

void Application::quit()
{
    std::cout << "Quitting the application." << std::endl;
    clutter_main_quit();
}

Gui* Application::get_gui() 
{
    return gui_.get();
}

Controller* Application::get_controller() 
{
    return controller_.get();
}

Configuration* Application::get_configuration() 
{
    return config_.get();
}

