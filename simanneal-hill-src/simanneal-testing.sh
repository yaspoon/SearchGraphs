#!/bin/bash
for i in {1..100}
do
	./simanneal-hill -map $1 -testing -startTemp 3000
done
