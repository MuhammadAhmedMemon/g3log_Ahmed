cmake_minimum_required(VERSION 3.11.4)
project(g3log VERSION 1.0.0)

set(INCLUDE_DIR1 ${PROJECT_SOURCE_DIR}/g3log/src)
set(INCLUDE_LIB ${PROJECT_SOURCE_DIR}/g3log/build/libg3logger.so)
set(INCLUDE_DIR2 ${PROJECT_SOURCE_DIR}/g3log/build/include)
set(INCLUDE_DIR3 /usr/include)
set(INCLUDE_SYSLIBS /usr/lib64)


include_directories(
    ${INCLUDE_DIR1}
    ${INCLUDE_DIR2}
    ${INCLUDE_DIR3}
)

add_executable(main main.cpp)
target_link_libraries(main ${INCLUDE_LIB} ${INCLUDE_SYSLIBS}/libpthread.so)