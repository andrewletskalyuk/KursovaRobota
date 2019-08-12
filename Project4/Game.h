#pragma once
#include "Navy.h"

class Game
{	
	bool doesItUser;
public:
	Game();
	~Game();	
	void SetDoesItUser(bool _doesItUser);
	bool GetDoesItUser() const;
	bool AreWePlaying(Navy& user, Navy& pc);
	void ShutUser(Navy & navyPC, int x, int y);
	void ShutPC(Navy & navyUser);
};

