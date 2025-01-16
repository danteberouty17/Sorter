# Sorter
This project consists of a multithreaded sorter. A text file of 100,000 six-digit numbers is used
as the input. These numbers are randomly generated and ordered. From here, the program splits the
list into 'x' amount of groups. The sorting algorithm is then run on these groups. Currently, it is
hard coded to run on 8 cores since that was most optimal for my machine, allowing it to run faster
than Linux's built in sort function.

Example log output:
`
My machine has this many processors
12

Running the script with this many processors
8

Generating 1000000 random numbers
arg[0]:generate
arg[1]:1000000
arg[2]:100000
arg[3]:999999

Starting system sort
real	0m0.140s
user	0m0.511s
sys	0m0.054s

Starting my sort
real	0m0.187s
user	0m0.270s
sys	0m0.045s
All done
`