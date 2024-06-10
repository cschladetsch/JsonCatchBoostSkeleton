# Add the test files
add_executable(tests main.cpp test_example.cpp)

# Link Catch2 library
target_link_libraries(tests PRIVATE Catch2::Catch2)

# Enable testing
enable_testing()

# Discover tests
include(CTest)
include(Catch)
catch_discover_tests(tests)

