#include <iostream>
#include <fstream> 
using namespace std;

// SUDOKU GAME
class Sudoku
{
    int puzzle[9][9];

public:
    Sudoku()
    {
        int temp[9][9] = {
            {0, 7, 0, 5, 8, 3, 0, 2, 0},
            {0, 5, 9, 2, 0, 0, 3, 0, 0},
            {3, 4, 0, 0, 0, 6, 5, 0, 7},
            {7, 9, 5, 0, 0, 0, 6, 3, 2},
            {0, 0, 3, 6, 9, 7, 1, 0, 0},
            {6, 8, 0, 0, 0, 2, 7, 0, 0},
            {9, 1, 4, 8, 3, 5, 0, 7, 6},
            {0, 3, 0, 7, 0, 1, 4, 9, 5},
            {5, 6, 7, 4, 2, 9, 0, 1, 3},
        };
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                puzzle[i][j] = temp[i][j];
            }
        }
    }

    void display_puzzle()
    {
        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                if (puzzle[r][c] == 0)
                    cout << "- ";
                else
                    cout << puzzle[r][c] << " ";
                if ((c + 1) % 3 == 0 && c != 8)
                    cout << "| ";
            }
            cout << endl;
            if ((r + 1) % 3 == 0 && r != 8)
            {
                cout << "____________________" << endl;
            }
        }
    }

    int Valid_move(int r, int c, int num)
    {
        for (int i = 0; i < 9; i++)
        {
            if (puzzle[r][i] == num)
            {
                return 0;
            }
        }
        for (int i = 0; i < 9; i++)
        {
            if (puzzle[i][c] == num)
            {
                return 0;
            }
        }
        int begrow = (r / 3) * 3;
        int begcol = (c / 3) * 3;
        for (int i = begrow; i < begrow + 3; i++)
        {
            for (int j = begcol; j < begcol + 3; j++)
            {
                if (puzzle[i][j] == num)
                {
                    return 0;
                }
            }
        }
        return 1;
    }

    int move(int r, int c, int num)
    {
        if (puzzle[r][c] != 0)
        {
            cout << "Cell is already filled!!!" << endl;
            return 0;
        }
        if (!Valid_move(r, c, num))
        {
            cout << "Invalid move!!! \nTry again.." << endl;
            return 0;
        }
        puzzle[r][c] = num;
        return 1;
    }

    int solve()
    {
        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                if (puzzle[r][c] == 0)
                {
                    return 0;
                }
            }
        }
        return 1;
    }

    // Save the current puzzle to a file
    void save_puzzle()
    {
        ofstream outFile("d:/sudoku_puzzlee.txt", ios::app);
        if (outFile.is_open())
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    outFile << puzzle[i][j] << " ";
                }
                outFile << endl;
            }
            outFile.close();
            cout << "Puzzle saved successfully!" << endl;
        }
        else
        {
            cout << "Unable to open file for saving!" << endl;
        }
    }

    // Load the puzzle from a file
    void load_puzzle()
    {
        ifstream inFile("sudoku_puzzlee.txt");
        if (inFile.is_open())
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    inFile >> puzzle[i][j];
                }
            }
            inFile.close();
            cout << "Puzzle loaded successfully!" << endl;
        }
        else
        {
            cout << "Unable to open file for loading!" << endl;
        }
    }
};

// TIC TAC TOE GAME
class Tic
{
public:
    void display(char board[3][3])
    {
        cout << "\n==========================\n";
        cout << "   PLAYER 1 [X]   |   PLAYER 2 [O]   \n";
        cout << "==========================\n\n";

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << "  " << board[i][j] << "  ";
                if (j < 2)
                {
                    cout << "|";
                }
            }
            cout << "\n";
            if (i < 2)
            {
                cout << "-----|-----|-----\n";
            }
        }

        cout << "\n==========================\n";
    }

       int check(char board[3][3], char player)
    {
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            {
                return true;
            }
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            {
                return true;
            }
        }

        if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        {
            return true;
        }
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        {
            return true;
        }
        return false;
    }

    // Function to save the game state to a file
    void saveGame(char board[3][3], string player1, string player2, char player, int turn, string winner)
    {
        ofstream outFile("d:/tictactoe.txt", ios::app);
        if (outFile.is_open())
        {
            outFile << player1 << "\n"
                    << player2 << "\n";
            outFile << player << "\n"
                    << turn << "\n";
            outFile << "Winner: " << winner << "\n"; // Save winner's name

            // Save the board
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    outFile << board[i][j] << " ";
                }
                outFile << "\n";
            }
            outFile.close();
            cout << "Game saved successfully!\n";
        }
        else
        {
            cout << "Error saving the game.\n";
        }
    }

    // Function to load the game state from a file
    int loadGame(char board[3][3], string &player1, string &player2, char &player, int &turn)
    {
        ifstream inFile("d:/tictactoe.txt");
        if (inFile.is_open())
        {
            getline(inFile, player1);
            getline(inFile, player2);
            inFile >> player;
            inFile >> turn;

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    inFile >> board[i][j];
                }
            }
            inFile.close();
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

class Piece
{
public:
    char symbol;
    bool isWhite;
    Piece(char sym, bool white) : symbol(sym), isWhite(white) {}
    virtual bool isValidMove(int sx, int sy, int dx, int dy, Piece *board[8][8]) = 0;
};

// Pawn Class
class Pawn : public Piece
{
public:
    bool justmovedtwo = 0;
    Pawn(bool white) : Piece(white ? 'P' : 'p', white) {}
    bool isValidMove(int sx, int sy, int dx, int dy, Piece *board[8][8]) override
    {
        int direction = isWhite ? -1 : 1;
        // Move forward
        if (dx == sx + direction && dy == sy && board[dx][dy] == nullptr)
        {
            justmovedtwo = 0;
            return true;
        }
        // Capture diagonally
        if (dx == sx + direction && abs(dy - sy) == 1 && board[dx][dy] != nullptr && board[dx][dy]->isWhite != isWhite)
        {
            justmovedtwo = 0;
            return true;
        }
        // Double Move
        if ((isWhite && sx == 6 || !isWhite && sx == 1) && dx == sx + 2 * direction && dy == sy && board[dx][dy] == nullptr && board[sx + direction][sy] == nullptr)
        {
            justmovedtwo = 1;
            return true;
        }
        // EN Passant

        if (abs(dy - sy) == 1 && dx == sx + direction && board[dx][dy] == nullptr)
        {
            Piece *adjacent = board[sx][dy];
            if (adjacent != nullptr && adjacent->symbol == (isWhite ? 'p' : 'P') && dynamic_cast<Pawn *>(adjacent)->justmovedtwo)
            {
                delete board[sx][dy];
                board[sx][dy] = nullptr;
                return true;
            }
        }
        return false;
    }
};

// Rook Class
class Rook : public Piece
{
public:
    Rook(bool white) : Piece(white ? 'R' : 'r', white) {}
    bool isValidMove(int sx, int sy, int dx, int dy, Piece *board[8][8]) override
    {
        if (sx != dx && sy != dy)
            return false; // Only horizontal or vertical moves

        // Check if the path is clear
        if (sx == dx)
        {
            for (int i = min(sy, dy) + 1; i < max(sy, dy); ++i)
                if (board[sx][i] != nullptr)
                    return false;
        }
        else
        {
            for (int i = min(sx, dx) + 1; i < max(sx, dx); ++i)
                if (board[i][sy] != nullptr)
                    return false;
        }

        // Destination is either empty or contains opponent's piece
        return (board[dx][dy] == nullptr || board[dx][dy]->isWhite != isWhite);
    }
};

// Knight Class
class Knight : public Piece
{
public:
    Knight(bool white) : Piece(white ? 'N' : 'n', white) {}
    bool isValidMove(int sx, int sy, int dx, int dy, Piece *board[8][8]) override
    {
        int xMove = abs(dx - sx);
        int yMove = abs(dy - sy);
        // checking jump dest is not taken by allied piece
        return ((xMove == 2 && yMove == 1) || (xMove == 1 && yMove == 2)) && (board[dx][dy] == nullptr || board[dx][dy]->isWhite != isWhite);
    }
};

// Bishop Class
class Bishop : public Piece
{
public:
    Bishop(bool white) : Piece(white ? 'B' : 'b', white) {}
    bool isValidMove(int sx, int sy, int dx, int dy, Piece *board[8][8]) override
    {
        if (abs(dx - sx) != abs(dy - sy))
            return false;
        int xStep = (dx - sx) > 0 ? 1 : -1;
        int yStep = (dy - sy) > 0 ? 1 : -1;
        for (int i = 1; i < abs(dx - sx); ++i)
        {
            if (board[sx + i * xStep][sy + i * yStep] != nullptr)
                return false;
        }
        return (board[dx][dy] == nullptr || board[dx][dy]->isWhite != isWhite);
    }
};

// Queen Class
class Queen : public Piece
{
public:
    Queen(bool white) : Piece(white ? 'Q' : 'q', white) {}
    bool isValidMove(int sx, int sy, int dx, int dy, Piece *board[8][8]) override
    {
        Rook rook(isWhite);
        Bishop bishop(isWhite);
        return rook.isValidMove(sx, sy, dx, dy, board) || bishop.isValidMove(sx, sy, dx, dy, board);
    }
};

// King Class
class King : public Piece
{
public:
    King(bool white) : Piece(white ? 'K' : 'k', white) {}
    bool isValidMove(int sx, int sy, int dx, int dy, Piece *board[8][8]) override
    {
        return abs(dx - sx) <= 1 && abs(dy - sy) <= 1;
    }
};

// Board Class
class Board
{
public:
    Piece *grid[8][8];
    Board()
    {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                grid[i][j] = nullptr;

        // Initialize pawns
        for (int i = 0; i < 8; i++)
        {
            grid[1][i] = new Pawn(false);
            grid[6][i] = new Pawn(true);
        }
        // Initialize other pieces
        grid[0][0] = grid[0][7] = new Rook(false);
        grid[7][0] = grid[7][7] = new Rook(true);
        grid[0][1] = grid[0][6] = new Knight(false);
        grid[7][1] = grid[7][6] = new Knight(true);
        grid[0][2] = grid[0][5] = new Bishop(false);
        grid[7][2] = grid[7][5] = new Bishop(true);
        grid[0][3] = new Queen(false);
        grid[7][3] = new Queen(true);
        grid[0][4] = new King(false);
        grid[7][4] = new King(true);
    }
    void display()
    {
        cout << "  A B C D E F G H\n";
        for (int i = 0; i < 8; i++)
        {
            cout << 8 - i << " ";
            for (int j = 0; j < 8; j++)
            {
                if (grid[i][j])
                {
                    cout << grid[i][j]->symbol << " ";
                }
                else
                {
                    cout << ". ";
                }
            }
            cout << 8 - i << "\n";
        }
        cout << "  A B C D E F G H\n";
    }
    bool movePiece(int sx, int sy, int dx, int dy, bool whiteTurn)
    {
        Piece *piece = grid[sx][sy];
        if (dx < 0 || dx >= 8 || dy < 0 || dy >= 8)
            return false;
        if (piece == nullptr)
            return false;
        if (piece->isWhite != whiteTurn)
            return false;
        if (piece->isValidMove(sx, sy, dx, dy, grid))
        {
            delete grid[dx][dy];
            grid[dx][dy] = piece;
            grid[sx][sy] = nullptr;
            return true;
        }
        return false;
    }
};

// Game Class
class Chess_Game
{
public:
    Board board;
    bool whiteTurn;
    Chess_Game() : whiteTurn(true) {}
    void play()
    {
        string player1, player2;
        for (int i = 0; i < 1; i++)
        {
            cout << "Enter name of Player White : ";
            cin >> player1;
            cout << "Enter name of Player Black : ";
            cin >> player2;
        }
        while (true)
        {
            board.display();
            cout << (whiteTurn ? player1 : player2) << "'s turn. Enter move for source point (e.g., E2 or e4) or type 'exit' to return to Menu : ";
            string src, dest;
            cin >> src;
            cout << (whiteTurn ? player1 : player2) << "'s turn. Enter move for destination point (e.g., E2 or e4) or type 'exit' to return to Menu: ";
            cin >> dest;
            if (src == "exit" || dest == "exit")
            {
                cout << "Exiting Chess...\n";
                break;
            }

            int sx = 8 - (src[1] - '0');
            int sy = src[0] - ((src[0] < 'a') ? 'A' : 'a');
            int dx = 8 - (dest[1] - '0');
            int dy = dest[0] - ((dest[0] < 'a') ? 'A' : 'a');
            if (board.movePiece(sx, sy, dx, dy, whiteTurn))
            {
                whiteTurn = !whiteTurn;
            }
            else
            {
                cout << "Invalid move. Try again.\n";
            }
        }
    }
};

int main()
{

    // Ask players for their names
    string player1, player2;
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int turn = 0;
    char player = 'X';
    int row, col;           // Declare row and col here
    string winner = "None"; // Initialize winner

    Tic t;

    // sukoku game
    int r, c, num, ch;
    Sudoku game;

    // chess
    Chess_Game Chess_game;

    do
    {
        cout << "menu\n1.Tic Tac Toe \n2.Sudoku\n3.Chess\n4.exit\n";
        cout << "enter choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            // Check if a save file exists
            cout << "Do you want to load the previous game? (y/n): ";
            char loadChoice1;
            cin >> loadChoice1;

            if (loadChoice1 == 'y' || loadChoice1 == 'Y')
            {
                if (!t.loadGame(board, player1, player2, player, turn))
                {
                    cout << "No saved game found. Starting a new game.\n";
                }
                else
                {
                    cout << "Game loaded successfully!\n";
                }
            }
            else
            {
                // New game setup
                cout << "Enter Player 1's name: ";
                cin >> player1;
                cout << "Enter Player 2's name: ";
                cin >> player2;
            }

            // Game loop
            for (turn; turn < 9; turn++)
            {
                t.display(board);

                // Take entry from user & check for invalid entry
                while (true)
                {
                    cout << "\nPlayer: " << (player == 'X' ? player1 : player2) << " [" << player << "]\n";
                    cout << "Enter row (0-2) and column (0-2), or enter -1 to save and quit: ";
                    cin >> row >> col;

                    // Check for save and quit
                    if (row == -1 || col == -1)
                    {
                        t.saveGame(board, player1, player2, player, turn, winner);
                        break;
                        // return 0; // Exit after saving
                    }

                    // Validate input: row and col should be between 0 and 2, and the cell should be empty
                    if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ')
                    {
                        cout << "Invalid move... Try again\n";
                    }
                    else
                    {
                        break;
                    }
                }

                // Make a move
                board[row][col] = player;

                // Check & display the winner
                if (t.check(board, player))
                {
                    winner = (player == 'X') ? player1 : player2; // Set the winner's name
                    t.display(board);

                    // Bold and Clear Winning Message
                    cout << "\n************************************************\n";
                    cout << "*               CONGRATULATIONS!              *\n";
                    cout << "*       " << winner << " WINS!       *\n";
                    cout << "*            *** WELL PLAYED! ***            *\n";
                    cout << "************************************************\n\n";
                    break;
                }

                // Switch the player
                player = (player == 'X') ? 'O' : 'X';
            }

            t.display(board);

            // Check for draw
            if (turn == 9 && !t.check(board, 'X') && !t.check(board, 'O'))
            {
                cout << "\n************************************************\n";
                cout << "*               IT'S A DRAW!                 *\n";
                cout << "*   No one wins this time... Try again soon!  *\n";
                cout << "************************************************\n\n";
            }

            // Save the game with the final result
            t.saveGame(board, player1, player2, player, turn, winner);

            // return 0;
            break;

        case 2:
            // Ask for the player's name
            char player[100];
            cout << "Enter your name: ";
            cin >> player;

            // Print welcome message
            cout << "\nWelcome " << player << "!!!" << endl;
            // Ask if the player wants to load a saved puzzle
            char loadChoice;
            cout << "Do you want to load a saved puzzle? (y/n): ";
            cin >> loadChoice;
            if (loadChoice == 'y' || loadChoice == 'Y')
            {
                game.load_puzzle();
            }

            // Start Sudoku Game
            int r, c, num;
            char saveChoice;
            cout << "Sudoku Game:-" << endl;
            while (!game.solve())
            {
                game.display_puzzle();
                cout << "\nEnter row(1-9) or -1 to exit :  ";
                cin >> r;
                if (r == -1)
                {
                    game.save_puzzle();
                    break;
                }
                cout << "Enter column(1-9) or -1 to exit : ";
                cin >> c;
                if (c == -1)
                {
                    game.save_puzzle();
                    break;
                }
                cout << "Enter number(1-9) you want to insert or -1 to exit : ";
                cin >> num;
                if (num == -1)
                {
                    game.save_puzzle();
                    break;
                }
                r--;
                c--;
                if (game.move(r, c, num))
                {
                    if (game.solve())
                    {
                        cout << "Congrats!!! Sudoku is solved..." << endl;
                        game.display_puzzle();
                    }
                }

                // Ask if the player wants to save their progress
                cout << "Do you want to save your progress? (y/n): ";
                cin >> saveChoice;
                if (saveChoice == 'y' || saveChoice == 'Y')
                {
                    game.save_puzzle();
                }
            }
            break;

        case 3:
            cout << "Chess Game:-" << endl;
            Chess_game.play();
            break;

        case 4:
            exit(0);
        default:
            cout << "invalid choice";
        }
    } while (1);
    return 0;
}