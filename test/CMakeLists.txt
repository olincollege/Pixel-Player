set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-conversion")

add_executable(test_filename test_filename.c)
target_link_libraries(test_filename
  PRIVATE file file file
  PUBLIC ${CRITERION}
)
add_test(
  NAME test_filename
  COMMAND test_filename ${CRITERION_FLAGS}
)
