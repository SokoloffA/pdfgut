 # BEGIN_COMMON_COPYRIGHT_HEADER
 # (c)LGPL2+
 #
 # Flacon - audio File Encoder
 # https://github.com/flacon/flacon
 #
 # Copyright: 2012-2013
 #   Alexander Sokoloff <sokoloff.a@gmail.com>
 #
 # This library is free software; you can redistribute it and/or
 # modify it under the terms of the GNU Lesser General Public
 # License as published by the Free Software Foundation; either
 # version 2.1 of the License, or (at your option) any later version.

 # This library is distributed in the hope that it will be useful,
 # but WITHOUT ANY WARRANTY; without even the implied warranty of
 # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 # Lesser General Public License for more details.

 # You should have received a copy of the GNU Lesser General Public
 # License along with this library; if not, write to the Free Software
 # Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 #
 # END_COMMON_COPYRIGHT_HEADER

cmake_minimum_required(VERSION 3.0.0)
cmake_policy(SET CMP0028 NEW)


project(pdfgut)

set(MAJOR_VERSION 0)
set(MINOR_VERSION 0)
set(PATCH_VERSION 1)
set(FULL_VERSION ${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION})

add_definitions(-DAPPLICATION_MAJOR_VERSION=\"${MAJOR_VERSION}\")
add_definitions(-DAPPLICATION_FLACON_MINOR_VERSION=\"${MINOR_VERSION}\")
add_definitions(-DAPPLICATION_PATCH_VERSION=\"${PATCH_VERSION}\")
add_definitions(-DAPPLICATION_VERSION=\"${FULL_VERSION}\")

set (CMAKE_CXX_STANDARD 11)
include("cmake/tools.cmake")
status_message("${PROJECT_NAME} ver. ${FULL_VERSION}")
status_message(" ")


set(HEADERS
    mainwindow.h
    document.h
    settings.h
    thememanager.h

    panels/objtreeviewitem.h
    panels/objnumtreeview.h

    view/objview.h
    view/parseview.h

    pdfparser/pdferrors.h
    pdfparser/pdfobject.h
    pdfparser/pdfreader.h
    pdfparser/pdfvalue.h
    #pdfparser/pdfwriter.h
    pdfparser/pdfxref.h

)

set(SOURCES
    main.cpp
    mainwindow.cpp
    document.cpp
    settings.cpp
    thememanager.cpp

    panels/objtreeviewitem.cpp
    panels/objnumtreeview.cpp

    view/objview.cpp
    view/parseview.cpp

    pdfparser/pdfobject.cpp
    pdfparser/pdfreader.cpp
    pdfparser/pdfvalue.cpp
    #pdfparser/pdfwriter.cpp
    pdfparser/pdfxref.cpp
)



# set(UI_FILES
#     mainwindow.ui
#     printersettings/printersettings.ui
#     aboutdialog/aboutdialog.ui
#     export/exporttopdf.ui
#     configdialog/configdialog.ui
#     printdialog/printdialog.ui
# )

# QRC files .................
# set(RESOURCES
#     resource.qrc
# )

# add translations ...
# file (GLOB TS_FILES
#     translations/boomaga*.ts
# )

# set(TRANSLATIONS_DIR
#     "${GUI_SHARE_DIR}/translations"
# )
# add_definitions(-DTRANSLATIONS_DIR=\"${TRANSLATIONS_DIR}\")


#*******************************************

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt5 REQUIRED
    Core
    Widgets
    LinguistTools
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)


SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(ZLIB REQUIRED)
include_directories(${ZLIB_INCLUDE_DIRS})
set(LIBRARIES ${LIBRARIES} ${ZLIB_LIBRARIES})

#include(translations/translatorsinfo/CMakeLists.txt)
#get_translatorsinfo_qrc(translatorsinfo_qrc)
#qt5_add_resources(TRANSLATORS_INFO_QRC ${translatorsinfo_qrc})

#qt5_add_resources(  QRC_SOURCES ${RESOURCES})
#qt5_add_translation(QM_FILES    ${TS_FILES})


add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} ${QM_FILES} ${QRC_SOURCES} ${TRANSLATORS_INFO_QRC})
target_link_libraries(${PROJECT_NAME} ${LIBRARIES} Qt5::Widgets)


install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
#install(FILES ${QM_FILES} DESTINATION ${TRANSLATIONS_DIR})

#add_tests("tests")

show_status()
