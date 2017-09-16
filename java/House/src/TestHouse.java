public class TestHouse {

	public static void main(String[] args) throws Exception{
		House h1=new House(123,89.0);
		House h2=(House)(h1.clone());
		h1.getDate().setDate(23);
		show(h1);
		show(h2);
	}
	static void show(House h) {
		System.out.println("id="+h.getId()+" area="+
				h.getArea()+" "+h.getDate().toString());
	}
}
