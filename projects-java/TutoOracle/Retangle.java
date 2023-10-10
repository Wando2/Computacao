public class Retangle {
    int height = 0;
    int width = 0;
    Point origin;

    // four constructors
    public Retangle() {
        this.origin = new Point(0, 0);
    }

    public Retangle(Point p, int h, int w) {
        this.height = h;
        this.width = w;
        this.origin = p;
    }

    public int area() {
        return height * width;
    }
    
    public static void main(String[] args) {
        Retangle r1 = new Retangle();
        Point origin = new Point(23, 94);
        Retangle r2 = new Retangle(origin, 100, 200);

        System.out.println("Height: " + r1.height);
        System.out.println("Width: r2 " + r2.width);
        System.out.println("Origin: " + r2.origin.x + ", " + r2.origin.y);
        System.out.println("Area: " + r2.area());
        System.out.println("area of reference" + new Retangle(origin, 100, 20).area());
     
    }

}

