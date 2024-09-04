#pragma once
class Character{
	private: 
		int myHealth;
		bool alive;
		int myLevel;

	public:
		Character(): myHealth(1000), alive(true), myLevel(1){};
		int health() const;
		int isAlive() const;
		int level() const;
		void dealDamage(Character& defender, int damage);
		void heal(Character& patient, int healing);
};
