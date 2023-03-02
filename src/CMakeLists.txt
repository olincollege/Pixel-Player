



add_library(dimensions dimensions.c dimensions.h)
#add_library(isa isa.c isa.h)
#add_library(philip philip.c viphilip.h)
# define our libraries
add_library(stb_image stb_image.h)
add_library(stb_image_resize stb_image_resize.h)

# connect our libraries to photoprocess
target_link_libraries(photoprocess stb_image stb_image_resize)


add_executable(main main.c)
target_link_libraries(main dimensions)

