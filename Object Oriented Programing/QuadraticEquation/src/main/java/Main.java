import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        System.out.print("请输入一元二次方程的 3 个系数: ");
        Scanner sc = new Scanner(System.in);
        double a = sc.nextDouble();
        double b = sc.nextDouble();
        double c = sc.nextDouble();
        QuadraticEquation equation = new QuadraticEquation(a, b, c);

        int numOfSolidRoots = equation.howManySolidRoots();
        if (numOfSolidRoots == 0) {
            System.out.print("方程没有实根");
        } else if (numOfSolidRoots == 1) {
            System.out.printf("方程有2个相等的实根，是：%.2f", equation.getRoot1());
        } else {
            System.out.printf("方程有2个不等的实根，是：%.2f 和 %.2f", equation.getRoot1(), equation.getRoot2());
        }
    }
}
