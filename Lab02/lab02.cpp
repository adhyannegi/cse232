// WRITE YOUR CODE HERE
#include <iostream>
#include <iomanip>

int main(){
  int num_of_days;
  std::cin >> num_of_days;
  double starting_distance_km = 37.33 * 149598000;
  double distance_km = 14.33 * 60 * 60 *24 * num_of_days;
  distance_km += starting_distance_km;

  double starting_distance_miles = 37.33 * 92955800;
  double distance_miles = 8.9 *60 * 60 *24 * num_of_days;
  distance_miles += starting_distance_miles;

  double round_trip_time = distance_km / 1079252848.8 * 2;

  std::cout << std::fixed << std::setprecision(2);

  std::cout << std::fixed << std::setprecision(2) << distance_km << std::endl;
  std::cout << std::fixed << std::setprecision(2) << distance_miles << std::endl;
  std::cout << std::fixed << std::setprecision(2) << round_trip_time << std::endl;
  return 0;
}