cmake_minimum_required(VERSION 3.5)

project(Exam-v22 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Sql REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        addcar.cpp
        addcar.h
        addcar.ui
        addcustomer.cpp
        addcustomer.h
        addcustomer.ui
        removecar.h
        removecar.cpp
        removecar.ui
        removecustomer.h
        removecustomer.cpp
        removecustomer.ui
        editcar.cpp
        editcar.h
        editcar.ui
        editcustomer.h
        editcustomer.cpp
        editcustomer.ui
        assigncar.h
        assigncar.cpp
        assigncar.ui
        unassigncar.cpp
         unassigncar.h
          unassigncar.ui
          seachcar.h
          seachcar.cpp
          seachcar.ui
          searchcustomer.cpp
           searchcustomer.h
            searchcustomer.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Exam-v22
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Exam-v22 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Exam-v22 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Exam-v22
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Exam-v22 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)


set_target_properties(Exam-v22 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(Exam-v22 PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Sql
    Qt::Widgets
)
find_package(Qt6 REQUIRED COMPONENTS Sql)
target_link_libraries(Exam-v22 PRIVATE Qt6::Sql)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Exam-v22)
endif()
