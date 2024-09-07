namespace RPGCombatKata.Tests{
	public class CharacterDeathTests
	{
		public static IEnumerable<object[]> GetDeathScenarios()
		{
			yield return new object[] { new List<int> { 1001 } };
			yield return new object[] { new List<int> { 10, 133, 234, 77, 14, 320, 213 } };
			yield return new object[] { new List<int> { 1100 } };
		}

		[Theory]
		[MemberData(nameof(GetDeathScenarios))]
		public void DefenderDiesAndHealthGoesToZeroWhenDamageHigherThanHealth(List<int> damages)
		{
			var attacker = new Character();
			var defender = new Character();

			RepeatDamage(attacker, defender, damages);

			new CharacterAsserts(defender).IsDead();
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

		private void RepeatDamage(Character attacker, Character defender, List<int> damages)
		{
			foreach (var damage in damages)
			{
				attacker.DealDamage(defender, damage);
			}
		}
	}
}
