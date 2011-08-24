/**
 * @file RenderModes.h
 * Contains the Solid, Shaded, and Blended render mode classes.
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
#ifndef SDL_TTF_RENDERMODES_H
#define SDL_TTF_RENDERMODES_H

#include <SDL_ttf.h>

#include "sdlpp/video/Surface.h"
#include "sdlpp/misc/Color.h"
#include "sdlpp_ttf/ttf/Font.h"

namespace sdl {
namespace ttf {
    using namespace std;
    using namespace misc;
    using namespace video;

    /**
     * @struct Solid
     * @brief Renders a font as solid.
     */
    struct Solid {
        /**
         * Constructs a Solid font renderer with the specified color mask.
         *
         * @param color The color mask for the Font.
         */
        Solid (const Color& color) : color_ (color) {};

        /**
         * Returns a Surface containing c rendered in font.
         *
         * @param font The Font to use.
         * @param c The character to render.
         *
         * @return The rendered Surface.
         */
        Surface render (const Font& font, char c) const {
            return Surface (TTF_RenderGlyph_Solid (*font, c, **color_));
        };

        /**
         * Returns a Surface containg text rendered in font.
         *
         * @tparam Encoding The string encoding.
         *
         * @param font The font to use.
         * @param text The string to render.
         *
         * @return The rendered Surface.
         */
        template<int Encoding>
        Surface render (const Font& font, const string& text) const {
            return Surface (TTF_RenderText_Solid (*font, text.c_str (), **color_));
        };

        private:
            /**
             * The Color to render the Font.
             */
            Color color_;
    }; //Solid

    /**
     * @overload template<int Encoding> Surface render (const Font& font, const string& text) const
     * @brief TEXT specialization. Returns a Surface containg text rendered in font.
     *
     * @param font The font to use.
     * @param text The string to render.
     *
     * @return The rendered Surface.
     */
    template<>
    Surface Solid::render<TEXT> (const Font& font, const string& text) const {
        return Surface (TTF_RenderText_Solid (*font, text.c_str (), **color_));
    };

    /**
     * @overload template<int Encoding> Surface render (const Font& font, const string& text) const
     * @brief UTF8 specialization. Returns a Surface containg text rendered in font.
     *
     * @param font The font to use.
     * @param text The string to render.
     *
     * @return The rendered Surface.
     */
    template<>
    Surface Solid::render<UTF8> (const Font& font, const string& text) const {
        return Surface (TTF_RenderUTF8_Solid (*font, text.c_str (), **color_));
    };

    /**
     * @overload template<int Encoding> Surface render (const Font& font, const string& text) const
     * @brief UNICODE specialization. Returns a Surface containg text rendered in font.
     *
     * @param font The font to use.
     * @param text The string to render.
     *
     * @return The rendered Surface.
     */
    template<>
    Surface Solid::render<UNICODE> (const Font& font, const string& text) const {
        return Surface ();//TTF_RenderUNICODE_Solid (*font, text.c_str (), **color_));
    };

    /**
     * @struct Shaded
     * @brief Renders a font as shaded.
     */
    struct Shaded {
        /**
         * Constructs a Shaded font renderer with the specified foreground and background colors. 
         *
         * @param fg The foreground Color.
         * @param bg The background Color.
         */
        Shaded (const Color& fg, const Color& bg) : fg_ (fg), bg_ (bg) {};

        /**
         * Returns a Surface containing c rendered in font.
         *
         * @param font The Font to use.
         * @param c The character to render.
         *
         * @return The rendered Surface.
         */
        Surface render (const Font& font, char c) const {
            return TTF_RenderGlyph_Shaded (*font, c, **fg_, **bg_);
        };

        /**
         * Returns a Surface containg text rendered in font.
         *
         * @tparam Encoding The string encoding.
         *
         * @param font The font to use.
         * @param text The string to render.
         *
         * @return The rendered Surface.
         */
        template<int Encoding>
        Surface render (const Font& font, const string& text) const {
            return Surface (TTF_RenderText_Shaded (*font, text.c_str (), **fg_, **bg_));
        };

        private:
            /**
             * The foreground Color.
             */
            Color fg_;

            /**
             * The background Color.
             */
            Color bg_;
    }; //Shaded

    /**
     * @overload template<int Encoding> Surface render (const Font& font, const string& text) const
     * @brief TEXT specialization. Returns a Surface containg text rendered in font.
     *
     * @param font The font to use.
     * @param text The string to render.
     *
     * @return The rendered Surface.
     */
    template<>
    Surface Shaded::render<TEXT> (const Font& font, const string& text) const {
        return Surface (TTF_RenderText_Shaded (*font, text.c_str (), **fg_, **bg_));
    };

    /**
     * @overload template<int Encoding> Surface render (const Font& font, const string& text) const
     * @brief UTF8 specialization. Returns a Surface containg text rendered in font.
     *
     * @param font The font to use.
     * @param text The string to render.
     *
     * @return The rendered Surface.
     */
    template<>
    Surface Shaded::render<UTF8> (const Font& font, const string& text) const {
        return Surface (TTF_RenderUTF8_Shaded (*font, text.c_str (), **fg_, **bg_));
    };

    /**
     * @overload template<int Encoding> Surface render (const Font& font, const string& text) const
     * @brief UNICODE specialization. Returns a Surface containg text rendered in font.
     *
     * @param font The font to use.
     * @param text The string to render.
     *
     * @return The rendered Surface.
     */
    template<>
    Surface Shaded::render<UNICODE> (const Font& font, const string& text) const {
        return Surface ();//TTF_RenderUNICODE_Shaded (*font, text.c_str (), **fg_, **bg_));
    };

    /**
     * @struct Blended
     * @brief Renders a font as blended.
     */
    struct Blended {
        /**
         * Constructs a Blended font renderer with the specified color mask.
         *
         * @param color The color mask for the Font.
         */
        Blended (const Color& color) : color_ (color) {};

        /**
         * Returns a Surface containing c rendered in font.
         *
         * @param font The Font to use.
         * @param c The character to render.
         *
         * @return The rendered Surface.
         */
        Surface render (const Font& font, char c) const {
            return Surface (TTF_RenderGlyph_Blended (*font, c, **color_));
        };

        /**
         * Returns a Surface containg text rendered in font.
         *
         * @tparam Encoding The string encoding.
         *
         * @param font The font to use.
         * @param text The string to render.
         *
         * @return The rendered Surface.
         */
        template<int Encoding>
        Surface render (const Font& font, const string& text) const {
            return Surface (TTF_RenderText_Blended (*font, text.c_str (), **color_));
        };

        private:
            /**
             * The Color to render the Font.
             */
            Color color_;
    }; //Blended

    /**
     * @overload template<int Encoding> Surface render (const Font& font, const string& text) const
     * @brief TEXT specialization. Returns a Surface containg text rendered in font.
     *
     * @param font The font to use.
     * @param text The string to render.
     *
     * @return The rendered Surface.
     */
    template<>
    Surface Blended::render<TEXT> (const Font& font, const string& text) const {
        return Surface (TTF_RenderText_Blended (*font, text.c_str (), **color_));
    };

    /**
     * @overload template<int Encoding> Surface render (const Font& font, const string& text) const
     * @brief UTF8 specialization. Returns a Surface containg text rendered in font.
     *
     * @param font The font to use.
     * @param text The string to render.
     *
     * @return The rendered Surface.
     */
    template<>
    Surface Blended::render<UTF8> (const Font& font, const string& text) const {
        return Surface (TTF_RenderUTF8_Blended (*font, text.c_str (), **color_));
    };

    /**
     * @overload template<int Encoding> Surface render (const Font& font, const string& text) const
     * @brief UNICODE specialization. Returns a Surface containg text rendered in font.
     *
     * @param font The font to use.
     * @param text The string to render.
     *
     * @return The rendered Surface.
     */
    template<>
    Surface Blended::render<UNICODE> (const Font& font, const string& text) const {
        return Surface ();//TTF_RenderUNICODE_Blended (*font, text.c_str (), **color_));
    };
}; //ttf
}; //sdl

#endif //SDL_TTF_RENDERMODES_H

