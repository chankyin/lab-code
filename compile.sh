#!/bin/bash
fileId=lab${1}_${2}
g++ -g -std=c++11 -pedantic-errors ${fileId}.cpp -o ${fileId} \
  && ./${fileId}
