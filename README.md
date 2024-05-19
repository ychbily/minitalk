# Minitalk

## Overview

Minitalk is a simple client-server communication project developed as part of the curriculum at 42 School. The project aims to implement a basic form of inter-process communication (IPC) using signals in Unix-like operating systems. 

## Features

- **Client-Server Communication:** Implements a client-server model where the client sends messages to the server using signals.
- **Signal Handling:** Demonstrates the use of signal handling techniques for communication between processes.
- **Message Transmission:** Allows the transmission of messages (strings of characters) from the client to the server.
- **Error Handling:** Includes error handling mechanisms to manage signal transmission and reception errors.
- **Acknowledgment:** The server acknowledges every message received by sending back a signal to the client.
- **Unicode Support:** Supports transmission of Unicode characters in messages.

## Usage

**1. Clone the repository:**

```bash
git clone https://github.com/ychbily/minitalk.git
```
**2. Compile the server and client:**
```bash
make
```
or
```bash
make bonus
```

**3. Start the server:**
```bash
./server
```
or
```bash
./server_bonus
```
**4. Start the client with the server's PID and the message to be sent:**
```bash
./client [server_PID] [message]
```
or
```bash
./client_bonus [server_PID] [message]

## Contributing
Contributions to this project are welcome! If you find any issues or have suggestions for improvements, feel free to open an issue or create a pull request.
