# Chat app with C and python

This is a proof of concept chat app utilizing C and python with the sockets library

```bash
# compile C code
gcc main.c -o server

# run c code, replace 8080 with correct port
./server 8080

# run python client
python3 main.py

# or just
python3 setup.py
```
# To use

First, find your LAN Internet Protocol (IP) address with the linux command:
```bash
ip addr show
```
then run setup.py on both machines:
```bash
python3 setup.py
```
