#!/usr/bin/env bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

use_solution pie.cpp

compile random_generator.py

samplegroup
limits maxn=100
sample 01
sample 02
sample 03

group g1 15
limits maxn=15
tc 01
tc 02
tc 13-01 random_generator exactly 1
tc 13-02 random_generator exactly 2
tc 13-03 random_generator exactly 3
tc 13-04 random_generator exactly 4
tc 13-05 random_generator exactly 5
tc 13-06 random_generator exactly 6
tc 13-07 random_generator exactly 7
tc 13-08 random_generator exactly 8
tc 13-09 random_generator exactly 9
tc 13-10 random_generator exactly 10
tc 13-11 random_generator exactly 11
tc 13-12 random_generator exactly 12
tc 13-13 random_generator exactly 13

group g2 10
limits maxn=1000
include_group g1
tc 03
tc 3-01 random_generator random 10**3 10
tc 3-02 random_generator random 10**3 100
tc 3-03 random_generator random 10**3 800
tc 3-04 random_generator squarefree 10**3

group g3 12
limits maxn=100000
include_group g2
tc 5-01 random_generator random 10**5 10
tc 5-02 random_generator random 10**5 100
tc 5-03 random_generator random 10**5 1000
tc 5-04 random_generator squarefree 10**5

group g4 13
limits maxn=5000000
include_group g3
tc 56-01 random_generator random 5*10**6 10
tc 56-02 random_generator random 5*10**6 100
tc 56-03 random_generator random 5*10**6 1000
tc 56-04 random_generator squarefree 5*10**6

group g5 15
limits maxn=100000000
include_group g4
tc 8-01 random_generator random 10**8 10
tc 8-02 random_generator random 10**8 100
tc 8-03 random_generator random 10**8 1000
tc 8-04 random_generator squarefree 10**8

group g6 14
limits maxn=10000000000
include_group g5
tc 10-01 random_generator random 10**10 10
tc 10-02 random_generator random 10**10 100
tc 10-03 random_generator random 10**10 1000
tc 10-04 random_generator squarefree 10**10

group g7 21
limits maxn=10000000000000
include_group g6
tc 12-01 random_generator random 10**13 10
tc 12-02 random_generator random 10**13 100
tc 12-03 random_generator random 10**13 1000
tc 12-04 random_generator squarefree 10**13
