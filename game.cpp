#include <iostream>
#include <string>
#include <random>

void checkValidInput(int &row, int &col) {
    bool validInput = false;
    while (!validInput) {
        std::cout << "Enter row & col: ";
        if (std::cin >> row >> col) {
            if ((row >= 0 && col >= 0) && (row < 3 && col < 3)) {
                validInput = true;
            } else {
                std::cout << "Please enter valid row & col." << std::endl;
            }
        } else {
            std::cout << "Invalid input. Please enter 2 numbers." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

bool isGameBoardFull(const std::vector<std::vector<std::string>>& board) {
    for (const auto& row : board) {
        for (const auto& ele : row) {
            if (ele.empty()) { 
                return false;
            }
        }
    }
    std::cout << "Its a draw!" << std::endl;
    return true;
}

//  Stop judging its O(n) lmao
bool isWin(const std::vector<std::vector<std::string>>& board, std::string player) {

    if (board[0][0] == player && board[0][1] == player && board[0][2] == player) {           // Checks across row 1
        std::cout << "\nCongrats, " << player << " won!" << std::endl;
        return true;
    } else if (board[1][0] == player && board[1][1] == player && board[1][2] == player)  {    // Checks across row 2
        std::cout << "\nCongrats, " << player << " won!" << std::endl;
        return true;
    } else if (board[2][0] == player && board[2][1] == player && board[2][2] == player)  {    // Checks across row 3
        std::cout << "\nCongrats, " << player << " won!" << std::endl;
        return true;
    } else if (board[0][0] == player && board[1][0] == player && board[2][0] == player)  {    // Checks across col 1
        std::cout << "\nCongrats, " << player << " won!" << std::endl;
        return true;
    } else if (board[0][1] == player && board[1][1] == player && board[2][1] == player)  {    // Checks across col 2
        std::cout << "\nCongrats, " << player << " won!" << std::endl;
        return true;
    } else if (board[0][2] == player && board[1][2] == player && board[2][2] == player)  {    // Checks across col 3
        std::cout << "\nCongrats, " << player << " won!" << std::endl;
        return true;
    } else if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {    // Checks across diagnol
        std::cout << "\nCongrats, " << player << " won!" << std::endl;
        return true;
    } else if (board[0][2] == player && board[1][1] == player && board[2][0] == player)  {    // Checks across diagnol
        std::cout << "\nCongrats, " << player << " won!" << std::endl;
        return true;
    } else {
        return false;
    }
    return false;
}

std::string formatCell(const std::string& ele) {
    if (ele.empty()) {
        return " ";
    } else {
        return ele;
    }
}

void printGameBoard(const std::vector<std::vector<std::string>>& board) {
    int count = 0;
    for (const auto& row : board) {
        if (count != 2) {
            std::cout << formatCell(row[0]) << "  | " << formatCell(row[1]) << " |  " << formatCell(row[2]) << std::endl;
            std::cout << "---|---|---" << std::endl;;
        } else {
            std::cout << formatCell(row[0]) << "  | " << formatCell(row[1]) << " |  " << formatCell(row[2]) << std::endl;
        }
        count++;
    }
}

int main() {
    int row, col;
    std::vector<std::vector<std::string>> game_board(3, std::vector<std::string>(3));
    
    while (!isGameBoardFull(game_board) && !isWin(game_board, "X") && !isWin(game_board, "O")) {
        checkValidInput(row, col);
        if (game_board[row][col].empty()) {
            game_board[row][col] = "X";
        } else {
            std::cout << "Rude, Please pick an open spot." << std::endl;
            continue;
        }

        for (size_t attempts = 0; attempts < 9; ++attempts) {
            std::random_device rd;
            std::mt19937 gen(rd()); // Mersenne Twister engine
            std::uniform_int_distribution<> dis(0, 2);

            int randomRow = dis(gen);
            int randomCol = dis(gen);
            if (game_board[randomRow][randomCol].empty()) {
                game_board[randomRow][randomCol] = "O";
                break;
            }
        }
        printGameBoard(game_board);
    }
    return 0;
}