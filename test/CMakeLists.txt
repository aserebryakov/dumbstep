enable_testing()

add_executable(
  dumbstep_test 
  hello_test.cc
)

target_include_directories(dumbstep_test PRIVATE ../include)

target_link_libraries(
  dumbstep_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(dumbstep_test)
