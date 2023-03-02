# Some compilers warn that the return value of cr_assert gets converted from an
# int to a unsigned char:1. To avoid this error in those compilers, turn off
# conversion warnings for test code.
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
