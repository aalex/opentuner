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
 * Configuration for the application.
 */

#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include <string>
#include <boost/program_options.hpp>

/** 
 * Contains the configuration options for the application.
 */
class Configuration
{
    public:
        /**
         * A lot of configuration options are set in the constructor of the Configuration class.
         */
        Configuration(const boost::program_options::variables_map &options);
        bool get_verbose() const { return verbose_; } ;
    private:
        bool verbose_;
};
#endif // __CONFIGURATION_H__

