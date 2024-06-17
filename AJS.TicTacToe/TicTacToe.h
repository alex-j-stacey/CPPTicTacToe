#pragma once
#include <iostream>

class TicTacToe
{
private:

	char m_board[5][5] = {
			{ ' ', '|', ' ', '|', ' '},
			{ '-', '-', '-', '-', '-'},
			{ ' ', '|', ' ', '|', ' '},
			{ '-', '-', '-', '-', '-'},
			{ ' ', '|', ' ', '|', ' '}
	};
	int m_numTurns = 0;
	char m_winner = ' ';

public:

	TicTacToe() 
	{
		char m_boardchar[5][5];
		int m_numTurns;
		char m_winner;
	}

	void DisplayBoard()
	{
		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 5; x++)
			{
				std::cout << m_board[y][x];
			}
			std::cout << "\n";
		}
	}

	bool IsOver()
	{
		if (m_numTurns == 9) { return true; }

		if (m_board[0][0] == 'X' && m_board[0][2] == 'X' && m_board[0][4] == 'X') { m_winner = 'X'; return true; }
		if (m_board[2][0] == 'X' && m_board[2][2] == 'X' && m_board[2][4] == 'X') { m_winner = 'X'; return true; }
		if (m_board[4][0] == 'X' && m_board[4][2] == 'X' && m_board[4][4] == 'X') { m_winner = 'X'; return true; }

		if (m_board[0][0] == 'X' && m_board[2][0] == 'X' && m_board[4][0] == 'X') { m_winner = 'X'; return true; }
		if (m_board[0][2] == 'X' && m_board[2][2] == 'X' && m_board[4][2] == 'X') { m_winner = 'X'; return true; }
		if (m_board[0][4] == 'X' && m_board[2][4] == 'X' && m_board[4][4] == 'X') { m_winner = 'X'; return true; }

		if (m_board[0][0] == 'O' && m_board[0][2] == 'O' && m_board[0][4] == 'O') { m_winner = 'O'; return true; }
		if (m_board[2][0] == 'O' && m_board[2][2] == 'O' && m_board[2][4] == 'O') { m_winner = 'O'; return true; }
		if (m_board[4][0] == 'O' && m_board[4][2] == 'O' && m_board[4][4] == 'O') { m_winner = 'O'; return true; }

		if (m_board[0][0] == 'O' && m_board[2][0] == 'O' && m_board[4][0] == 'O') { m_winner = 'O'; return true; }
		if (m_board[0][2] == 'O' && m_board[2][2] == 'O' && m_board[4][2] == 'O') { m_winner = 'O'; return true; }
		if (m_board[0][4] == 'O' && m_board[2][4] == 'O' && m_board[4][4] == 'O') { m_winner = 'O'; return true; }

		if (m_board[0][0] == 'X' && m_board[2][2] == 'X' && m_board[4][4] == 'X') { m_winner = 'X'; return true; }
		if (m_board[0][4] == 'X' && m_board[2][2] == 'X' && m_board[4][0] == 'X') { m_winner = 'X'; return true; }

		if (m_board[0][0] == 'O' && m_board[2][2] == 'O' && m_board[4][4] == 'O') { m_winner = 'O'; return true; }
		if (m_board[0][4] == 'O' && m_board[2][2] == 'O' && m_board[4][0] == 'O') { m_winner = 'O'; return true; }

		else { return false; }

	}

	char GetPlayerTurn() 
	{
		if (m_numTurns == 0 || m_numTurns == 2 || m_numTurns == 4 || m_numTurns == 6 || m_numTurns == 8)
		{
			return 'X';
		}
		else { return 'O'; }
	}

	bool IsValidMove(int position)
	{
		if (position == 1 && *m_board[0, 0] == ' ') { return true; }
		else if (position == 2 && m_board[0][2] == ' ') { return true; }
		else if (position == 3 && m_board[0][4] == ' ') { return true; }
		else if (position == 4 && m_board[2][0] == ' ') { return true; }
		else if (position == 5 && m_board[2][2] == ' ') { return true; }
		else if (position == 6 && m_board[2][4] == ' ') { return true; }
		else if (position == 7 && m_board[4][0] == ' ') { return true; }
		else if (position == 8 && m_board[4][2] == ' ') { return true; }
		else if (position == 9 && m_board[4][4] == ' ') { return true; }
		else { std::cout << "Spot already taken" << "\n"; return false; }
	}
	
	void Move(int position)
	{
		if (position == 1) { m_board[0][0] = GetPlayerTurn(); m_numTurns++; }
		if (position == 2) { m_board[0][2] = GetPlayerTurn(); m_numTurns++; }
		if (position == 3) { m_board[0][4] = GetPlayerTurn(); m_numTurns++; }
		if (position == 4) { m_board[2][0] = GetPlayerTurn(); m_numTurns++; }
		if (position == 5) { m_board[2][2] = GetPlayerTurn(); m_numTurns++; }
		if (position == 6) { m_board[2][4] = GetPlayerTurn(); m_numTurns++; }
		if (position == 7) { m_board[4][0] = GetPlayerTurn(); m_numTurns++; }
		if (position == 8) { m_board[4][2] = GetPlayerTurn(); m_numTurns++; }
		if (position == 9) { m_board[4][4] = GetPlayerTurn(); m_numTurns++; }
	}

	void DisplayResult()
	{
		if (m_winner == 'X') { std::cout << "X is the winner!" << "\n"; }
		if (m_winner == 'O') { std::cout << "O is the winner!" << "\n"; }
		else if (m_winner == ' ') { std::cout << "It's a tie!" << "\n"; }
	}
};