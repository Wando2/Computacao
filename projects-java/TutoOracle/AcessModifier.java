public class AcessModifier {
    private int age;
    private String name;
    private int weight;

    public AcessModifier(int age, String name, int weight) {
        this.age = age;
        this.name = name;
        this.weight = weight;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public int getAge() {
        return this.age;
    }
    
    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }

    public int getWeight() {
        return this.weight;
    }

    public void setWeight(int weight) {
        
            this.weight = weight;
    }


    public static void main(String[] args) {
        
        AcessModifier tom = new AcessModifier(10, "Tom", 4);
        System.out.println("Tom's age is " + tom.getAge());

        
    
    } 
}