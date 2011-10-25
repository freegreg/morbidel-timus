#!/bin/bash


for i in {1..9}
do
  ./binary < ../misc/teste/1238\ -\ Folding/folding0$i.in
  cat ../misc/teste/1238\ -\ Folding/folding0$i.ok
done

for i in {10..41}
do
    ./binary < ../misc/teste/1238\ -\ Folding/folding$i.in
    cat ../misc/teste/1238\ -\ Folding/folding$i.ok
done

