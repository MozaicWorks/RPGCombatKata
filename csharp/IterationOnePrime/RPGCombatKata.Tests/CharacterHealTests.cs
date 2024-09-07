namespace RPGCombatKata.Tests{
	public class CharacterHealTests
	{
		[Fact]
		public void HealingACharacterIncreasesTheirHealth()
		{
			var character = CharacterBuilder.ACharacter().AliveWithHealth(800).Build();
			var healer = new Character();

			healer.Heal(character, 100);

			new CharacterAsserts(character).HasHealth(900);
		}

		[Fact]
		public void HealingACharacterHasHealthCappedAt1000()
		{
			var character = CharacterBuilder.ACharacter().AliveWithHealth(800).Build();
			var healer = new Character();

			healer.Heal(character, 300);

			new CharacterAsserts(character).IsAliveAtFullHealth();
		}
	}
}
