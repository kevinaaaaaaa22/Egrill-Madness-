#ifndef GAMEWORLD_H_
#define GAMEWORLD_H_

#include "GameConstants.h"
#include <string>

const int START_PLAYER_LIVES = 3;

class GameController;

class GameWorld
{
public:

	GameWorld(std::string assetPath)
	 : m_lives(START_PLAYER_LIVES), m_score(0), m_level(0),
	   m_controller(nullptr), m_assetPath(assetPath), m_regularEgrills(0), m_pokylanes(0)
	{
	}

	virtual ~GameWorld()
	{
	}

	virtual int init() = 0;
	virtual int move() = 0;
	virtual void cleanUp() = 0;

	void setGameStatText(std::string text);

	bool getKey(int& value);
	void playSound(int soundID);

	int getLevel() const
	{
		return m_level;
	}

	int getLives() const
	{
		return m_lives;
	}

	void decLives()
	{
		m_lives--;
	}

	void setLives(int n)
	{
		m_lives = n;
	}

	void incLives()
    {
		m_lives++;
	}

	int getScore() const
	{
		return m_score;
	}

	void setScore(int n)
	{
		m_score = n;
	}

	void increaseScore(int howMuch)
	{
		m_score += howMuch;
	}

	  // The following should be used by only the framework, not the student

	bool isGameOver() const
	{
		return m_lives == 0;
	}

	void advanceToNextLevel()
	{
		++m_level;
	}

	void setLevel(int n)
	{
		m_level = n;
	}
 
	void setController(GameController* controller)
	{
		m_controller = controller;
	}

	std::string assetPath() const
	{
		return m_assetPath;
	}

	void incEgrills(int type) {
		if (type == REGULAR_EGRILL) m_regularEgrills++;
		else if (type == POKYLANE) m_pokylanes++;
	}

	int getEgrillsCount(int type) {
		if (type == REGULAR_EGRILL) return m_regularEgrills;
		else if (type == POKYLANE) return m_pokylanes;
		return 0;
	}

private:
	int				m_lives;
	int				m_score;
	int				m_level;
	GameController* m_controller;
	std::string		m_assetPath;

	// Record number of egrills collected
	int				m_regularEgrills;
	int				m_pokylanes;
};

#endif // GAMEWORLD_H_





