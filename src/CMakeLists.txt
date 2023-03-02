

add_library(dimensions dimensions.c dimensions.h)
#add_library(isa isa.c isa.h)
#add_library(philip philip.c viphilip.h)

add_executable(main main.c)
target_link_libraries(main dimensions)
