#include <fstream>

int main(int argc, char* argv[]) {
  std::string header = argv[1];
  header += ".hpp";
  std::string impl = argv[1];
  impl += ".cpp";
  std::ofstream fh(header);
  fh << "#pragma once\n#include <non-generated.hpp>\nextern int b;\ninline "
        "int c = a;\n";
  std::ofstream fi(impl);
  fi << "int b = 5;";
}
