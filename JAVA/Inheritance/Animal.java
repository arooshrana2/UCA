class Dog extends Animal{
	void sound(){
		System.out.println("Barking...");
	}
}
class Cat extends Animal{
	Cat(){
		System.out.println("I am cat..");
	}
	void sound(){
		System.out.println("Meowing...");
	}
}

public class Animal{
	Animal(){
		System.out.println("I am an Animal..");
	}
	void eat(){
		System.out.println("I eat food..!");
	}
	public static void main(String[]args){
		Cat c = new Cat();
		Dog d = new Dog();
		c.sound();
		c.eat();
		d.sound();
		d.eat();
	}
}
