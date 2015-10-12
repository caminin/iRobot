#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <algorithm>

template<typename T> 
std::ostream& write(std::ostream& os, const T& value);
  
template<typename T> 
std::istream & read(std::istream& is, T& value);
