def main():
    print("Done")

if __name__ == "__main__":
    main()

from dataclasses import dataclass
@dataclass
class Character:
    health = 1000
    level = 1
    alive = True
