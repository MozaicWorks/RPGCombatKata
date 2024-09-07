using Moq;

namespace RPGCombatKata.Tests{

	public class DamageTests
	{
		[Fact]
		public void NormalDamage()
		{
			var diceStub = new Mock<Dice>();
			diceStub.Setup(d => d.Roll()).Returns(10);
			var damageCalculator = new DamageCalculator(diceStub.Object);

			var damageResult = damageCalculator.ComputeDamage();

			var asserts = new DamageAsserts(damageResult);
			asserts.AssertNormalDamageIs(150);
		}

		[Fact]
		public void CriticalHitDamage()
		{
			var diceStub = new Mock<Dice>();
			diceStub.Setup(d => d.Roll()).Returns(20);
			var damageCalculator = new DamageCalculator(diceStub.Object);

			var damageResult = damageCalculator.ComputeDamage();

			var asserts = new DamageAsserts(damageResult);
			asserts.AssertCriticalHit();
		}

		[Fact]
		public void CriticalMissDamage()
		{
			var diceStub = new Mock<Dice>();
			diceStub.Setup(d => d.Roll()).Returns(1);
			var damageCalculator = new DamageCalculator(diceStub.Object);

			var damageResult = damageCalculator.ComputeDamage();

			var asserts = new DamageAsserts(damageResult);
			asserts.AssertCriticalMiss();
		}
	}
}
