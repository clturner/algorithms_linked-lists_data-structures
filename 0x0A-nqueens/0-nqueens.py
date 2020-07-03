#!/usr/bin/python3

import sys

global N
board = []
queens = []
first_column = []

sys.setrecursionlimit(18500)

if len(sys.argv) is 1:
    print("Usage: nqueens N")
    sys.exit(1)

N = sys.argv[1]

try:
    int(N)
except:
    print("N must be a number")
    sys.exit(1)

if int(N) < 4:
    print("N must be at least 4")
    sys.exit(1)


def safe(board, row, column):

    for i in range(len(queens)):
        coords = queens[i]
        r = coords[0]
        c = coords[1]
        if row == r:
            return(False)
        elif column == c:
            return(False)
        elif (r-c) == (row-column):
            return(False)
        elif (r+c) == (row+column):
            return(False)
    return(True)


def place(board, row, column):
    if column >= int(N):
        return(True)

    if safe(board, row, column) is True:
        board[row][column] = 1

        if column == 0:
            idx = []
            idx.append(row)
            idx.append(column)
            first_column.append(idx)
            idx = []

        idx = []
        idx.append(row)
        idx.append(column)
        queens.append(idx)
        idx = []

        if column >= int(N)-1:
            print(queens)
            return(True)

        column += 1
        row = 0
        place(board, row, column)
    else:
        row += 1

    if row == int(N):
        l = queens[-1]
        row = l[0]
        column = l[1]
        board[row][column] = 0
        row += 1
        del queens[-1]

        if row >= int(N):
            if len(first_column) == int(N):
                sys.exit()
            l = queens[-1]
            row = l[0]
            column = l[1]
            board[row][column] = 0
            row += 1
            del queens[-1]
    place(board, row, column)


def nQueens_board(N):

    count = 0
    for i in range(0, int(N)):
        board_row = []
        for j in range(0, int(N)):
            count += 1
            board_row.append(0)
        board.append(board_row)

nQueens_board(int(N))

place(board, 0, 0)
