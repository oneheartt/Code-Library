public class Cube{

	private int edgeLength;

	public Cube(int edgeLength){
		this.edgeLength = edgeLength;
	}

	public int volume(){
		int x = this.edgeLength;
		return x * x * x;
	}

	public String toString(){
		return "the length of the edge is " + this.edgeLength + " and the volume " + volume();
	}
}