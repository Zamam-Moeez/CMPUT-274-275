/*
Name: Zamam Moeez
SID: 1665264
CCID: zamam
CMPUT 275 , Winter 2022

Exercise 6 Part 1: Bash History
*/
#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
  string lab;  // initilize string label
  string df;  // initialize second entry
  string curr;  // initialize current directory
  int n;  // init number of commands
  cin >> n;  // take input
  std::map < string, set < string >> hist;  // history in map
  curr = "/";  // current directory is root
  hist[curr];  // add current as path(key)
  for (int i = 0; i < n; i++) {  // loop through queries
    cin >> lab;  // take label as input
    cin >> df;  // take second entry
    if (lab == "cd") {  // if label is cd
      if (df == "..") {  // if df is .. move to prev direct
        curr = curr.erase(curr.rfind('/'));
        if (curr == "") {  // if string is empty its in root
          curr = "/";
        }
      } else {
        if (hist.count(df)) {  // if path exists continue
          continue;
        } else if (curr != "/") {
          curr = curr + "/" + df;  // otherwise create new string
        } else {
          curr = curr + df;  // if current is root, no need to add /
        }
        hist[curr];  // add path to hist
      }
    } else if (lab == "ls") {
      hist[curr].insert(df);  // if ls add file to set(value)
    }
  }
  for (auto itr = hist.begin(); itr != hist.end(); ++itr) {
    cout << itr -> first;  // print path
    for (auto it = (itr -> second).begin(); it != (itr -> second).end(); ++it) {
      cout << ' ' << * it;  // print files
    }
    cout << endl;
  }
}

