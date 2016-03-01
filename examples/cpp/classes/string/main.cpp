#include <iostream>
#include <cstring>

class string {
public:
  string() : buf(new char[1]) { buf[0] = '\0'; }
  string(const char* b) : buf(new char[strlen(b)+1]) { 
    strcpy(buf, b);
  }
  string(const string& s) : buf(new char[strlen(s.buf)+1]) { 
    strcpy(buf, s.buf);
  }
  ~string() { delete [] buf; }
  const char* getBuf() const { return buf; }
  string& operator=(const string&);
private:
  char* buf;
};
std::ostream& operator<<(std::ostream& out, const string& s) {
  return out << s.getBuf();
}
string& string::operator=(const string& s) {
  if ( this == & s) return *this;
  delete [] buf;
  buf = new char[strlen(s.buf)+1];
  strcpy(buf, s.buf);
  return *this;
}

int main() {
  string a, b("cat"), c(b);
  a.operator=(b);
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << c << std::endl;
  return 0;
}
