
namespace RPGCombatKata.Tests
{
	public class CharacterTestsWithCustomAsserts
	{
		[Fact]
		public void NewCharacterIsAliveAtFullHealthAndAtLevel1()
		{
			new CharacterAsserts(new Character()).IsNewAndValid();
		}

		[Fact]
		public void DefendersHealthDecreasesAfterAnAttackerDealsDamage()
		{
			var attacker = new Character();
			var defender = new Character();

			attacker.DealDamage(defender, 100);

			new CharacterAsserts(defender).HasHealth(900);
		}

		[Fact]
		public void DefenderDiesAndHealthGoesToZeroWhenDamageHigherThanHealth()
		{
			var attacker = new Character();
			var defender = new Character();

			attacker.DealDamage(defender, 1100);

			new CharacterAsserts(defender).IsDead();
		}

		[Fact]
		public void HealingACharacterIncreasesTheirHealth()
		{
			var attacker = new Character();
			var defender = new Character();
			var healer = new Character();
			attacker.DealDamage(defender, 200);

			healer.Heal(defender, 100);

			new CharacterAsserts(defender).HasHealth(900);
		}

		[Fact]
		public void HealingACharacterHasHealthCappedAt1000()
		{
			var attacker = new Character();
			var defender = new Character();
			var healer = new Character();
			attacker.DealDamage(defender, 200);

			healer.Heal(defender, 300);

			new CharacterAsserts(defender).IsAliveAtFullHealth();
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
