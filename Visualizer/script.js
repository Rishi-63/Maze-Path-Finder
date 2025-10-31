const mazeContainer = document.getElementById("maze");
const size = 30;
let maze = [];
let start = [0, 0];
let end = [size - 1, size - 1];

// Generate random maze
function generateMaze() {
  mazeContainer.innerHTML = "";
  maze = Array.from({ length: size }, () =>
    Array.from({ length: size }, () => (Math.random() < 0.25 ? 1 : 0))
  );
  maze[0][0] = 0;
  maze[size - 1][size - 1] = 0;

  mazeContainer.style.gridTemplateColumns = `repeat(${size}, 20px)`;
  mazeContainer.style.gridTemplateRows = `repeat(${size}, 20px)`;

  for (let i = 0; i < size; i++) {
    for (let j = 0; j < size; j++) {
      const cell = document.createElement("div");
      cell.classList.add("cell");
      if (maze[i][j] === 1) cell.classList.add("wall");
      if (i === 0 && j === 0) cell.classList.add("start");
      if (i === size - 1 && j === size - 1) cell.classList.add("end");
      mazeContainer.appendChild(cell);
    }
  }
}

// BFS for shortest path
async function solveMaze() {
  const dirs = [
    [1, 0],
    [0, 1],
    [-1, 0],
    [0, -1],
  ];
  const visited = Array.from({ length: size }, () => Array(size).fill(false));
  const parent = Array.from({ length: size }, () => Array(size).fill(null));
  const queue = [[0, 0]];
  visited[0][0] = true;

  while (queue.length > 0) {
    const [x, y] = queue.shift();
    const idx = x * size + y;
    const cell = mazeContainer.children[idx];
    if (!(x === 0 && y === 0)) {
      cell.classList.add("visited");
      await new Promise((res) => setTimeout(res, 20)); // medium-slow speed
    }

    if (x === size - 1 && y === size - 1) {
      drawPath(parent);
      return;
    }

    for (let [dx, dy] of dirs) {
      const nx = x + dx,
        ny = y + dy;
      if (
        nx >= 0 &&
        ny >= 0 &&
        nx < size &&
        ny < size &&
        !visited[nx][ny] &&
        maze[nx][ny] === 0
      ) {
        visited[nx][ny] = true;
        parent[nx][ny] = [x, y];
        queue.push([nx, ny]);
      }
    }
  }

  alert("No Path Found!");
}

async function drawPath(parent) {
  let [x, y] = [size - 1, size - 1];
  const path = [];

  while (x !== 0 || y !== 0) {
    path.push([x, y]);
    [x, y] = parent[x][y];
  }

  for (let [px, py] of path.reverse()) {
    const idx = px * size + py;
    const cell = mazeContainer.children[idx];
    cell.classList.add("path");
    await new Promise((res) => setTimeout(res, 30));
  }
}

// Buttons
document.getElementById("generateBtn").addEventListener("click", generateMaze);
document.getElementById("solveBtn").addEventListener("click", solveMaze);

// Initial maze
generateMaze();
