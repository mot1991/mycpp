#!/bin/bash
valgrind -v --tool=memcheck --leak-check=full --show-mismatched-frees=yes $1
