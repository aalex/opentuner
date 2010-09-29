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
 * The Controller contains most actions and events.
 */

#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <boost/bind.hpp>
#include <boost/signals2.hpp>
#include <string>

// Forward declaration
class Application;

/** The Controller contains most actions and events.
 *
 * The Controller contains the methods that any class should call.
 *
 * It also contains the signals to which they should connect their 
 * slots in order to subscribe to the events notifications. 
 */
class Controller
{
    public:
        //FIXME: does this member need to be public?
        /**
         * Constructor.
         */
        Controller(Application* owner);
        // FIXME: figure out what to do
        /** 
         * Called each time a pitch is detected
         * Arguments: not sure yet
         */
        boost::signals2::signal<void (unsigned int, unsigned int)> pitch_detected_signal_;

    private:
        Application* owner_;
};
#endif 
