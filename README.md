# Circular Buffer in C

Simple implementation of a circular buffer (ring buffer) using a fixed-size array.  
Supports enqueue (write) and dequeue (read) operations with wrap-around logic.  
Buffer is empty when head == tail, and full when next tail equals head.  

## Features
- No extra memory (no dynamic allocation)
- Efficient O(1) operations
- Overflow and underflow handling

## Usage
Compile with: `gcc main.c -o app`  
Run: `./app`
