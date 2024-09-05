using System;
using System.Linq;
using RPGCombatKata;

public class Program
{
    private static Random random = new Random();
    private static bool isCriticalHit = false;
    private static bool isCriticalMiss = false;

    public static int D20()
    {
        return random.Next(1, 21);
    }

    public static int Damage()
    {
        int damage;
        int roll = D20();
        if (roll == 1)
        {
            isCriticalMiss = true;
            isCriticalHit = false;
            damage = 0;
        }
        else if (roll == 20)
        {
            isCriticalMiss = false;
            isCriticalHit = true;
            damage = 30 * roll;
        }
        else
        {
            isCriticalMiss = false;
            isCriticalHit = false;
            damage = 15 * roll;
        }
        return damage;
    }

    public static void Main()
    {
        Character arthur = new Character();
        Character mordred = new Character();
        Character merlin = new Character();
        bool isHealing = true;

        while (arthur.IsAlive() && mordred.IsAlive())
        {
            int arthurDamage = Damage();
            arthur.DealDamage(mordred, arthurDamage);
            if (isCriticalHit)
            {
                Console.WriteLine("Arthur did a critical hit!");
            }
            if (isCriticalMiss)
            {
                Console.WriteLine("Arthur did a critical miss and won't heal!");
                isHealing = false;
            }
            Console.WriteLine($"Arthur dealt {arthurDamage} damage to Mordred and Mordred has {mordred.Health()} health left");
            if (!mordred.IsAlive())
            {
                Console.WriteLine("Mordred is dead!");
                break;
            }

            int mordredDamage = Damage();
            mordred.DealDamage(arthur, mordredDamage);
            if (isCriticalHit)
            {
                Console.WriteLine("Mordred did a critical hit!");
            }
            Console.WriteLine($"Mordred dealt {mordredDamage} damage to Arthur and Arthur has {arthur.Health()} health left");
            if (!arthur.IsAlive())
            {
                Console.WriteLine("Arthur is dead!");
                break;
            }

            if (isHealing)
            {
                int merlinHealing = Damage();
                merlin.Heal(arthur, merlinHealing);
                Console.WriteLine($"Merlin healed Arthur of {merlinHealing} and Arthur has {arthur.Health()} health left");
            }
            else
            {
                Console.WriteLine("Merlin can't heal Arthur right now");
                isHealing = true;
            }
        }
    }
}
