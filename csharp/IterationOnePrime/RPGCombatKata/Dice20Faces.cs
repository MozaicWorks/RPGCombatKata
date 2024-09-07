namespace RPGCombatKata
{
	public class Dice20Faces : Dice
	{
		Random random;
 
		public Dice20Faces()
		{
			random = new Random();
		}

		public int Roll()
		{
			return random.Next(1, 21);
		}
	}
}
