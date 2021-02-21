cmake_minimum_required(VERSION 3.10)
project(kalman-filter)

set(CMAKE_CXX_STANDARD 14)


#add_executable(kalman-filter  main.cpp)
#add_executable(kalman-filter laser_measurements/kalman_filter.cpp
#        laser_measurements/kalman_filter.h
#        laser_measurements/measurement_package.h
#        laser_measurements/tracking.cpp
#        laser_measurements/tracking.h
#        laser_measurements/main.cpp)

#add_executable(jacobian jacobian/main.cpp)

#add_executable(rmse  rmse.cpp )
#add_executable(normpdf  normpdf/main.cpp normpdf/help_functions.h)
#add_executable(mortion-model mortion-model/main.cpp mortion-model/helpers.h)
#add_executable(pseudo-range pseudo-range/main.cpp pseudo-range/helpers.h)
#add_executable(observation-model observation-model/main.cpp observation-model/helpers.h)
#add_executable(markov-localization-filter markov-localization-filter/main.cpp markov-localization-filter/helpers.h)
#add_executable(particle-filter-cpp particle-filter-cpp/gaussian_sample.cpp)
#add_executable(particle-filter-cpp particle-filter-cpp/multi_gussian.cpp particle-filter-cpp/multi_gussian.h particle-filter-cpp/multi_guss_sol.cpp)

#add_executable(naive_bayes naive_bayes/main.cpp naive_bayes/classifier.cpp naive_bayes/classifier.h)

#add_executable(cost_function cost_function/main.cpp cost_function/cost.cpp cost_function/cost.h)

add_executable(behavior_planner behavior_planner/main.cpp
        behavior_planner/vehicle.cpp behavior_planner/vehicle.h
        behavior_planner/cost.h behavior_planner/cost.cpp
        behavior_planner/road.h behavior_planner/road.cpp)