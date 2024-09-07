using System.Collections.Generic;

namespace RPGCombatKata.Tests
{
	public class CharacterTestsDataDriven
	{
		[Fact]
		public void NewCharacterIsAliveAtFullHealthAndAtLevel1()
		{
			new CharacterAsserts(new Character()).IsNewAndValid();
		}

		[Theory]
		[InlineData(0, 1000)]
		[InlineData(100, 900)]
		[InlineData(200, 800)]
		[InlineData(700, 300)]
		[InlineData(1, 999)]
		[InlineData(999, 1)]
		public void DefendersHealthDecreasesAfterAnAttackerDealsDamage(int damage, int expectedHealth)
		{
			var attacker = new Character();
			var defender = new Character();

			attacker.DealDamage(defender, damage);

			new CharacterAsserts(defender).IsAliveWithHealth(expectedHealth);
		}

		public static IEnumerable<object[]> GetDamageScenarios()
		{
			yield return new object[] { new List<int> { 1001 } };
			yield return new object[] { new List<int> { 10, 133, 234, 77, 14, 320, 213 } };
			yield return new object[] { new List<int> { 1100 } };
		}

		[Theory]
		[MemberData(nameof(GetDamageScenarios))]
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

		[Theory]
		[InlineData("damage more than healing 100", 200, 100, 900)]
		[InlineData("damage equal to healing", 500, 500, 1000)]
		[InlineData("damage lower than healing", 500, 600, 1000)]
		public void HealingACharacterIncreasesTheirHealth(string situation, int damage, int heal, int expectedHealth)
		{
			var attacker = new Character();
			var defender = new Character();
			var healer = new Character();
			attacker.DealDamage(defender, damage);

			healer.Heal(defender, heal);

			new CharacterAsserts(defender, situation).HasHealth(expectedHealth);
		}

		[Theory]
		[InlineData("damage kills, attempt healing", 1100, 300)]
		[InlineData("damage kills, attempt healing", 1001, 1)]
		[InlineData("damage kills, attempt healing", 1001, 2000)]
		public void HealingDoesNotReviveOrIncreaseHealthOfADeadCharacter(string situation, int damage, int healing)
		{
			var attacker = new Character();
			var defender = new Character();
			var healer = new Character();
			attacker.DealDamage(defender, damage);

			healer.Heal(defender, healing);

			new CharacterAsserts(defender, situation).IsDead();
		}
	}
}
