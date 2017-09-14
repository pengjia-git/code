
public abstract class GenericGeometric {
	private String color="white";
	private boolean fill=false;
	private java.util.Date createDate;
	
	protected GenericGeometric() {
		createDate= new java.util.Date();
	}
	
	protected GenericGeometric(String color,boolean fill)
	{
		this.color=color;
		this.fill=fill;
		createDate= new java.util.Date();
	}
	
	public String getColor()
	{
		return color;
	}
	
	public void setColor(String color)
	{
		this.color=color;
	}
	
	public boolean isFill()
	{
		return fill;
	}
	
	public void setFill(boolean fill)
	{
		this.fill=fill;
	}
	
	java.util.Date getCreateDate()
	{
		return createDate;
	}
	
	public String toString()
	{
		return " created on:"+" color:"+color+
				" fill:"+fill;
	}
	public abstract double getArea();
}
