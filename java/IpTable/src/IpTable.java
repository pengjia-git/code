import java.util.*;

public class IpTable {
	private Hashtable<String,Integer> hashMac=new Hashtable<String,Integer>();
	private Hashtable<String,Integer> hashIp=new Hashtable<String,Integer>();
	private Hashtable<String,Integer> hashName=new Hashtable<String,Integer>();
	private ArrayList<IpItem> ipArray=new ArrayList<IpItem>();
	
	public boolean insert(IpItem ip) 
	{
		int size=ipArray.size();
		ipArray.add(ip);
		hashMac.put(ip.mac,size);
		hashIp.put(ip.ip,size);
		hashName.put(ip.name,size);
		return true;
	}
	
	public boolean delete(IpItem ip)
	{
		boolean isTure;
		isTure=ipArray.remove(ip);
		if(isTure == false)
			return false;
		
		int size=ipArray.size();
		hashMac.clear();
		hashIp.clear();
		hashName.clear();
		for(int i=0;i<size;i++) {
			hashMac.put(ipArray.get(i).mac,i);
			hashIp.put(ipArray.get(i).ip,i);
			hashName.put(ipArray.get(i).name,i);
		}
		return true;
	}
	
	public void update(IpItem ip)
	{
		if(delete(ip))
			insert(ip);
	}
	
	public IpItem search(String a)
	{
		int index=-1;
		if(hashMac.containsKey(a))
			index=hashMac.get(a);
		else if(hashIp.containsKey(a))
			index=hashIp.get(a);
		else if(hashName.containsKey(a))
			index=hashName.get(a);
		if(index == -1)
			return null;
		
		return ipArray.get(index);
	}
	
	public String toString()
	{
		String val=new String();
		int len=ipArray.size();
		for(int i=0;i<len;i++)
			val+=ipArray.get(i).toString()+"\n";
		return val;
	}
}

class IpItem{
	public String mac;
	public String ip;
	public String name;
	public IpItem(String mac,String ip,String name) {
		this.mac=mac;
		this.ip=ip;
		this.name=name;
	}
	public String toString()
	{
		return "mac--"+mac+" ip--"+ip+" name--"+name;
	}
}