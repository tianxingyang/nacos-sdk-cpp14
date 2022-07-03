include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)

FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

aux_source_directory( . TEST_SRC)

add_executable(tests ${TEST_SRC})

target_link_libraries(tests PRIVATE
GTest::GTest
nacos-cli-static
)

add_test(gtests tests)