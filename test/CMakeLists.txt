set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-conversion")

add_executable(test_dithering test_dithering.c)
target_link_libraries(test_dithering
  PRIVATE dithering
  PUBLIC ${CRITERION}
)
add_test(
  NAME test_dithering
  COMMAND test_dithering ${CRITERION_FLAGS}
)
