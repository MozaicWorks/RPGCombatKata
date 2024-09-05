namespace RPGCombatKata.Tests
{
	public class CharacterTests
	{
		[Fact]
		public void NewCharacterHealthIs1000()
		{
			var character = new Character();

			Assert.Equal(1000, character.Health());
		}

		[Fact]
		public void NewCharacterIsAlive()
		{
			var character = new Character();

			Assert.True(character.IsAlive());
		}

		[Fact]
		public void NewCharacterHasLevel1()
		{
			var character = new Character();

			Assert.Equal(1, character.Level());
		}

		[Fact]
		public void DealDamage()
		{
			var attacker = new Character();
			var defender = new Character();

			attacker.DealDamage(defender, 100);

			Assert.Equal(900, defender.Health());
		}

		[Fact]
		public void HealthBecomesZeroWhenDamageHigherThanHealth()
		{
			var attacker = new Character();
			var defender = new Character();

			attacker.DealDamage(defender, 1100);

			Assert.Equal(0, defender.Health());
		}

		[Fact]
		public void DefenderDiesWhenDamageHigherThanHealth()
		{
			var attacker = new Character();
			var defender = new Character();

			attacker.DealDamage(defender, 1100);

			Assert.False(defender.IsAlive());
		}

		[Fact]
		public void HealingACharacterIncreasesTheirHealth()
		{
			var attacker = new Character();
			var defender = new Character();
			var healer = new Character();
			attacker.DealDamage(defender, 200);

			healer.Heal(defender, 100);

			Assert.Equal(900, defender.Health());
		}

		[Fact]
		public void HealingACharacterHasHealthCappedAt1000()
		{
			var attacker = new Character();
			var defender = new Character();
			var healer = new Character();
			attacker.DealDamage(defender, 200);

			healer.Heal(defender, 300);

			Assert.Equal(1000, defender.Health());
		}

		[Fact]
		public void HealingHasNoEffectOnDeadCharactersHealth()
		{
			var attacker = new Character();
			var defender = new Character();
			var healer = new Character();
			attacker.DealDamage(defender, 1100);

			healer.Heal(defender, 300);

			Assert.Equal(0, defender.Health());
		}

		[Fact]
		public void HealingDoesNotReviveADeadCharacter()
		{
			var attacker = new Character();
			var defender = new Character();
			var healer = new Character();
			attacker.DealDamage(defender, 1100);

			healer.Heal(defender, 300);

			Assert.False(defender.IsAlive());
		}
	}
}
