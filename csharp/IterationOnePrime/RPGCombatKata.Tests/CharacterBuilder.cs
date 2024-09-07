namespace RPGCombatKata.Tests{
	public class CharacterBuilder
	{
		private int health;
		private bool alive;

		private CharacterBuilder(){
			this.health = 1000;
			this.alive = true;
		}

		public static CharacterBuilder ACharacter()
		{
			return new CharacterBuilder();
		}

		public CharacterBuilder AliveWithHealth(int health)
		{
			this.health = health;
			this.alive = true;
			return this;
		}

		public CharacterBuilder Dead()
		{
			this.health = 0;
			this.alive = false;
			return this;
		}

		public CharacterBuilder AlmostDeadCharacter()
		{
			return CharacterBuilder.ACharacter().AliveWithHealth(1);
		}

		public Character Build()
		{
			var character = new Character();
			if (health == 1000)
			{
				return character;
			}
			if (!alive)
			{
				var other = new Character();
				other.DealDamage(character, 1001);
				return character;
			}

			var another = new Character();
			another.DealDamage(character, character.Health() - health);
			return character;
		}
	}
}
