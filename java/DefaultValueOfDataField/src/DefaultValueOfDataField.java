
public class DefaultValueOfDataField {
	public static void main(String[] args) {
		String edsen;
		Student jack=new Student();
		System.out.println(jack.name);
		System.out.println(jack.age);
		System.out.println(jack.isScienceMajor);
		System.out.println(jack.gender);
		/*�˴�����ᱨ������jack.name�Ͳ��ᱨ��jack.name�ᱻϵͳ��ʼ��Ϊnull*/
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