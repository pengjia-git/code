import java.util.Date;
public class House implements Cloneable, Comparable<House>{
	private int id;
	private double area;
	private Date whenDate;
	
	public House(int id,double area) {
		this.id=id;
		this.area=area;
		whenDate=new Date();
	}
	
	public int getId() {
		return id;
	}
	
	public double getArea() {
		return area;
	}
	
	public Date getDate() {
		return whenDate;
	}
	
	public int compareTo(House o) {
		if(area < o.getArea())
			return -1;
		else if(area == o.getArea())
			return 0;
		else
			return 1;
	}
	
	public Object clone() throws CloneNotSupportedException{
		House houseClone=(House) super.clone();
		houseClone.whenDate=(Date)houseClone.whenDate.clone();
		return houseClone;
	}
	
}
