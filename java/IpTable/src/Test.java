
public class Test {

	public static void main(String[] args) {
		IpTable ip=new IpTable();
		IpItem a;
		ip.insert(new IpItem("c4:b3:01:bd:8b:d2","192.168.1.103","xiaoming"));
		ip.insert(new IpItem("c4:b3:01:bd:8b:d1","192.168.1.101","pengjia"));
		a=ip.search("pengjia");
		ip.delete(a);
		ip.insert(new IpItem("c4:b3:01:bd:8b:d3","192.168.1.108","xiaohong"));

		System.out.print(ip.toString());
	}
}
