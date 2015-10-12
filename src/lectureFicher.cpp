#include "../include/lectureFichier.hpp"

template<typename T> 
std::ostream& write(std::ostream& os, const T& value) 
{ 
    return os.write(reinterpret_cast<const char*>(&value), sizeof(T)); 
} 
  
template<typename T> 
std::istream & read(std::istream& is, T& value) 
{ 
    return is.read(reinterpret_cast<char*>(&value), sizeof(T)); 
} 
