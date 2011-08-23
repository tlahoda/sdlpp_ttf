/**
 * @file FontManager.h, Contains the FontManager class.
 *
 * Copyright (C) 2005 Thomas P. Lahoda
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
#ifndef SDL_TTF_FONTMANAGER_H
#define SDL_TTF_FONTMANAGER_H

#include <map>
#include <string>

#include "sdlpp_ttf/subsystem/TTF.h"
#include "sdlpp_ttf/ttf/Font.h"

namespace sdl {
namespace ttf {
    using namespace std;

    /**
     * @struct FontManager, Manages fonts.
     */
    struct FontManager {
        /**
         * Returns an instance of the FontManager.
         *
         * @return FontManager&, A rerence to the FontManager.
         */
        static FontManager& instance () {
            static FontManager instance_;
            return instance_;
        };
    
        //~FontManager ();
   
        /**
         * Returns the Font of the given name in the given point size.
         *
         * @param const string& fileName, The name of the Font to retrieve.
         * @param int pointSize, The point size.
         *
         * @return Font. The Font.
         */
        Font font (const string& fileName, int pointSize) {
            FontMap::iterator nameIter = fonts_.find (fileName);
            if (nameIter != fonts_.end ()) {
                FontSizeMap::iterator sizeIter = nameIter->second.find (pointSize);
                if (sizeIter != nameIter->second.end ()) {
                    return sizeIter->second;
                } else {
                    Font font (fileName, pointSize);
                    nameIter->second.insert (make_pair (pointSize, font));
                    return font;
                }
            } else {
                Font font (fileName, pointSize);
                FontSizeMap sizeMap;
                sizeMap.insert (make_pair (pointSize, font));
                fonts_.insert (make_pair (fileName, sizeMap));
                return font;
            }
        };

        private:
            /**
             * Constructs a FontManager.
             */
            FontManager() : fonts_ () { subsystem::TTF::instance (); };
           
            /**
             * Copy constructs a FontManager.
             *
             * @param const FontManager& rhs, The FontManager to copy..
             */
            FontManager (const FontManager& rhs);
            
            /**
             * The assignment operator.
             *
             * @param const FontManager& rhs, The FontManager from which to assign.
             *
             * @return FontManager&, A Reference to this FontManager.
             */
            FontManager& operator= (const FontManager& rhs);

            /**
             * The type of the point size to font maps.
             */
            typedef map<int, Font> FontSizeMap;

            /**
             * The type of the string to FontSizeMap map.
             */
            typedef map<string, FontSizeMap> FontMap;

            /**
             * The map of Fonts.
             */
            FontMap fonts_;
    }; //FontManager
}; //ttf
}; //sdl

#endif //SDL_TTF_FONTMANAGER_H

