
set(BINARY_NAME RobotDataClient)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include/BasicDefine ${CMAKE_CURRENT_SOURCE_DIR}/../../include/webclient)

SET(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../temp/${BINARY_NAME})

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} DIR_SRCS)

add_library(${BINARY_NAME} SHARED ${DIR_SRCS})