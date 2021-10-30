set(PROJECT hwdll)

file(GLOB SOURCES *.cpp)
file(GLOB HEADERS *.h)

add_compile_definitions(-DDLL_EXPORTS)

# add the executable
add_library(${PROJECT} SHARED ${HEADERS} ${SOURCES})