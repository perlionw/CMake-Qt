cmake_minimum_required(VERSION 3.5)

project(StationCheckTool)

add_subdirectory(src/TaskDataClient temp)
add_subdirectory(src/TaskFinishClient)
add_subdirectory(src/RobotDataClient)

set (TaskDataClient_LIBS TaskDataClient)
set (TaskFinishClient_LIBS TaskFinishClient)
set (RobotDataClient_LIBS RobotDataClient)

find_package(Qt5Widgets)  
find_package(Qt5Core)
find_package(Qt5Gui)
find_package(Qt5Sql)

#SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/output)

set(CMAKE_AUTOMOC ON)

option(_USRDLL "DEFINITE IF USR DLL!" OFF)

configure_file(tool_config.h.in tool_config.h)

qt5_wrap_ui(ui_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/StationCheckTool/stationrobottool.ui)
qt5_add_resources(qrc_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/StationCheckTool/stationrobottool.qrc)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src/StationCheckTool DIR_SRCS)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/build ${CMAKE_CURRENT_SOURCE_DIR}/src/StationCheckTool include/webclient include/BasicDefine include/rapidxml)
add_executable(StationCheckTool ${DIR_SRCS} ${ui_FILES} ${qrc_FILES})

target_link_libraries (StationCheckTool ${TaskDataClient_LIBS} ${TaskFinishClient_LIBS} ${RobotDataClient_LIBS} Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Sql)
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/output/Debug)	