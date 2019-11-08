# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary. 

flood_fill: stack_ll.o driver.o
	c99 -o flood_fill stack_ll.o driver.o

stack_ll.o: stack_ll.c
	c99 -c stack_ll.c

driver.o: driver.c
	c99 -c driver.c
