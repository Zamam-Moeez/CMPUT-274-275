// ---------------------------------------------------
// Name : Zamam Moeez
// ID: 1665264
// CMPUT 275 , Winter 2022

// Exercise 1: Twin Primes
// ---------------------------------------------------

#include <iostream>

using namespace std;

bool isPrime(int n) {  // function declaration for isPrime
  if (n == 0 || n == 1) {  // 0 and 1 are not considered primes
    return false;  // return boolean false
  } else {
    for (int i = 2; i < n; i++) {  // else iterates from 2 to n-1
      if (n % i == 0) {  // if n divisible by i, it is not prime
        return false;  // returns boolean false
      }
    }
  }
  return true;  // if above not true, then it is prime
}

void twinPrimes(int k) {  // function declaration for twinPrime
  int i = 0;  // declare i and assign value 0, first num to be checked
  while (k > 0) {  // begin while loop
    if (isPrime(i) == true && isPrime(i + 2) == true) {  // if i & i+2 are prime
      cout << i << " " << i + 2 << endl;  // output the pair
      k = k - 1;  // keep changing to break loop when k pairs printed
      i = i + 1;  // move on to next num
    } else {
      i = i + 1;  // move on to next num
    }
  }
}

int main() {
  int num;  // declare num
  char q;  // declare query char
  bool prim;  // declare prim as bool
  cin >> q >> num;  // take intput of form "q num"
  if (q == 'p') {  // if q is p
    prim = isPrime(num);  // run isPrime
    if (prim == true) {  // if 1, isPrime is true
      cout << "prime" << endl;
    } else if (prim == false) {  // else not prime
      cout << "not prime" << endl;
    }
  } else if (q == 't') {  // if q is t
    twinPrimes(num);  // run twinPrime
  }
  return 0;
}
