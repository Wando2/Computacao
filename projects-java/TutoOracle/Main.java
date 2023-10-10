interface catInterface {
    void changeAge(int age);

    void changeName(String name);

    void messageToCat(String message);

    void color(String color);

    void weight(int weight);
}


class cat implements catInterface {

    int age;
    String name;
    String color;
    int weight;
    String message;

    public void changeAge(int age) {
        this.age = age;
    }

    public void changeName(String name) {
        this.name = name;
    }

    public void messageToCat(String message) {
        this.message = message;
    }

    public void color(String color) {
        this.color = color;
    }

    public void weight(int weight) {
        this.weight = weight;
    }

    public void meow() {
        System.out.println("Meow!");
    }

   
}

    

public class Main {
    public static void main(String[] args) {

        cat tom = new cat();
        tom.changeAge(10);
        tom.changeName("Tom");
        tom.color("Grey and Black");
        tom.weight(4);
        tom.messageToCat("love you dear cat");

        System.out.println("Tom's age is " + tom.age);
        System.out.println("Tom's name is " + tom.name);
        System.out.println("Tom's color is " + tom.color);
        System.out.println("Tom's weight is " + tom.weight);
        System.out.println("Tom's message is " + tom.message);
        tom.meow();
    }
}

class motorbike {
    int speed;
    int gear;

    void changeGear(int gear) {
        this.gear = gear;
    }

    void speedUp(int speed) {
        this.speed = speed;
    }

    void applyBrakes(int decrement) {
        speed -= decrement;
    }

    void printStates() {
        System.out.println("speed: " + speed + " gear: " + gear);
    }
}

