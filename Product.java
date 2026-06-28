public class Product{
	
	private String name, location;
	private int weight;

	public Product(String name){
		this(name, "shelf", 1);
	}

	public Product(String name, String location){
		this(name, location, 1);
	}

	public Product(String name, int weight){
		this(name, "shelf", weight);
	}

	public Product(String name, String location, int weight){
		this.name = name;
		this.location = location;
		this.weight = weight;
	}

	@Override
	public String toString(){
		return name + " (" + weight + " kg) can be found from the" + location;
	}
}	