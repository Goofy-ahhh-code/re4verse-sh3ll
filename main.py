import socket
# i added these comments not chatgpt
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(("127.0.0.1", 8080))  # store as variables later, maybe use command line arguments for that

s.send("message\n".encode()) # figure out a username system
s.send("exit".encode()) # figure out a username system
s.close()


