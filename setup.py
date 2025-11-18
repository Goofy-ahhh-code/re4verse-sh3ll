import subprocess
import os

os.system("gcc main.c -o server")
subprocess.Popen(["gnome-terminal", "--", "./server", "8080"])
subprocess.Popen(["gnome-terminal", "--", "python3", "main.py"]) 
