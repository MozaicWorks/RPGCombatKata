using System;
using System.Linq;
using RPGCombatKata;

public class Program
{
	public static void Main()
	{
		var damageCalculator = new DamageCalculator(new Dice20Faces());
		Character arthur = new Character();
		Character mordred = new Character();
		Character merlin = new Character();
		bool isHealing = true;

		while (arthur.IsAlive() && mordred.IsAlive())
		{
			var arthurDamage = damageCalculator.ComputeDamage();
			arthur.DealDamage(mordred, arthurDamage.damage);
			if (arthurDamage.isCriticalHit)
			{
				Console.WriteLine("Arthur did a critical hit!");
			}
			if (arthurDamage.isCriticalMiss)
			{
				Console.WriteLine("Arthur did a critical miss and won't heal!");
				isHealing = false;
			}
			Console.WriteLine($"Arthur dealt {arthurDamage.damage} damage to Mordred and Mordred has {mordred.Health()} health left");
			if (!mordred.IsAlive())
			{
				Console.WriteLine("Mordred is dead!");
				break;
			}

			var mordredDamage = damageCalculator.ComputeDamage();
			mordred.DealDamage(arthur, mordredDamage.damage);
			if (mordredDamage.isCriticalHit)
			{
				Console.WriteLine("Mordred did a critical hit!");
			}
			Console.WriteLine($"Mordred dealt {mordredDamage.damage} damage to Arthur and Arthur has {arthur.Health()} health left");
			if (!arthur.IsAlive())
			{
				Console.WriteLine("Arthur is dead!");
				break;
			}

			if (isHealing)
			{
				var merlinHealing = damageCalculator.ComputeDamage();
				merlin.Heal(arthur, merlinHealing.damage);
				Console.WriteLine($"Merlin healed Arthur of {merlinHealing.damage} and Arthur has {arthur.Health()} health left");
			}
			else
			{
				Console.WriteLine("Merlin can't heal Arthur right now");
				isHealing = true;
			}
		}
	}
}
