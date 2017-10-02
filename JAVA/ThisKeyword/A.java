public class A{
	A(){
		System.out.println("Constructor");
		this(11);
	}
	A(int x){
		System.out.println(x);
	}
	public static void main(String args[]){
		A a = new A();
	}
}
