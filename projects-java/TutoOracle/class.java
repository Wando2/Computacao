class dog {

    int age;
    String name;
    int weight;
    int height;

    public void bark() {
        System.out.println("Woof!");
    }


    void age(int age) {
        this.age = age;
    }

    void name(String name) {
        this.name = name;
    }

    void weight(int weight) {
        this.weight = weight;
    }

    void height(int height) {
        this.height = height;
    }

}

class liveDog {
    public static void main(String[] args) {
        dog Dogao = new dog();

        Dogao.name("Dogao");
        Dogao.weight(10);
        Dogao.height(20);


        System.out.println("Dogao's age is " + Dogao.age);
        Dogao.bark();


    }
}


