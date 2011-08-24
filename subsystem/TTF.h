/**
 * @file TTF.h
 * Contains the TTF class.
 *
 * Copyright (C) 2011 Thomas P. Lahoda
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */
#ifndef SDL_SUBSYSTEM_TTF_H
#define SDL_SUBSYSTEM_TTF_H

#include <stdexcept>

#include <SDL_ttf.h>

namespace sdl {
namespace subsystem {
    using namespace std;

    /**
     * @struct TTF
     * @brief The True Type Font subsystem
     */
    struct TTF {
        /**
         * Returns an instance of the TTF subsystem.
         *
         * @return A reference to the TTF subsystem.
         */
        static TTF& instance () {
            static TTF instance_;
            return instance_;
        };

        /**
         * Determines if the TTF subsystem is open.
         *
         * @return True if the TTF subsystem is open, false otherwise.
         */
        static bool isOpen () { return TTF_WasInit (); };

        /**
         * Enable byte swapping relative to the system's endianess for UNICODE data.
         */
        void enableByteSwappedUNICODE () { TTF_ByteSwappedUNICODE (1); };

        /**
         * Disable byte swapping relative to the system's endianess for UNICODE date.
         */
        void disableByteSwappedUNICODE () { TTF_ByteSwappedUNICODE (0); };

        protected:
            /**
             * Opens the TTF subsystem.
             *
             * @return True if the TTF subsystem was opened, false otherwise.
             */
            bool open () {
                init ();
                return isOpen ();
            };

            /**
             * Closes the TTF subssytem.
             *
             * @return True if the TTF subsystem was closed, false otherwise.
             */
            bool close () {
                quit ();
                return !isOpen ();
            };
           
        private:
            /**
             * Initialize the TTF subsystem.
             */
            void init () {
                if (TTF_Init () == -1) 
                    throw runtime_error (TTF_GetError ());
            };

            /**
             * Quits the TTF subssytem.
             */
            void quit () { TTF_Quit (); };
        
            /**
             * Initializes the TTF subsystem.
             */
            TTF () { init (); };

            /**
             * Closes the TTF subsystem.
             */
            ~TTF () { quit (); };
    }; //TTF
}; //subsystem
}; //sdl

#endif //SDL_SUBSYSTEM_TTF_H

