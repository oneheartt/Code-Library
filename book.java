public class book{

	private String author, title;
	private int pageCount;

	public book(String author, String title, int pageCount){
		this.author = author;
		this.title = title;
		this.pageCount = pageCount;
	}

	public String getAuthor(){
		return this.author;
	}

	public String getName(){
		return this.title;
	}

	public int getPages(){
		return this.pageCount;
	}

	public String toString(){
		return this.author + ", " + this.title + ", " + this.pageCount + " pages";
	}
}