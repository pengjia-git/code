import java.util.*;

/**
 * <p>
 * Title: ????????
 * </p>
 * <p>
 * Description: ?????????????????????????????????????��
 * </p>
 * <p>
 * Copyright: Copyright (c) 2003
 * </p>
 * <p>
 * Filename: RoleRight.java
 * </p>
 * 
 * @author ???
 * @version 1.0
 */
public class RoleRight {
	private static Hashtable<String,String> rightList = new Hashtable<String,String>();

	/**
	 * <br>
	 * ?????????????????? <br>
	 * ????????? <br>
	 * ?????????
	 */
	public void init() {
		String[] accRoleList = { "admin", "satrap", "manager", "user", "guest" };
		String[] rightCodeList = { "10001", "10011", "10021", "20011", "24011" };
		for (int i = 0; i < accRoleList.length; i++) {
			rightList.put(accRoleList[i], rightCodeList[i]);
		}
	}

	/**
	 * <br>
	 * ????????????????????? <br>
	 * ?????????String accRole ??????? <br>
	 * ?????????String ??????
	 */
	public String getRight(String accRole) {
		if (rightList.containsKey(accRole))
			return (String) rightList.get(accRole);
		else
			return null;
	}

	/**
	 * <br>
	 * ?????????????????????? <br>
	 * ?????????String accRole ??????? <br>
	 * ?????????String rightCode ????????? <br>
	 * ?????????void ?????
	 */
	public void insert(String accRole, String rightCode) {
		rightList.put(accRole, rightCode);
	}

	/**
	 * <br>
	 * ?????????????????? <br>
	 * ?????????String accRole ??????? <br>
	 * ?????????void?????
	 */
	public void delete(String accRole) {
		if (rightList.containsKey(accRole))
			rightList.remove(accRole);
	}

	/**
	 * <br>
	 * ???????????????????? <br>
	 * ?????????String accRole ??????? <br>
	 * ?????????String rightCode ????????? <br>
	 * ?????????void?????
	 */
	public void update(String accRole, String rightCode) {
		// this.delete(accRole);
		this.insert(accRole, rightCode);
	}

	/**
	 * <br>
	 * ??????????????????��??????????? <br>
	 * ??????????? <br>
	 * ???????????
	 */
	public void print() {
		Enumeration RLKey = rightList.keys();
		while (RLKey.hasMoreElements()) {
			String accRole = RLKey.nextElement().toString();
			print(accRole + "=" + this.getRight(accRole));
		}
	}

	/**
	 * <br>
	 * ?????????????????????? <br>
	 * ?????????Object oPara ???????????? <br>
	 * ???????????
	 */
	public void print(Object oPara) {
		System.out.println(oPara);
	}

	/**
	 * <br>
	 * ????????????????? <br>
	 * ????????? <br>
	 * ?????????
	 */
	public static void main(String[] args) {
		RoleRight RR = new RoleRight();
		RR.init();
		RR.print();
		RR.print("___________________________");
		RR.insert("presider", "10110");
		RR.print();
		RR.print("___________________________");
		RR.update("presider", "10100");
		RR.print();
		RR.print("___________________________");
		RR.delete("presider");
		RR.print();
	}
}
// end:)~