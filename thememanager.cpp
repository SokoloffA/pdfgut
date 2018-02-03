/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * PDFGut - show the Internal Structure of a PDF
 * https://github.com/SokoloffA/pdfgut
 *
 * Copyright: 2018
 *   Alexander Sokoloff <sokoloff.a@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * END_COMMON_COPYRIGHT_HEADER */


#include "thememanager.h"


/************************************************
 *
 ************************************************/
ThemeManager &ThemeManager::instance()
{
    static ThemeManager res;
    return res;
}

QString ThemeManager::parseViewQSS()
{
    return "";

    // Dark ...............................
    return "background-color: #41423D; color: #EEEEEE; ";
    // Dark ...............................
}


/************************************************
 *
 ************************************************/
QString ThemeManager::parseViewCSS()
{
    return
            "<style>\n"
            ".error { color: #E50303; } \n"
            "li { margin: -20px;}\n"
            "ul {margin: 0; padding:0;}"
            ".topLevel {margin: -30px;}\n"
            ".header {background-color: #EEEEEE; }\n"

            ".dName  { color: #006E4A;} \n"
            ".num    { color: #B08000; }\n"
            //".string { color: #3A5CB7; }\n"
            ".string { color: #0B57AE; }\n"
            ".link   { color: #644EB8; }\n"
            ".bool   { color: #404040; font-weight: bold; }\n"
            ".null   { color: #404040; font-weight: bold; }\n"
            ".name   { color: #BF0303; }\n"
            "</style>";



    return
            "<style>\n"
            ".error { color: #E50303; } \n"
            "li { margin: -20px;}\n"
            "ul {margin: 0; padding:0;}"
            ".topLevel {margin: -30px;}\n"
            ".header {background-color: #EEEEEE; }\n"

            ".dName  { color: #0B57AE;} \n"
            ".num    { color: #B08000; }\n"
            //".string { color: #3A5CB7; }\n"
            ".string { color: #BF0303; }\n"
            ".link   { color: #644EB8; }\n"
            ".bool   { color: #404040; font-weight: bold; }\n"
            ".null   { color: #404040; font-weight: bold; }\n"
            ".name   { color: #006E4A; }\n"
            "</style>";

    // Dark ...............................
    return
            "<style>\n"
            ".error { color: #E50303; } \n"

            ".dName  { color: #74D0F0;} \n"
            ".link   { color: #569CD6; }\n"
            ".name   { color: #CE9178; }\n"
            ".num    { color: #DCDCAA; }\n"
            ".bool   { color: #C586C0; }\n"
            ".null   { color: #C586C0; }\n"
            ".string   { color: #5B843F; }\n"
            "li { margin: -30px;}\n"
            "</style>"
            "\n\n"
            ;
    // Dark ...............................

/*
 *             "<style>\n"
            ".error { color: #E50303; } \n"

//            ".dName  { color: #A05A27;} \n"
            ".dName  { color: #303030;} \n"
            ".link   { color: #3D5DBA; }\n"
            ".name   { color: #008000; }\n"
            ".num    { color: #986800; }\n"
            ".bool   { color: #C586C0; }\n"
            ".null   { color: #C586C0; }\n"
            ".string   { color: #5B843F; }\n"
            "li { margin: -30px;}\n"
            "</style>
 */
/*
    return
            "<style>\n"
            ".header { "
            "  background-color: #696562; "
            "  color: #CCCCCC; "
            " }\n"
            ".error { color: #E50303; } \n"

            ".dName  { color: #A05A27;} \n"
//            ".dName  { color: #;} \n"
            ".link   { color: #375DBC; }\n"
            ".name   { color: #067332; }\n"
            ".num    { color: #B08000; }\n"
            ".bool   { color: #C586C0; }\n"
            ".null   { color: #C586C0; }\n"
            ".string   { color: #BF0303; }\n"
            "li { margin: -30px;}\n"
            "</style>"
            "\n\n"
            ;
********/
/*
    return
            "<style>\n"
            ".header { "
            "  background-color: #696562; "
            "  color: #CCCCCC; "
            " }\n"
            ".error { color: #E50303; } \n"

//            ".dName  { color: #375DBC;} \n"
            ".dName  { color: #505050;} \n"
            ".link   { color: #008000; }\n"
            ".name   { color: #A05A27; }\n"
            ".num    { color: #B08000; }\n"
            ".bool   { color: #A92083; }\n"
            ".null   { color: #BF0303; }\n"
            //".string   { color: #BF0303; }\n"
            ".string   { color: #375DBC; }\n"
            "li { margin: -30px;}\n"
            "</style>"
            "\n\n"
            ;
*/
}


/************************************************
 *
 ************************************************/
ThemeManager::ThemeManager()
{

}
