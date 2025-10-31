# Maze Solver using Backtracking (DAA Project)

### 👨‍💻 Project Overview
This project finds a path through a maze using the **Backtracking algorithm**.  
The maze is represented as a grid where:
- `0` = path
- `1` = wall  

The goal is to reach the bottom-right corner from the top-left corner.

---

### 📂 Files in this Project
- **maze.c** → Main program (written in C)
- **input.txt** → Contains maze input
- **output_example.txt** → Example output
- **screenshots/** → Stores images of program output

---

### ⚙️ How to Run
1. Open any C compiler (Code::Blocks, Turbo C, OnlineGDB, etc.)
2. Keep `maze.c` and `input.txt` in the same folder.
3. Compile and run `maze.c`
4. Program will read the maze from `input.txt` and display:
   - Whether a path exists
   - Which cells were visited

---

### 🧠 Algorithm Used
- **Backtracking** (Depth-First Search approach)
- Recursively explores all possible paths until it finds a valid route.

---

### 🕒 Time Complexity
- **Worst Case:** O(4^(n²))  
  (Each cell can have up to 4 possible moves)

---

### 📊 Example Input

