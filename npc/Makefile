all:
	verilator --cc --exe --build --trace -j 1 -Wall csrc/main.cpp vsrc/top.v

sim: all
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	./obj_dir/Vtop

include ../Makefile
