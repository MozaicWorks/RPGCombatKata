from dataclasses import dataclass

@dataclass
class Character:
    health = 1000
    level = 1
    alive = True

    def takeDamage(self, damage):
        self.health = 0 if damage > self.health else self.health - damage
        self.alive = self.health > 0
