package main;

import shape.Rectangle;
import shape.Utility;

import java.util.Random;

public class Main {
    public static void main(String[] args) {
        Random r = new Random();
        Rectangle[] rectangles = new Rectangle[10];
        for (int i = 0; i < rectangles.length; i++) {
            rectangles[i] = new Rectangle(r.nextDouble(0, 100), r.nextDouble(0, 100));
        }

        Utility.output(rectangles);
        Rectangle maxRectangle = Utility.getMaxRectangle(rectangles);
        System.out.printf("最大的矩形是: [%.2f, %.2f] - %.2f\n\n",
                maxRectangle.getWidth(), maxRectangle.getHeight(), maxRectangle.getArea());
        Utility.sort(rectangles);
        Rectangle.setColor("RED");
        System.out.println("降序并修改颜色后:\n");
        Utility.output(rectangles);

    }
}
