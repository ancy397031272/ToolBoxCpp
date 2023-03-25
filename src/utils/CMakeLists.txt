set(SRCS FileSystem.cpp
        )

add_library(toolbox ${SRCS})

target_include_directories(toolbox PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

target_link_libraries(toolbox PUBLIC fmt::fmt)

install(DIRECTORY ${PROJECT_DIR}/include/
        DESTINATION "${CMAKE_INSTALL_PREFIX}/toolbox/include"
        USE_SOURCE_PERMISSIONS
        )

install(TARGETS toolbox fmt
        EXPORT toolbox_target
        ARCHIVE DESTINATION "${CMAKE_INSTALL_PREFIX}/toolbox/lib"
        LIBRARY DESTINATION "${CMAKE_INSTALL_PREFIX}/toolbox/lib"
        RUNTIME DESTINATION "${CMAKE_INSTALL_PREFIX}/toolbox/bin"
        )
