 /*---------------------------------------------------
 Name: Zamam Moeez
 ID: 1665264
 CMPUT 275 , Winter 2022
 CCID: zamam

 Exercise 3 Part 1: Sales
 ---------------------------------------------------*/
#include <iostream>

#include <unordered_map>

using namespace std;

int main() {
  int length;  // declare number of items
  int target;  // declare target sale
  int item;  // declare individual item
  unordered_map < int, int > map;  // initialise unordered map for int

  cin >> length;  // input number of items
  cin >> target;  // input target sale

  for (int i = 0; i < length; i++) {  // iterate throught items
    cin >> item;  // input item

    if (map.find(target - item) != map.end()) {  // if addend found in map
      cout << "YES" << endl;  // print YES and exit
      return 0;
    }

    map[item] = i;  // else add item to map
  }

  cout << "NO" << endl;  // if no such pair exists print NO and exit

  return 0;
}
