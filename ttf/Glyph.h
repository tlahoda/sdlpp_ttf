/**
 * @file Glyph.h, Contains the Glyph class.
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
#ifndef SDL_TTF_GLYPH_H
#define SDL_TTF_GLYPH_H

#include <stdexcept>

#include <SDL_ttf.h>

namespace sdl {
namespace ttf {
    using namespace std;

    /**
     * @struct Glyph, Represents a character glyph.
     */
    struct Glyph {
        /**
         * Constructs a Glyph of c using font.
         *
         * @tparam Font, The Font. This is templated to avoid an include conflict.
         *
         * @param const Font& font, The Font to use.
         * @param char c, The character for which to create the Glyph.
         */
        template<class Font>
        Glyph (const Font& font, char c) 
          : minx_ (), maxx_ (), miny_ (), maxy_ (), advance_ () {
            if (!TTF_GlyphMetrics (*font, c, &minx_, &maxx_, &miny_, &maxy_, &advance_))
                throw runtime_error (TTF_GetError ());
        };

        /**
         * Returns the left side of the Glyph.
         *
         * @return int, The left side.
         */
        int minx () const { return minx_; };
        
        /**
         * Returns the right side of the Glyph.
         *
         * @return int, The right side.
         */
        int maxx () const { return maxx_; };
        
        /**
         * Returns the bottom of the Glyph.
         *
         * @return int, The bottom.
         */
        int miny () const { return miny_; };
        
        /**
         * Returns the top of the Glyph.
         *
         * @return int, The top.
         */
        int maxy () const { return maxy_; };
        
        /**
         * Returns the width of the Glyph including spacing.
         *
         * @return int, The width including spacing.
         */
        int advance () const { return advance_; };

        private:
            /**
             * The left side.
             */
            int minx_;
            
            /**
             * The right side.
             */
            int maxx_;
            
            /**
             * The bottom.
             */
            int miny_;
            
            /**
             * The top.
             */
            int maxy_;

            /**
             * The width including spacing.
             */
            int advance_;
    }; //Glyph
}; //ttf
}; //sdl

#endif //SDL_TTF_GLYPH_H

