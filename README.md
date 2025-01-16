# Sorter
This project consists of a multithreaded sorter. A text file of 100,000 six-digit numbers is used
as the input. These numbers are randomly generated and ordered. From here, the program splits the
list into 'x' amount of groups. The sorting algorithm is then run on these groups. Currently, it is
hard coded to run on 8 cores since that was most optimal for my machine, allowing it to run faster
than Linux's built in sort function.