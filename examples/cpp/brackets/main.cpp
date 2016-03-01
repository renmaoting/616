#include <iostream>
#include <cstring>

class string {
public:
  string(int n = 0) : buf(new char[n+1]) { buf[0] = '\0'; }
  string(const char* b) : buf(new char[strlen(b)+1]) { 
    strcpy(buf, b);
  }
  string(const string& s) : buf(new char[strlen(s.buf)+1]) { 
    strcpy(buf, s.buf);
  }
  ~string() { delete [] buf; }
  char& operator[](int index) { return buf[index]; }
  const char& operator[](int index) const { return buf[index]; }
  const char* getBuf() const { return buf; }
  string& operator=(const string&);
  string operator+(const string&);
private:
  char* buf;
};

string string::operator+(const string& rhs) {
  string temp(strlen(buf)+strlen(rhs.buf));
  strcpy(temp.buf, buf);
  strcat(temp.buf, rhs.buf);
  return temp;
}

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
  string a("dog"), b("cat"); 
  const string c(b);
  b[0] = 'b';
  std::cout << b << std::endl;
  std::cout << c[0] << std::endl;
  std::cout << c[1] << std::endl;
  std::cout << a+b << std::endl;
}
