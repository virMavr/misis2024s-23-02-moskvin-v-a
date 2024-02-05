#include "complex/complex.hpp"

bool testParse(const std::string& str)
{
  using namespace std;
  istringstream istrm(str); //ограниченный cin 
  Complex z;
  istrm >> z;
  if (istrm.good()) {
    cout << "Read success: " << str << " -> " << z << endl;
  }
  else {
    cout << "Read error : " << str << " -> " << z << endl;
  }
  return istrm.good();
}

bool testAddition(const std::string& str)
{
  using namespace std;
  istringstream istrm(str);
  Complex a, b, c;
  Complex z(8.0);
  cout << z << endl;
  istrm >> a >> b >> c;
  if (a + b == c) {
    cout << "Addition correct: " << a << " + " << b << " = " << c << endl;
  }
  else {
    cout << "Addition INcorrect: " << a << " + " << b << " != " << c << endl;
  }
  return (a + b == c);
}

bool testSubtraction(const std::string& str)
{
  using namespace std;
  istringstream istrm(str);
  Complex a, b, c;
  istrm >> a >> b >> c;
  if (a - b == c) {
    cout << "Substraction correct: " << a << " - " << b << " = " << c << endl;
  }
  else {
    cout << "Substraction INcorrect: " << a << " - " << b << " != " << c << endl;

  }
  return a - b == c;
}
int main()
{
  Complex z;
  z += Complex(8.0);
  testParse("{8.9,9}");
  testParse("{8.9, 9}");
  testParse("{8.9,9 }");
  testAddition("{1,2}{3,4}{4,6}");
  testSubtraction("{5,6}{3,3}{2,2}");
  return 0;
}