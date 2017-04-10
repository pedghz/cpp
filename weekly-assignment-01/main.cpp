#include <iostream>
using namespace std;

int double_(int num);


int main ()
{
  int i;
  int result;
  cout << "Please enter an integer value: ";
  cin >> i;
  cout << "The value you entered is " << i;
  result = double_(i);
  cout << " and its double is " << result << ".\n";
  return 0;
}


int double_(int num)  {
   int result;
   result = num*2;
   return result;
}
