
set(BINARY_NAME TaskFinishClient)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include/BasicDefine ${CMAKE_CURRENT_SOURCE_DIR}/../../include/webclient)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} DIR_SRCS)

message(${CMAKE_CURRENT_SOURCE_DIR})

SET(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../temp/${BINARY_NAME})

add_library(${BINARY_NAME} SHARED ${DIR_SRCS})

message(${CMAKE_BINARY_DIR})

message(${CMAKE_CURRENT_SOURCE_DIR}../../lib)

INSTALL (TARGETS TaskFinishClient LIBRARY DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}../../lib)