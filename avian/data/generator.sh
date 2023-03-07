#!/bin/bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

use_solution ../cheat.cpp
compile gen_random.py

group g1 30
limits c=3 k=4
for i in {0..15}
do
tc subtask1-`printf "%02d" $i` gen_random c=3 k=4
done

group g2 25
limits c=2 k=4 even=1
for i in {0..15}
do
tc subtask2-`printf "%02d" $i` gen_random c=2 k=4 n=998
done

group g3 20
limits c=2 k=4
for i in {0..15}
do
tc subtask3-`printf "%02d" $i` gen_random c=2 k=4
done

group g4 25
limits c=3 k=5
for i in {0..9}
do
tc subtask4-`printf "%02d" $i` gen_random c=3 k=5
done
for i in {10..15}
do
tc subtask4-`printf "%02d" $i` gen_random c=3 k=5 n=998
done