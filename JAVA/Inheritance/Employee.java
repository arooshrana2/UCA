public class Employee{
	int eno;
	String ename;
	Address a;
	Employee( int eno, String ename, Address a ){
		this.eno = eno;
		this.ename = ename;
		this.a = a;
	}
	void display(){
		System.out.println(this.eno+" "+this.ename+" "+this.a.hno+" "
		+this.a.street+" "+this.a.town+" "+this.a.district);
	}
	public static void main(String[] args){
		Address add = new Address(42,"Yog Vihar", "Baltana", "Mohali");
		Employee emp = new Employee(114, "Aroosh", add);
		emp.display();
	}
	
}
class Address{
	int hno;
	String street;
	String town;
	String district;
	Address(int hno, String street, String town, String district){
		this.hno = hno;
		this.street = street;
		this.town = town;
		this.district = district;
	}
}
