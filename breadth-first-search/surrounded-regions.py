import collections
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        visited = set()

        def bfs(x, y):
            if board[x][y] == "O":
                board[x][y] = "N"
            q = collections.deque()
            q.append((x, y))
            visited.add((x, y))
            while q:
                cur_x, cur_y = q.popleft()
                dirs = [[1,0],[-1,0],[0,1],[0,-1]]
                for dx, dy in dirs:
                    next_x, next_y = cur_x + dx, cur_y + dy
                    if (next_x, next_y) not in visited and -1 < next_x < len(board) and -1 < next_y < len(board[0]) and board[next_x][next_y] == "O":
                        board[next_x][next_y] = "N"
                        q.append((next_x, next_y))
                        visited.add((next_x, next_y))

        edges = collections.deque()
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == "O" and (i == 0 or i == len(board)-1 or j == 0 or j == len(board[0])-1):
                    edges.append((i,j))
        while edges:
            search_x, search_y = edges.popleft()
            bfs(search_x, search_y)
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == "O":
                    board[i][j] = "X"
                elif board[i][j] == "N":
                    board[i][j] = "O"
        return