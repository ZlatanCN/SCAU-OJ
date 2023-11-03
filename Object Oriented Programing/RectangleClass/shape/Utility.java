package shape;

public class Utility {
    public static int compare(Rectangle rect1, Rectangle rect2) {
        if (rect1.getArea() > rect2.getArea()) {
            return 1;
        } else if (rect1.getArea() == rect2.getArea()) {
            return 0;
        } else {
            return -1;
        }
    }

    public static void sort(Rectangle[] rectangles) {
        for (int i = 0; i < rectangles.length; i++) {
            for (int j = i + 1; j < rectangles.length; j++) {
                if (compare(rectangles[i], rectangles[j]) == -1) {
                    Rectangle temp = rectangles[j];
                    rectangles[j] = rectangles[i];
                    rectangles[i] = temp;
                }
            }
        }
    }

    public static Rectangle getMaxRectangle(Rectangle[] rectangles) {
        sort(rectangles);
        return rectangles[0];
    }

    public static void output(Rectangle[] rectangles) {
        System.out.printf("共有%d个矩形对象， 颜色是: %s\n", rectangles.length, Rectangle.getColor());

        for (Rectangle rectangle : rectangles) {
            double w = rectangle.getWidth();
            double h = rectangle.getHeight();
            double a = rectangle.getArea();
            System.out.printf("[%.2f, %.2f] - %.2f\n", w, h, a);
        }
    }
}
