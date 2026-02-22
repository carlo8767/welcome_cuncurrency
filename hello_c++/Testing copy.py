from collections import deque

def shortest_path(grid, x, y):
    m, n = len(grid), len(grid[0])

    # If start or end blocked
    if grid[0][0] == 1 or grid[m-1][n-1] == 1:
        return -1

    # BFS setup
    q = deque()
    q.append((0, 0, 0))   # (row, col, distance)

    visited = set()
    visited.add((0, 0))

    directions = [(1,0), (-1,0), (0,1), (0,-1)]
    current_direction = list()
    # LEFT, LEFT, RIGHT,UP, DOWN 
    while q:
        row, column, distance = q.popleft()

        # 🎯 goal reached
        if row == m-1 and column == n-1:
            return distance
        # expand neighbors
        if 1 == grid[y+1][x]:
                shortest_path(grid,0,-1)
        elif 1 == grid[y][x+1]:
                shortest_path(grid,-1,0 )
        elif 1 == grid[y-1][x]:
                shortest_path(grid,0,+1 )
        elif  1 == grid[y-1][x-1]:
                shortest_path(grid,+1,0 )
        # TODO: implement BFS expansion
        value = grid[y][x]
        if value == 1 and x > len(grid[y]):
           shortest_path(grid,0,-1 )
        q.append(x,y,1)
        visited.append(x,y)


    return -1

grid = [
 [0, 0, 1, 0],
 [0, 0, 0, 0],
 [1, 0, 1, 0],
 [0, 0, 0, 0]
]
shortest_path(grid)