public class QuadraticEquation {
    private double a;
    private double b;
    private double c;

    private final double DELTA;

    public QuadraticEquation(double n1, double n2, double n3) {
        a = n1;
        b = n2;
        c = n3;
        DELTA = Math.pow(b, 2) - 4 * a * c;
    }

    public double getRoot1() {
        double div = -b + Math.sqrt(DELTA);
        return div / (2 * a);
    }

    public double getRoot2() {
        double div = -b - Math.sqrt(DELTA);
        return div / (2 * a);
    }

    public int howManySolidRoots() {
        if (DELTA < 0) {
            return 0;
        } else if (DELTA == 0) {
            return 1;
        } else {
            return 2;
        }
    }
}
