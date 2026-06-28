public class Pet{
	private String name, breed;

	public Pet(String name, String breed){
		this.name = name; this.breed = breed;
	}

	public String getName(){
		return this.name;
	}

	public String getBreed(){
		return this.breed;
	}
}