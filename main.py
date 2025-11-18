import socket
import os
# i added these comments not chatgpt
user = input("Enter your username: ")
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(("127.0.0.1", 8080))  # store as variables later, maybe use command line arguments for that
message = ""
while message != "end":
  message = input("Enter your message: ")
  s.send(f"{user}: {message}".encode()) # figure out a username system



s.close()

