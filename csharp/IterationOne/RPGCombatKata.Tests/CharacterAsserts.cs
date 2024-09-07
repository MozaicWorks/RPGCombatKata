using Xunit;

namespace RPGCombatKata.Tests
{

	public class CharacterAsserts
	{
		private readonly Character character;

		public CharacterAsserts(Character character)
		{
			this.character = character;
		}

		public void HasFullHealth()
		{
			Assert.Equal(1000, character.Health());
		}

		public void IsAlive()
		{
			Assert.True(character.IsAlive());
		}

		public void IsAliveAtFullHealth()
		{
			IsAlive();
			HasFullHealth();
		}

		public void IsNotAlive()
		{
			Assert.False(character.IsAlive());
		}

		public void HasNoHealth()
		{
			Assert.Equal(0, character.Health());
		}

		public void IsDead()
		{
			IsNotAlive();
			HasNoHealth();
		}

		public void HasHealth(int expectedHealth)
		{
			Assert.Equal(expectedHealth, character.Health());
		}

		public void IsAtLevel(int expectedLevel)
		{
			Assert.Equal(expectedLevel, character.Level());
		}

		public void IsNewAndValid()
		{
			IsAliveAtFullHealth();
			IsAtLevel(1);
		}
	}
}
