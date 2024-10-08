from dataclasses import dataclass

@dataclass
class BoundedInt:
    min_value: int
    max_value: int
    value: int

    def __max__(self):
        return BoundedInt(self.min_value, self.max_value, self.max_value)

    def __min__(self):
        return BoundedInt(self.min_value, self.max_value, self.min_value)

    def __add__(self, other: int):
        isMax = (self.value + other) > self.max_value
        return self.__max__() if isMax else self.__doAdd__(other)

    def __doAdd__(self, other:int):
        return BoundedInt(self.min_value, self.max_value, self.value + other)

    def __sub__(self, other: int):
        isMin = (self.value - other) < self.min_value
        return self.__min__() if isMin else self.__doSub__(other)

    def __doSub__(self, other: int):
        return BoundedInt(self.min_value, self.max_value, self.value - other)

    def __eq__(self, other:int):
        return self.value == other

    def __lt__(self, other: int):
        return self.value < other

    def __gt__(self, other: int):
        return self.value > other

@dataclass
class Character:
    MAX_HEALTH = 1000
    health = BoundedInt(0, MAX_HEALTH, MAX_HEALTH)
    level = 1

    def isAlive(self):
        return self.health > 0

    def takeDamage(self, damage):
        self.health -= damage

    def heal(self, healing):
        if self.isAlive():
            self.health += healing

    def dealDamageTo(self, character, damage):
        if character is self:
            return

        if (self.level - character.level) >=5:
            damage = 1.5*damage

        if(character.level - self.level) >= 5:
            damage = damage/2

        character.takeDamage(damage)
