namespace RPGCombatKata.Tests{
	public class CharacterTestsObjectMother
	{
		[Fact]
		public void NewCharacterIsAliveAtFullHealthAndAtLevel1()
		{
			var character = CharacterBuilder.ACharacter().Build();
			new CharacterAsserts(character).IsNewAndValid();
		}

		[Theory]
		[MemberData(nameof(GetDamageScenarios))]
		public void DefendersHealthDecreasesAfterAnAttackerDealsDamage(int defenderInitialHealth, int damage, int expectedHealth)
		{
			var attacker = new Character();
			var defender = CharacterBuilder.ACharacter().AliveWithHealth(defenderInitialHealth).Build();

			attacker.DealDamage(defender, damage);

			new CharacterAsserts(defender).IsAliveWithHealth(expectedHealth);
		}

		public static IEnumerable<object[]> GetDamageScenarios()
		{
			yield return new object[] { 1000, 1, 999 };
			yield return new object[] { 1000, 200, 800 };
			yield return new object[] { 1000, 999, 1 };
			yield return new object[] { 999, 998, 1 };
			yield return new object[] { 2, 1, 1 };
		}

		[Theory]
		[MemberData(nameof(GetDeathScenarios))]
		public void DefenderDiesAndHealthGoesToZeroWhenDamageHigherThanHealth(List<int> damages)
		{
			var attacker = new Character();
			var defender = new Character();

			foreach (var damage in damages)
			{
				attacker.DealDamage(defender, damage);
			}

			new CharacterAsserts(defender).IsDead();
		}

		public static IEnumerable<object[]> GetDeathScenarios()
		{
			yield return new object[] { new List<int> { 1001 } };
			yield return new object[] { new List<int> { 10, 133, 234, 77, 14, 320, 213 } };
			yield return new object[] { new List<int> { 1100 } };
		}

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

		[Fact]
		public void HealingDoesNotReviveOrIncreaseHealthOfADeadCharacter()
		{
			var attacker = new Character();
			var defender = new Character();
			var healer = new Character();

			attacker.DealDamage(defender, 1100);
			healer.Heal(defender, 300);

			new CharacterAsserts(defender).IsDead();
		}
	}
}
