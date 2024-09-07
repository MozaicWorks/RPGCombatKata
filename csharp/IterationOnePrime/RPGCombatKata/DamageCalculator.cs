namespace RPGCombatKata
{
	public struct DamageResult
	{
		public int damage;
		public bool isCriticalMiss;
		public bool isCriticalHit;
	};

	public class DamageCalculator
	{
		private Dice d20;

		public DamageCalculator(Dice d20){
			this.d20 = d20;
		}

		public DamageResult ComputeDamage()
		{
			int roll = d20.Roll();

			if(roll == 1) {
				return new DamageResult{damage = 0, isCriticalMiss = true, isCriticalHit = false};
			}

			if(roll == 20){
				return new DamageResult{ damage = 30*roll, isCriticalMiss = false, isCriticalHit = true };
			}

			return new DamageResult{ damage =  15*roll, isCriticalMiss = false, isCriticalHit = false };
		}
	}
}
