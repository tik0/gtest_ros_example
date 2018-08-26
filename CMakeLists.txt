cmake_minimum_required(VERSION 2.8.3)
set(PROJECT_NAME gtest_ros_example)
project(${PROJECT_NAME})

# kinetic specific
add_compile_options(-std=c++11)

# Find packages and includes
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)
find_package(GTest REQUIRED)

include_directories(
  include/${PROJECT_NAME}
  ${catkin_INCLUDE_DIRS}
  ${GTEST_INCLUDE_DIRS}
)

catkin_package()

# Add common talker and listener executables
add_executable(rostalker src/rostalker.cpp)
add_executable(roslistener src/roslistener.cpp)
target_link_libraries(roslistener
  ${catkin_LIBRARIES} pthread
)
target_link_libraries(rostalker
  ${catkin_LIBRARIES} pthread
)

#############
## Testing ##
#############

# Build and link the test_talker
catkin_add_gtest(talker-test test/test_talker.cpp)
target_link_libraries(talker-test ${catkin_LIBRARIES})

#####################################
## Testing w/ and w/o catkin magic ##
#####################################

# Build and link the simple_test executable w/ catkin magic
catkin_add_gtest(simple_test_catkin test/simple_test.cpp)
target_link_libraries(simple_test_catkin ${catkin_LIBRARIES})

# Build and link the simple_test executable w/o any catkin magic
add_executable(simple_test src/simple_test.cpp)
target_link_libraries(simple_test ${GTEST_LIBRARIES} pthread)
