namespace RPGCombatKata.Tests{
	public class NewCharacterTests
	{
		[Fact]
		public void NewCharacterIsAliveAtFullHealthAndAtLevel1()
		{
			var character = CharacterBuilder.ACharacter().Build();

			new CharacterAsserts(character).IsNewAndValid();
		}

	}
}
