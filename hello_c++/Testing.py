from collections import deque
import heapq


class Pass:


    def find_start_goal(self,grid):
        start = goal = None
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if grid[r][c] == 'S':
                    start = (r, c)
                elif grid[r][c] == 'G':
                    goal = (r, c)
        return start, goal


    def get_neighbors(self,pos, grid):
        r, c = pos
        moves = [(0,1), (1,0), (0,-1), (-1,0)]
        result = []

        for dr, dc in moves:
            nr, nc = r + dr, c + dc
            if 0 <= nr < len(grid) and 0 <= nc < len(grid[0]):
                if grid[nr][nc] != '#':
                    result.append((nr, nc))
        return result


    # ---- IMPLEMENT ONE OF THESE ----

   

    def astar(self,grid):
        """Informed search with Manhattan heuristic"""
        pass
    def bfs (self, grid, direction_x, direction_y, pos_obstacles):
        x = direction_x
        y = direction_y
        for p, v in enumerate(grid):
            for ns in v:
                
                if (x,y) in pos_obstacles:
                    y-1
                    break
                if ns == '#':
                    pos_obstacles.append((x+1,y))
                    self.bfs(grid, 0,y,pos_obstacles)
                x+=1
                if ns == 'G':
                    return
                

if __name__ == '__main__':

    pass_class = Pass()
    """
    grid = [
        "S..#...",
        ".#.#..#",
        ".#....#",
        "...##..",
        "#.....G"
    ]
    """
    grid = ["S..#...",
                ".#....",
                ".....G"]

    # choose algorithm here
    dictionary_path = dict()
    list_obstacles = list()
    path = pass_class.bfs( grid, 0, 0, list_obstacles)
    ns = len(ds)
    print(len(path))
    # path = astar(grid)













""""
You are given a 2D grid that represents a small map.

S = start position

G = goal position

# = obstacle (cannot cross)

. = free cell

Your task is to write a Python program that finds a path from S to G.

You must implement ONE of the following:

Uninformed Search → Breadth-First Search (BFS)

Informed Search → A* using Manhattan distance heuristic










"""