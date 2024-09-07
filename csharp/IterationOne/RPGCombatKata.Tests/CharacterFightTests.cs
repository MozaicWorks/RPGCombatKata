namespace RPGCombatKata.Tests{
	public class CharacterFightTests
	{
		public static IEnumerable<object[]> GetDamageScenarios()
		{
			yield return new object[] { 1000, 1, 999 };
			yield return new object[] { 1000, 200, 800 };
			yield return new object[] { 1000, 999, 1 };
			yield return new object[] { 999, 998, 1 };
			yield return new object[] { 2, 1, 1 };
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
	}
}
