cmake_minimum_required(VERSION 3.5)

project(CDDB VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Sql REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        widget.cpp
        widget.h
        widget.ui
        album.h
        album.cpp
        song.h
        song.cpp
        detail.ui
        detail.h
        detail.cpp
        mainwindow.ui
        mainwindow.cpp
        mainwindow.h
        database.h
        database.cpp
        addDialog.h
        addDialog.cpp
        addDialog.ui
        AddSongDialog.ui
        AddSongDialog.h
        AddSongDialog.cpp
        search.ui
        search.h
        search.cpp
)

configure_file(cddb.db cddb.db COPYONLY)
file(COPY images DESTINATION .)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(CDDB
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET CDDB APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(CDDB SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(CDDB
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(CDDB PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(CDDB PRIVATE Qt${QT_VERSION_MAJOR}::Sql)

set_target_properties(CDDB PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(CDDB)
endif()
