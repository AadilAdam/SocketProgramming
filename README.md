# SocketProgramming

The Goal of this assignment is to learn TCP/UDP socket programming. You can use any IP address for client – server communication. 
The programming language for socket is your choice (C,C++ or Java).  It is encouraged to use C/C++ to understand the various primitives of
socket programming for client – server communication in the internet environment.
If you are using C/C++ you have to use system calls such as socket(), bind(), listen(), accept(),connect(), send(),recv(), sendto() & 
recvfrom().

Algorithm (Client Side):

1. Start.
2. Create a socket using socket() system call.
3. Connect the socket to the address of the server using connect() system call.
4. Send the filename of required file using send() system call.
5. Read the contents of the file sent by server by recv() system call.
6. Stop.

Algorithm (Server Side):
1. Start.
2. Create a socket using socket() system call.
3. Bind the socket to an address using bind() system call.
4. Listen to the connection using listen() system call.
5. accept connection using accept()
6. Receive filename and transfer contents of file with client.
7. Stop
