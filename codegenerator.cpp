#include <fstream>

int main(int argc, char* argv[]) {
  std::string header = argv[1];
  header += ".hpp";
  std::string impl = argv[1];
  impl += ".cpp";
  std::ofstream fh(header);
  fh << "#pragma once\nextern int a;\n";
  std::ofstream fi(impl);
  fi << "int a = 5;";
}
