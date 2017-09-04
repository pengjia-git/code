
public class DefaultValueOfDataField {
	public static void main(String[] args) {
		String edsen;
		Student jack=new Student();
		System.out.println(jack.name);
		System.out.println(jack.age);
		System.out.println(jack.isScienceMajor);
		System.out.println(jack.gender);
		/*此处代码会报错，但是jack.name就不会报错。jack.name会被系统初始化为null*/
		//System.out.println(edsen);
	}

}

class Student{
	String name;
	int age;
	boolean isScienceMajor;
	char gender;
	Student(){
		System.out.println("construction");
		age=3;
		gender='s';
	}
}