#include <iostream>
#include <string>
#include <vector>
#define max_size 100
using namespace std;

vector<int> digits;
vector<char> operators;

int m[max_size][max_size], M[max_size][max_size];

int op(int a, int b, char op)
{
  int res;
  switch(op)
  {
    case '+':
      res = a + b;
      break;
    case '-':
      res = a - b;
      break;
    case '*':
      res = a * b;
      break;
    default:
      res = a / b;
  }
  return res;
}

int min(int i, int j)
{
  int min = 9999, a, b, c, d;
  for(int k = i; k < j; k++)
  {
    a = op(M[i][k], M[k+1][j], operators[k]);
    b = op(M[i][k], m[k+1][j], operators[k]);
    c = op(m[i][k], M[k+1][j], operators[k]);
    d = op(m[i][k], m[k+1][j], operators[k]);

    min = std::min(min,std::min(std::min(std::min(a,b),c),d));
  }
  return min;
}

int max(int i, int j)
{
  int max = -9999, a, b, c, d;
  for(int k = i; k < j; k++)
  {
    a = op(M[i][k], M[k+1][j], operators[k]);
    b = op(M[i][k], m[k+1][j], operators[k]);
    c = op(m[i][k], M[k+1][j], operators[k]);
    d = op(m[i][k], m[k+1][j], operators[k]);

    max = std::max(max,std::max(std::max(std::max(a,b),c),d));
  }
  return max;
}


int main()
{
  string str;  cin >> str; digits.push_back(0); operators.push_back(0);
  int size = str.length();
  for(int i = 0; i < size; i++)
    if(i % 2 == 0)// is a digit
      digits.push_back(str[i] - '0');
    else // is  an operator
      operators.push_back(str[i]);

  size = digits.size()-1;

  for(int i = 1; i <= size; i++){ m[i][i] = digits[i]; M[i][i] = digits[i]; }
  for(int s = 1; s < size; s++)
  {
    for(int i = 1; i <= size - s; i++)
    {
      int j = i + s;
      int mi = min(i,j);
      int ma = max(i,j);

      m[i][j] = mi;
      M[i][j] = ma;
    }
  }

  cout << M[1][digits.size() - 1] << endl;

  return 0;
}


