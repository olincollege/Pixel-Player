# define our libraries
add_library(stb_image stb_image.c stb_image.h)
add_library(stb_image_resize stb_image_resize.c stb_image_resize.h)

#excluded warnings because we did not write these files
set_target_properties(stb_image PROPERTIES COMPILE_FLAGS "-w")
set_target_properties(stb_image_resize PROPERTIES COMPILE_FLAGS "-w")

add_library(dithering dithering.c dithering.h)
add_library(photoprocess photoprocess.c photoprocess.h)
target_link_libraries(stb_image PRIVATE m)
target_link_libraries(dithering PRIVATE m)

add_executable(main main.c)
target_link_libraries(main stb_image stb_image_resize dithering photoprocess)
