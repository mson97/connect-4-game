//
// Created by Minhee Son on 11/17/17.
//

#include <stdio.h>
#include <ctype.h>
#include "valid.h"

bool isValidFormat(const int numArgsRead, const int numArgsNeeded) {
  bool valid = numArgsRead == numArgsNeeded;
  char c;

  do {
    scanf("%c", &c);
    if (!isspace(c)) {
      valid = false;
    }
  } while (c != '\n');

  return valid;
}

bool isInBounds(const int val, const int lower_bound, const int upper_bound) {
  return (val >= lower_bound) && (val <= upper_bound);
}