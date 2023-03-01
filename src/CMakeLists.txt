# include the files to execute
add_executable(photoprocess photoprocess.c)

# define our libraries
add_library(stb_image stb_image.h)
add_library(stb_image_resize stb_image_resize.h)

# connect our libraries to photoprocess
target_link_libraries(photoprocess stb_image stb_image_resize)
