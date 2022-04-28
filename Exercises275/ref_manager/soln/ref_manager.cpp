 /*---------------------------------------------------
 Name: Zamam Moeez
 ID: 1665264
 CMPUT 275 , Winter 2022
 CCID: zamam

 Exercise 3 Part 2: Reference Manager
 ---------------------------------------------------*/
#include "ref_manager.h"
#include <string>
#include <cassert>

ReferenceManager::ReferenceManager() {
  numToDelete = 0;
  for (int i = 0; i < MAX_PTRS; i++) {
    pointers[i] = NULL;
  }
}
/* Destructor loops through pointers array freeing up memory
by assigning pointer to NULL and then deleting. Later calls
garbage collect */ 
ReferenceManager::~ReferenceManager() {
  for (int i = 0; i < MAX_PTRS; i++) {  // loops through pointers array
  reassignPointer(i, NULL);  // reassigns each pointer to NULL
  }
  garbageCollect();  // call garbage collect
}

/* garbageCollect() loops through garbage array, printing pointers in the array
then deletes those pointers from memory */
void ReferenceManager::garbageCollect() {
  for (int i = 0; i < numToDelete; i++) {  // loop through the garbage array
    cout << garbage[i] << endl;  // print pointers in in need of deletion
    delete garbage[i];  // delete those pointers
  }
numToDelete = 0;  // reset numtoDelete to 0
}

/* reassignPointer reassigns pointer in pointers array at ptrIndex to
neAddr. Correspondingly changes the refCount for both new pointer and old one */
void ReferenceManager::reassignPointer(unsigned int ptrIndex,
  const char * newAddr) {
  if (newAddr != NULL) {  // if the newAddr exists
    refCount[newAddr]++;  // increase reference count by 1
  }
  if (pointers[ptrIndex] != NULL) {  // if the pointer exists
    refCount[pointers[ptrIndex]]--;  // decrease refernce count by 1
    if (refCount[pointers[ptrIndex]] == 0) {  // if it decreases to 0
      garbage[numToDelete] = pointers[ptrIndex];  // add it to garbage array
      numToDelete++;  // increase num to delete by 1
    }
  }
  pointers[ptrIndex] = newAddr;  // reassign pointer to reference newAddr
}

/* readString reads in string of length and reassgins pointer at ptrIndex in the pointers
array to that string */
void ReferenceManager::readString(unsigned int ptrIndex, unsigned int length) {
  char * rstring = new char[length + 1];  // dynamically declare string
  for (unsigned int i = 0; i < length; i++) {  // take input for each char
    cin >> rstring[i];
  }
  rstring[length] = '\0';  // add null char at the end
  reassignPointer(ptrIndex, rstring);  // call reassign to point to rstring
}

const char* ReferenceManager::getPtr(unsigned int ptrIndex) {
  assert(ptrIndex < MAX_PTRS);
  return pointers[ptrIndex];
}
