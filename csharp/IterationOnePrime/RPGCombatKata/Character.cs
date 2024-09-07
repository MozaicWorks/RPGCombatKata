namespace RPGCombatKata{
	public class Character
	{
		private int myHealth;
		private bool alive;
		private int myLevel;

		public Character(){
			this.myHealth = 1000;
			this.myLevel = 1;
			this.alive = true;
		}

		public int Health()
		{
			return myHealth;
		}

		public bool IsAlive()
		{
			return alive;
		}

		public int Level()
		{
			return myLevel;
		}

		public void DealDamage(Character defender, int damage)
		{
			if (defender.Health() < damage)
			{
				defender.alive = false;
				defender.myHealth = 0;
			}
			else
			{
				defender.myHealth -= damage;
			}
		}

		public void Heal(Character patient, int healing)
		{
			if (!patient.IsAlive())
			{
				return;
			}
			if (patient.Health() + healing > 1000)
			{
				patient.myHealth = 1000;
			}
			else
			{
				patient.myHealth += healing;
			}
		}
	}
}
