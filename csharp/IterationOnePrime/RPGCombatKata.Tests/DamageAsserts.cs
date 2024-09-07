using Xunit;

namespace RPGCombatKata.Tests
{
	public class DamageAsserts
	{
		private readonly DamageResult result;

		public DamageAsserts(DamageResult result)
		{
			this.result = result;
		}

		public void AssertCriticalHit()
		{
			Assert.Equal(600, result.damage);
			Assert.True(result.isCriticalHit);
			Assert.False(result.isCriticalMiss);
		}

		public void AssertCriticalMiss()
		{
			Assert.Equal(0, result.damage);
			Assert.False(result.isCriticalHit);
			Assert.True(result.isCriticalMiss);
		}

		public void AssertNormalDamageIs(int damage)
		{
			Assert.Equal(damage, result.damage);
			Assert.False(result.isCriticalHit);
			Assert.False(result.isCriticalMiss);
		}
	}
}
