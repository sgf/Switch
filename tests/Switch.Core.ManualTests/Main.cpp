#include <iostream>
#include <sys/param.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  char directory[MAXPATHLEN];
  
  if (getcwd(directory, MAXPATHLEN) != 0) {
    std::cout << "Current directory = " << directory << std::endl;
  } else {
    std::cout << "error = " << errno << "With message = " << directory << std::endl;
  }
}

