add_library(demo_ranges)
target_sources(demo_ranges PUBLIC FILE_SET CXX_MODULES FILES ranges.cc)

add_executable(demo main.cc)
target_link_libraries(demo demo_ranges)