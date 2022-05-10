N = int(input())
board = [0]*N
for i in range(N):
    board[i]=[0]*N
board[0]=list(input())

for row in range(N-1):
    for col in range(N):
        black=0
        if row>0:
            if board[row-1][col]=='#':
                black+=1
        if col>0:
            if board[row][col-1]=='#':
                black+=1
        if col<N-1:
            if board[row][col+1]=='#':
                black+=1
                
        if black%2==1:
            board[row+1][col]='#'
        else:
            board[row+1][col]='.'

s=''
for row, line in enumerate(board):
    for col, tile in enumerate(line):
        s+=board[row][col]
    s+='\n'
print(s)