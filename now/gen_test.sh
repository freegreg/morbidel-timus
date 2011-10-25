#!/bin/bash

for i in {1..1000}
do
  echo "running test$i"
  ./binary | grep ERROR
  sleep 1
done
